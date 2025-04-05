#include "stm32f4xx.h"
#include <stdio.h>



void usart_gpio_init(void);
void usart_init(void);
int brr_calc(void);
void uart2_write(int ch);
int __io_putchar(int ch);

int main()
{
    usart_gpio_init();
    usart_init();

    while(1)
    {
        printf("your message here\n");
        for (volatile int i = 0; i < 1000000; i++);
    }
}
