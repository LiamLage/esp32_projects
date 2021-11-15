#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void) {
    char c = 0;
    char str[100];
    memset(str, 0, sizeof(str));

    printf("Enter some characters:\n");
    while (c != '\n') {
        c = getchar();
        if (c != 0xFF) {
            str[strlen(str)] = c;
            printf("%c", c);
        }
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
    printf("\n\nuser input:\n%s\n", str);
}
