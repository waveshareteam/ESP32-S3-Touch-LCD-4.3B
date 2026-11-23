# ESP32-S3-Touch-LCD-4.3B 综合固件

[English](README.md)

综合固件用于运行 LVGL 演示。请按型号、屏幕类型和分辨率选择。

| 适用型号 | 屏幕类型 | 分辨率 | 固件 |
| --- | --- | --- | --- |
| ESP32-S3-Touch-LCD-4.3B | 触摸 | 800 × 480 | [`ESP32-S3-Touch-LCD-4.3B_FactoryOnly_20260225.bin`](ESP32-S3-Touch-LCD-4.3B_FactoryOnly_20260225.bin) |

上表的固件适用于标准款 ESP32-S3-Touch-LCD-4.3B 和带外壳的 ESP32-S3-Touch-LCD-4.3B-BOX。在固件中心为这两款选择 ESP32-S3-Touch-LCD-4.3B。

使用 USB 数据线连接开发板，在本目录打开终端，使用 esptool 5 或更新版本，并将 `PORT` 替换为设备串口。

整片擦除 Flash 会清除固件、设置和用户数据，请提前备份。

```sh
python -m esptool --chip esp32s3 --port PORT erase-flash
python -m esptool --chip esp32s3 --port PORT write-flash 0x0 ESP32-S3-Touch-LCD-4.3B_FactoryOnly_20260225.bin
```

烧录完成后复位开发板，确认显示和对应功能正常。

原有预编译固件见 [`examples/`](examples/)。
