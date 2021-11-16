/* Author:  Liam Lage
 * Created: 16/11/2021
 *
 * Target: ESP_WROOM_32
 * 
 * Section 4 - Working With C
 * Lecture 4 - IDF Components & Other Source Files
 * https://learnesp32.com/videos/3/4_idf%20components%20-%20other%20source%20files
 * */

#include <stdio.h>
#include "module.h"

void app_main(void) {
    int result = moduleFunction(2, 3);
    printf("value id: %d\n", result);
}
