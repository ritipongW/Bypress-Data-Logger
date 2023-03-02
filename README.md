# Bypress-Data-Logger
ESP32 connected to RTC Module and Micro SD Card
- Hardwares
  - ESP32 Wroom (30 pins or 38 pins)
  - RTC Module DS3231 (or DS1302)
  - Micro SD Card Mudule

SPI for Micro SD Card can connected both Hard SPI and Soft SPI (choose the whcich one)

| SD Card Pins  |   Hard SPI    |   SOft SPI   |
| ------------- | ------------- | -------------|
| SS/CS  | GPIO5  | Content Cell |
| SCK  | GPIS18  | Content Cell |
| MISO | GPIS19 | Content Cell |
| MOSI | GPIS23  | Content Cell |
