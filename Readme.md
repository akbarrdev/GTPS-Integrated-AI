# NevoAI

NevoAI is a C++ library that enables seamless AI integration into GTPS (Growtopia Private Server) with efficiency and ease.

[![Buy API Key](https://img.shields.io/badge/Buy%20API%20Key-WhatsApp-25D366?style=for-the-badge&logo=whatsapp&logoColor=white)](https://wa.me/6282370784874)
[![View API Pricing](https://img.shields.io/badge/View%20API%20Pricing-GitHub-blue?style=for-the-badge&logo=github)](https://github.com/akbarrdev/GTPS-Integrated-AI/blob/main/API_pricelist.md)
## About

NevoAI leverages an external API to provide quick and accurate AI responses. The library is designed to work asynchronously, ensuring optimal game server performance without sacrificing responsiveness.

## Technologies

- libcurl
- nlohmann/json
- Multithreading
- HTTPS API

## Key Features

- Seamless AI integration for GTPS
- Asynchronous operations for optimal performance
- Robust error handling
- Thread-safe packet sending

## How It Works

1. AI requests are sent to an external API asynchronously
2. Responses are processed in a separate thread
3. Callbacks are invoked with AI results
4. Game packets are sent safely using a mutex

## Installation

1. Move `NevoAI.h` and `libcurl.lib` to your source folder (alongside `Source.cpp`)
2. Extract `curl.zip`, then move the extracted folder into the **include** folder (within your source folder)
3. Add the following include statement at the top of your `World.h` file, below the `Packet.h` include:
```cpp
// Add this at the top of your World.h file
// below the #include "Packet.h"
#include "NevoAI.h"
```
4. Ensure you fill in the `APIKEY` in `NevoAI.h` with a valid API key

## Usage

To use NevoAI, add the necessary code to your command handling function in `World.h`. Refer to the example implementation within the `World.h` file for more details on how to integrate NevoAI into your GTPS project.

NevoAI is designed to work asynchronously, ensuring smooth gameplay while waiting for AI responses.

## License

[MIT License](https://opensource.org/licenses/MIT)

## Redistribution

This library is free to be included and resold as part of GTPS source code packages without the need for attribution. GTPS source sellers are permitted to incorporate NevoAI into their products without providing credit to the original authors.

## Contact

For questions or support, contact us on [WhatsApp](https://wa.me/6282370784874)