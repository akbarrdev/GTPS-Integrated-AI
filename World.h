// Letak di bawah Packet.h
#include "NevoAI.h"

// letak di void SendCMD()
//
else if (command.starts_with("/ai "))
    {
        try
        {
            string name = pInfo(peer)->tankIDName;
            string RID = pInfo(peer)->rid;
            string question = cmd.substr(4, cmd.length() - 4).c_str();
            cout << "Question: " << question << endl;

            NevoAI::ask(RID, name, question, [peer](const std::string &ask, const std::string &result)
                        {
    			DialogBuilder ai;
    			ai.add_label_icon(true, 12272, "`6Nevo AI")
    				.add_spacer(false)
    				.add_textbox("`9Your question:")
    				.add_smalltext(ask)
    				.add_spacer(false)
    				.add_textbox("`9Nevo AI:")
    				.add_smalltext(result)
    				.add_spacer(false)
    				.end_dialog("", "Oke", "").add_quick_exit();

    			NevoAI::SendPacketSafe(peer, "OnDialogRequest", ai.to_string()); });

            NevoAI::SendPacketSafe(peer, "OnConsoleMessage", "`9AI sedang memproses pertanyaan Anda. Harap tunggu...");
        }
        catch (const std::exception &err)
        {
            cout << err.what() << endl;
            NevoAI::SendPacketSafe(peer, "OnConsoleMessage", "`4Terjadi kesalahan saat memproses permintaan AI.");
        }
    }