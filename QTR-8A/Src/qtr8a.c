/*
 * qtr8a.c
 *
 *  Created on: Apr 5, 2025
 *      Author: danba
 */

#include "stm32f4xx.h"
#include <stdio.h>
#include <usart.h>
#include <stdint.h>


void clk_enable() {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // Enable GPIOA clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN; // Enable GPIOB clock
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;  // Enable ADC1 clock
}

void gpio_config() {
    // PA0, PA1, PA4, PA6, PA7 as analog mode
    GPIOA->MODER |= (3 << 0) | (3 << 2) | (3 << 8) | (3 << 12) | (3 << 14);
    GPIOA->PUPDR &= ~((3 << 0) | (3 << 2) | (3 << 8) | (3 << 12) | (3 << 14));

    // PB0 as analog mode
    GPIOB->MODER |= (3 << 0);
    GPIOB->PUPDR &= ~(3 << 0);
}

void adc_enable(void) {
    ADC1->CR2 |= ADC_CR2_ADON;
}

void adc_config(void) {
    ADC1->SMPR2 |= ADC_SMPR2_SMP0 | ADC_SMPR2_SMP1 | ADC_SMPR2_SMP4 | ADC_SMPR2_SMP6 | ADC_SMPR2_SMP7;
}

void adc_init(void) {
    clk_enable();
    gpio_config();
    adc_config();
    adc_enable();
}

uint32_t conv_start(uint8_t channel) {
    ADC1->SQR3 = channel;
    ADC1->CR2 |= ADC_CR2_SWSTART;
    while (!(ADC1->SR & ADC_SR_EOC));
    return ADC1->DR; //
}

uint32_t conv_start1(void) { return conv_start(0); }  // PA0
uint32_t conv_start2(void) { return conv_start(1); }  // PA1
uint32_t conv_start3(void) { return conv_start(4); }  // PA4
uint32_t conv_start4(void) { return conv_start(8); }  // PB0
uint32_t conv_start5(void) { return conv_start(6); }  // PA6 (Replaces PC0)
uint32_t conv_start6(void) { return conv_start(7); }  // PA7 (Replaces PC1)
