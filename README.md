# Bypress-Data-Logger
ESP32 connected to RTC Module and Micro SD Card
- Hardwares
  - ESP32 Wroom (30 pins or 38 pins)
  - RTC Module DS3231 (or DS1302)
  - Micro SD Card Mudule

SPI for Micro SD Card can connected both Hard SPI and Soft SPI (choose the whcich one)

| SD Card Pins  |   Hard SPI    |   Soft SPI   |
| ------------- | ------------- | -------------|
| SS/CS  | GPIO5  | GPI26 |
| SCK  | GPIS18  |GPI27 |
| MISO | GPIS19 | GPI13 |
| MOSI | GPIS23  |  GPI14 |

RTC library provide by Makuna
Download from https://github.com/Makuna/Rtc.git or libraies manager
