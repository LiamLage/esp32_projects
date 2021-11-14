#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define PIN 2

void app_main(void) {
    gpio_pad_select_gpio(PIN);  // select pad as a gpio function  
    gpio_set_direction(PIN, GPIO_MODE_OUTPUT);  // define the pin as an output
    int isOn = 0;   // on / off flag
    while (true) {
        isOn = !isOn;
        gpio_set_level(PIN, isOn);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
