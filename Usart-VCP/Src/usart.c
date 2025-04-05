/*
 * usart.c
 *
 *  Created on: Apr 5, 2025
 *      Author: danba
 */

#include "usart.h"
#include <stdio.h>
#include "stm32f4xx.h"

int __io_putchar(int ch)
{
    uart2_write(ch);
    return ch;
}

void uart2_write(int ch)
{
    while (!(USART_NAME->SR & USART_TX_STATUS)) {}
    USART_NAME->DR = (ch & 0xFF);
}

int brr_calc(void)
{
    return (MCU_CLK + (DESIRED_BAUD_RATE / 2)) / DESIRED_BAUD_RATE;
}

void usart_gpio_init(void)
{
    RCC->AHB1ENR |= USART_GPIO_EN;  // GPIOA clock
    RCC->APB1ENR |= USART_EN_CLK;   // USART2 clock

    // PA2 as Alternate Function (AF7)
    USART_GPIO_NAME->MODER &= ~(1U << 4);
    USART_GPIO_NAME->MODER |= (1U << 5);

    USART_GPIO_NAME->AFR[0] |= (7U << 8);  // AF7 for PA2
}

void usart_init(void)
{
    USART_NAME->BRR = 139;
    USART_NAME->CR1 = USART_TE_EN;
    USART_NAME->CR1 |= USART_EN;
}
