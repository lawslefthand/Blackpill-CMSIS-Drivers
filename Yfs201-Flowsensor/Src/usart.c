#include "stm32f4xx.h"
#include <stdio.h>

#define USART_PIN            (1U<<2)   // PA2 TX pin
#define USART_GPIO_EN        (1U<<0)   //  GPIOA clock
#define USART_EN_CLK         (1U<<17)  // USART2 clock
#define USART_GPIO_NAME       GPIOA
#define USART_EN             (1U<<13)  // USART enable
#define USART_TE_EN          (1U<<3)   // Transmitter enable
#define USART_NAME           USART2
#define DESIRED_BAUD_RATE    115200
#define MCU_CLK              84000000
#define USART_TX_STATUS      (1U<<7)   // TXE flag in SR

void usart_gpio_init(void);
void usart_init(void);
int brr_calc(void);
void uart2_write(int ch);
int __io_putchar(int ch);


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

void init_usart_tx(void)
{
	usart_gpio_init();
	usart_init();
}
