# Bypress-Data-Logger
ESP32 connected to RTC Module and Micro SD Card
- Hardwares
  - ESP32 Wroom (30 pins or 38 pins)
  - RTC Module DS3231 (or DS1302)
  - Micro SD Card Mudule

SPI for Micro SD Card can connected both Hard SPI and Soft SPI (choose the whcich one)

| SD Card Pins  |   VSPI     |   Define SPI   | HSPI    |
| ------------- | ------------- | -------------| -------------|
| SS/CS  | GPIO5  | GPIO26 | GPIO15 |
| SCK  | GPIO18  |GPIO27 | GPIO14 |
| MISO | GPIO19 | GPIO13 | GPIO12 |
| MOSI | GPIO23  |  GPIO14 | GPIO13 |

RTC library provide by Makuna
Download from https://github.com/Makuna/Rtc.git or libraies manager
