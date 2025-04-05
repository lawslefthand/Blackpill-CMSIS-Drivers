/*
 * usart.h
 *
 *  Created on: Sep 2, 2024
 *      Author: danba
 */

#ifndef SRC_USART_H_
#define SRC_USART_H_



void usart_gpio_init(void);
void usart_init(void);
int brr_calc(void);
void uart2_write(int ch);
int __io_putchar(int ch);
void init_usart_tx(void);

#endif /* SRC_USART_H_ */
