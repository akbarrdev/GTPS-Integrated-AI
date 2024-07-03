# NevoAI

NevoAI adalah library C++ yang memungkinkan integrasi AI ke dalam GTPS (Growtopia Private Server) dengan mudah dan efisien.

[![Beli API Key](https://img.shields.io/badge/Beli%20API%20Key-WhatsApp-25D366?style=for-the-badge&logo=whatsapp&logoColor=white)](https://wa.me/6282370784874)

## Tentang

NevoAI memanfaatkan API eksternal untuk memberikan respons AI yang cepat dan akurat. Library ini dirancang untuk bekerja secara asinkron, memastikan performa optimal server game tanpa mengorbankan responsivitas.

## Teknologi

- libcurl
- nlohmann/json
- Multithreading
- HTTPS API

## Fitur Utama

- Integrasi AI yang mulus untuk GTPS
- Operasi asinkron untuk performa optimal
- Penanganan kesalahan yang kuat
- Pengiriman paket yang aman antar thread

## Cara Kerja

1. Permintaan AI dikirim ke API eksternal secara asinkron
2. Respons diproses di thread terpisah
3. Callback dipanggil dengan hasil AI
4. Paket game dikirim dengan aman menggunakan mutex

## Instalasi

1. Pindahkan `NevoAI.h` dan `libcurl.lib` ke folder source Anda (bersama `Source.cpp`)
2. Ekstrak `curl.zip`, lalu pindahkan folder hasil ekstrak ke dalam folder `include` (yang ada di folder source Anda)
3. Tambahkan pernyataan include berikut di bagian atas file `World.h` Anda, di bawah include `Packet.h`:
```cpp
// Tambahkan ini di bagian atas file World.h Anda
// di bawah #include "Packet.h"
#include "NevoAI.h"
```


4. Pastikan Anda mengisi `APIKEY` di `NevoAI.h` dengan API key yang valid

## Penggunaan

Untuk menggunakan NevoAI, tambahkan kode yang diperlukan ke fungsi penanganan perintah Anda di `World.h`. Lihat contoh implementasi di dalam file `World.h` untuk detail lebih lanjut tentang cara mengintegrasikan NevoAI ke dalam proyek GTPS Anda.

NevoAI dirancang untuk bekerja secara asinkron, memastikan gameplay yang lancar saat menunggu respons AI.

## Lisensi

[Lisensi MIT](https://opensource.org/licenses/MIT)

## Redistribusi

Library ini bebas untuk disertakan dan dijual kembali sebagai bagian dari paket kode sumber GTPS tanpa perlu atribusi. Penjual kode sumber GTPS diizinkan untuk memasukkan NevoAI ke dalam produk mereka tanpa memberikan kredit kepada penulis asli.

## Kontak

Untuk pertanyaan atau dukungan, hubungi saya di [WhatsApp](https://wa.me/6282370784874)