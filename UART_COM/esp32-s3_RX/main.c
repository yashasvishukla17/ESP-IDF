#include "driver/uart.h"

#define UART_PORT UART_NUM_1
#define TX_PIN 17
#define RX_PIN 18

void app_main(void){
    uart_config_t uart_config = {
        .baud_rate = 9600,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
    };

    uart_param_config(UART_PORT, &uart_config);
    uart_set_pin(UART_PORT, TX_PIN, RX_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    uart_driver_install(UART_PORT, 1024, 1024, 0, NULL, 0);

    uint8_t data[100];

    while (1){
        int len = uart_read_bytes(UART_PORT, data, sizeof(data), pdMS_TO_TICKS(1000));

        if (len > 0){
            uart_write_bytes(UART_PORT, "Received: ", 10);
            uart_write_bytes(UART_PORT, (const char *)data, len);
            uart_write_bytes(UART_PORT, "\n", 1);
            ESP_LOGI("UART", "Received %s", data);
        }
    }
}