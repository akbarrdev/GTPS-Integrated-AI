#pragma once
#ifndef NEVO_AI_H
#define NEVO_AI_H

#include <string>
#include <future>
#include <functional>
#include <curl/curl.h>
#include <sstream>
#include <iomanip>
#include <nlohmann/json.hpp>
#include <iostream>
#include <thread>
#include <mutex>

using json = nlohmann::json;
std::string APIKEY = ""; // isi apikeymu

class NevoAI
{
private:
    static std::mutex packetMutex;
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *output)
    {
        size_t total_size = size * nmemb;
        output->append((char *)contents, total_size);
        return total_size;
    }

    static void PerformRequest(const std::string &url, std::function<void(const std::string &)> callback)
    {
        CURL *curl = curl_easy_init();
        std::string response;
        if (curl)
        {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
            curl_easy_setopt(curl, CURLOPT_USERAGENT, "NevoAI Client/1.0");
            CURLcode res = curl_easy_perform(curl);
            if (res != CURLE_OK)
            {
                callback("Error: " + std::string(curl_easy_strerror(res)));
                curl_easy_cleanup(curl);
                return;
            }
            curl_easy_cleanup(curl);
            try
            {
                json j = json::parse(response);
                if (j.contains("status") && j["status"].is_boolean() && j["status"].get<bool>())
                {
                    if (j.contains("data") && j["data"].is_object() && j["data"].contains("response"))
                    {
                        callback(j["data"]["response"].get<std::string>());
                        return;
                    }
                }
                std::cout << "Unexpected JSON structure: " << j.dump() << std::endl;
                callback("Oops! AI mengalami kesalahan teknis. Struktur respons tidak sesuai. Tolong segera laporkan ke Owner!");
            }
            catch (const nlohmann::json::parse_error &e)
            {
                std::cout << "Error parsing JSON: " << e.what() << std::endl;
                callback("Oops! AI mengalami kesalahan teknis. Gagal parsing JSON. Tolong segera laporkan ke Owner!");
            }
        }
        else
        {
            callback("Error: Could not initialize CURL");
        }
    }

    static std::string UrlEncode(const std::string &value)
    {
        std::ostringstream escaped;
        escaped.fill('0');
        escaped << std::hex;
        for (char c : value)
        {
            if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~')
                escaped << c;
            else
            {
                escaped << std::uppercase;
                escaped << '%' << std::setw(2) << int((unsigned char)c);
                escaped << std::nouppercase;
            }
        }
        return escaped.str();
    }

public:
    static void SendPacketSafe(ENetPeer *peer, const std::string &type, const std::string &data)
    {
        std::lock_guard<std::mutex> lock(packetMutex);
        if (type == "OnDialogRequest")
        {
            gamepacket_t packet;
            packet.Insert("OnDialogRequest");
            packet.Insert(data);
            packet.CreatePacket(peer);
        }
        else if (type == "OnConsoleMessage")
        {
            gamepacket_t packet;
            packet.Insert("OnConsoleMessage");
            packet.Insert(data);
            packet.CreatePacket(peer);
        }
        else if (type == "OnTextOverlay")
        {
            gamepacket_t packet;
            packet.Insert("OnTextOverlay");
            packet.Insert(data);
            packet.CreatePacket(peer);
        }
        // enet_peer_send(peer, 0, Variant{type}.push(data).pack());
    }
    static void ask(const std::string &playerSpecialID, const std::string &playerName, const std::string &ask,
                    std::function<void(const std::string &, const std::string &)> callback)
    {
        std::string encodedPlayerName = UrlEncode(playerName);
        std::string encodedAsk = UrlEncode(ask);
        std::string url = "https://api.akk.bar/ai-gtps?apikey=" + APIKEY + "&playerSpecialID=" +
                          playerSpecialID + "&playerName=" +
                          encodedPlayerName + "&ask=" + encodedAsk;

        std::thread([url, ask, callback]()
                    { PerformRequest(url, [ask, callback](const std::string &result)
                                     { callback(ask, result); }); })
            .detach();
    }
};
std::mutex NevoAI::packetMutex;
#endif // NEVO_AI_H
