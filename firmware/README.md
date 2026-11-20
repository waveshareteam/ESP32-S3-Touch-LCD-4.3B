# ESP32-S3-Touch-LCD-4.3B Integrated Firmware

[简体中文](README_ZH.md)

Choose the LVGL demo image for your model, screen type, and resolution.

| Board | Screen type | Resolution | Firmware |
| --- | --- | --- | --- |
| ESP32-S3-Touch-LCD-4.3B | Touch | 800 × 480 | [`ESP32-S3-Touch-LCD-4.3B_FactoryOnly_20260225.bin`](ESP32-S3-Touch-LCD-4.3B_FactoryOnly_20260225.bin) |

Connect the board with a USB data cable. Open a terminal in this directory, use esptool 5 or later, and replace `PORT` with the board's serial port.

Back up any data you need before erasing the entire flash, which clears firmware, settings, and user data.

```sh
python -m esptool --chip esp32s3 --port PORT erase-flash
python -m esptool --chip esp32s3 --port PORT write-flash 0x0 ESP32-S3-Touch-LCD-4.3B_FactoryOnly_20260225.bin
```

Reset the board after flashing and check that the display and demo functions work.

The original prebuilt binaries are in [`examples/`](examples/).
