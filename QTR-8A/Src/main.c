#include "stm32f4xx.h"
#include <stdio.h>
#include <usart.h>
#include "qtr8a.h"


int main(void) {
    adc_init();
    init_usart_tx();
    printf("init success\n");

    while (1) {
        uint32_t sensor1 = conv_start1();
        uint32_t sensor2 = conv_start2();
        uint32_t sensor3 = conv_start3();
        uint32_t sensor4 = conv_start4();
        uint32_t sensor5 = conv_start5();
        uint32_t sensor6 = conv_start6();

        printf("S1: %lu, S2: %lu, S3: %lu\n", sensor1, sensor2, sensor3);
        printf("S4: %lu, S5: %lu, S6: %lu\n", sensor4, sensor5, sensor6);

       // for (volatile int i = 0; i < 1000000; i++); // Small delay
    }
}
