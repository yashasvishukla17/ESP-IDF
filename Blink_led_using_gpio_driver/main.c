#include <driver/gpio.h>
#include<freertos/FreeRTOS.h>
#include "esp_log.h"
#include<freertos/task.h>
#define LED_PIN 2

void app_main(void){
    gpio_reset_pin(LED_PIN); //reset the pin in the beginning
    gpio_set_direction(LED_PIN,GPIO_MODE_OUTPUT); //pinMode
    while(1){ //kinda like loop
        ESP_LOGI("MAIN","LED IS BLINKING");
        gpio_set_level(LED_PIN,1); //digitalWrite
        vTaskDelay(pdMS_TO_TICKS(1000)); //delay

        gpio_set_level(LED_PIN,0);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

