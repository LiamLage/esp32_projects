#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "math.h"

#define TAG "DICE"

int dice_roll(void);

// diceroll: return a random number between zero & six
int dice_roll(void) {
    int random = esp_random();
    int positiveNumber = abs(random);   // make number positive
    int diceNumber = (positiveNumber % 6) + 1;  // 0 <= dice number <= 6
    return diceNumber;
}

void app_main(void) {
    while (1) {
        vTaskDelay(1000 / portTICK_PERIOD_MS);  // divide by portTICK_PERIOD_MS to get ms
        ESP_LOGI(TAG, "random number: %d", dice_roll());   // esp has a built in random number generator, include esp_system.h to access it
    }
    
}