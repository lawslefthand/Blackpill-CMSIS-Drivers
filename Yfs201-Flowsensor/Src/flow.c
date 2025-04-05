// flow_sensor.c
#include "flow.h"
#include "stm32f4xx.h"
#include "usart.h"
#include <stdio.h>

void clk_en(void) {
	RCC->AHB1ENR |= (1 << 0);
	RCC->AHB1ENR |= (1 << 1);
	RCC->AHB1ENR |= (1 << 2);
	RCC->APB1ENR |= (1 << 1);
	RCC->APB2ENR |= (1 << 0);
}

void gpio_config(void) {
	GPIOA->MODER &= ~(1 << 16);
	GPIOA->MODER |= (1 << 17);
	GPIOA->AFR[1] |= (1 << 0);
	GPIOA->AFR[1] &= ~(1 << 1);
	GPIOA->AFR[1] &= ~(1 << 2);
	GPIOA->AFR[1] &= ~(1 << 3);
}

void pwm_upcounter_config(void) {
	TIM1->CCMR1 |= TIM_CCMR1_IC1F_0 | TIM_CCMR1_IC1F_1 | TIM_CCMR1_CC1S_0;
	TIM1->CCER |= TIM_CCER_CC1E;
	TIM1->CCER &= (uint16_t) (~TIM_CCER_CC1P);
	TIM1->SMCR |= TIM_SMCR_SMS_2 | TIM_SMCR_SMS_1 | TIM_SMCR_SMS_0;
	TIM1->SMCR |= TIM_SMCR_TS_2 | TIM_SMCR_TS_0;
	TIM1->SMCR &= ~(TIM_SMCR_TS_1);
	TIM1->CR1 |= TIM_CR1_CEN;
}

void delay_ms(uint32_t ms) {
	SysTick->LOAD = (SystemCoreClock / 8000) * ms - 1;
	SysTick->VAL = 0;
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
	while ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == 0);
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}

int flow_rate(void) {
	int counter_value = TIM1->CNT;
	delay_ms(1000);
	TIM1->CNT = 0;
	return counter_value / 7.5;
}

int turbine_rpm(void) {
	int counter_value = TIM1->CNT;
	delay_ms(1000);
	TIM1->CNT = 0;
	return ((counter_value * 60) / 8);
}

static int total_pulses = 0;

int volume(void) {
    total_pulses += TIM1->CNT;
    //printf("Total Volume Pulses: %d\n", total_pulses);
    delay_ms(1000);
    return total_pulses;
}


void counter_reset(void) {
	TIM1->CNT = 0;
}


