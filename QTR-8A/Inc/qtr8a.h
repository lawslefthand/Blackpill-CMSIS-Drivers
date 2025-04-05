/*
 * qtr8a.h
 *
 *  Created on: Apr 5, 2025
 *      Author: danba
 */

#ifndef INC_QTR8A_H_
#define INC_QTR8A_H_


void clk_enable(void);
void gpio_config(void);
void adc_enable(void);
void adc_config(void);
void adc_init(void);

uint32_t conv_start(uint8_t channel);
uint32_t conv_start1(void);  // PA0
uint32_t conv_start2(void);  // PA1
uint32_t conv_start3(void);  // PA4
uint32_t conv_start4(void);  // PB0
uint32_t conv_start5(void);  // PA6
uint32_t conv_start6(void);  // PA7

#endif /* INC_QTR8A_H_ */
