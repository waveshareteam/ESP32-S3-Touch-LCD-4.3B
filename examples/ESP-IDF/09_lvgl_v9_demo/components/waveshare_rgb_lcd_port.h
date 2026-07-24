#ifndef _RGB_LCD_H_
#define _RGB_LCD_H_

#include "esp_log.h"
#include "esp_heap_caps.h"
#include "driver/gpio.h"
#include "driver/i2c.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_rgb.h"
#include "esp_lcd_touch.h"
#include "esp_lcd_touch_gt911.h"


#define I2C_MASTER_SCL_IO           9       /*!< GPIO number used for I2C master clock */
#define I2C_MASTER_SDA_IO           8       /*!< GPIO number used for I2C master data  */
#define I2C_MASTER_NUM              0       /*!< I2C master i2c port number, the number of i2c peripheral interfaces available will depend on the chip */
#define I2C_MASTER_FREQ_HZ          400000                     /*!< I2C master clock frequency */
#define I2C_MASTER_TX_BUF_DISABLE   0                          /*!< I2C master doesn't need buffer */
#define I2C_MASTER_RX_BUF_DISABLE   0                          /*!< I2C master doesn't need buffer */
#define I2C_MASTER_TIMEOUT_MS       1000

#define GPIO_INPUT_IO_4    4
#define GPIO_INPUT_PIN_SEL  1ULL<<GPIO_INPUT_IO_4
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////// Please update the following configuration according to your LCD spec //////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define ESP_PANEL_USE_1024_600_LCD           (0)     // 0: 800x480, 1: 1024x600
#define CONFIG_EXAMPLE_LCD_TOUCH_CONTROLLER_GT911 1  // 1 initiates the touch, 0 closes the touch.

#if ESP_PANEL_USE_1024_600_LCD
    #define EXAMPLE_LCD_H_RES               (1024)
    #define EXAMPLE_LCD_V_RES               (600)
#else
    #define EXAMPLE_LCD_H_RES               (800)
    #define EXAMPLE_LCD_V_RES               (480)
#endif

#if ESP_PANEL_USE_1024_600_LCD
    #define EXAMPLE_LCD_PIXEL_CLOCK_HZ      (21 * 1000 * 1000)
#else
    #define EXAMPLE_LCD_PIXEL_CLOCK_HZ      (16 * 1000 * 1000)
#endif

#define EXAMPLE_LCD_BIT_PER_PIXEL       (16)
#define EXAMPLE_RGB_BIT_PER_PIXEL       (16)
#define EXAMPLE_RGB_DATA_WIDTH          (16)
#define EXAMPLE_RGB_BOUNCE_LINES        10
#define EXAMPLE_RGB_BOUNCE_BUFFER_SIZE  (EXAMPLE_LCD_H_RES * EXAMPLE_RGB_BOUNCE_LINES)
#define EXAMPLE_LCD_IO_RGB_DISP         (-1)             // -1 if not used
#define EXAMPLE_LCD_IO_RGB_VSYNC        (GPIO_NUM_3)
#define EXAMPLE_LCD_IO_RGB_HSYNC        (GPIO_NUM_46)
#define EXAMPLE_LCD_IO_RGB_DE           (GPIO_NUM_5)
#define EXAMPLE_LCD_IO_RGB_PCLK         (GPIO_NUM_7)
#define EXAMPLE_LCD_IO_RGB_DATA0        (GPIO_NUM_14)
#define EXAMPLE_LCD_IO_RGB_DATA1        (GPIO_NUM_38)
#define EXAMPLE_LCD_IO_RGB_DATA2        (GPIO_NUM_18)
#define EXAMPLE_LCD_IO_RGB_DATA3        (GPIO_NUM_17)
#define EXAMPLE_LCD_IO_RGB_DATA4        (GPIO_NUM_10)
#define EXAMPLE_LCD_IO_RGB_DATA5        (GPIO_NUM_39)
#define EXAMPLE_LCD_IO_RGB_DATA6        (GPIO_NUM_0)
#define EXAMPLE_LCD_IO_RGB_DATA7        (GPIO_NUM_45)
#define EXAMPLE_LCD_IO_RGB_DATA8        (GPIO_NUM_48)
#define EXAMPLE_LCD_IO_RGB_DATA9        (GPIO_NUM_47)
#define EXAMPLE_LCD_IO_RGB_DATA10       (GPIO_NUM_21)
#define EXAMPLE_LCD_IO_RGB_DATA11       (GPIO_NUM_1)
#define EXAMPLE_LCD_IO_RGB_DATA12       (GPIO_NUM_2)
#define EXAMPLE_LCD_IO_RGB_DATA13       (GPIO_NUM_42)
#define EXAMPLE_LCD_IO_RGB_DATA14       (GPIO_NUM_41)
#define EXAMPLE_LCD_IO_RGB_DATA15       (GPIO_NUM_40)

#define EXAMPLE_LCD_IO_RST              (-1)             // -1 if not used
#define EXAMPLE_PIN_NUM_BK_LIGHT        (-1)    // -1 if not used
#define EXAMPLE_LCD_BK_LIGHT_ON_LEVEL   (1)
#define EXAMPLE_LCD_BK_LIGHT_OFF_LEVEL  !EXAMPLE_LCD_BK_LIGHT_ON_LEVEL

#define EXAMPLE_PIN_NUM_TOUCH_RST       (-1)            // -1 if not used
#define EXAMPLE_PIN_NUM_TOUCH_INT       (-1)            // -1 if not used

esp_err_t waveshare_esp32_s3_rgb_lcd_init(uint8_t frame_buffer_count,
                                          esp_lcd_panel_handle_t *panel_handle,
                                          esp_lcd_touch_handle_t *touch_handle);

esp_err_t waveshare_rgb_lcd_backlight_on(void);

#endif
