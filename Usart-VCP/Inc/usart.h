/*
 * usart.h
 *
 *  Created on: Apr 5, 2025
 *      Author: danba
 */

#ifndef INC_USART_H_
#define INC_USART_H_

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



#endif /* INC_USART_H_ */
