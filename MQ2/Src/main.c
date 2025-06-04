# include <stdint.h>
#include "stm32f4xx.h"
#include "UART.h"
#include "adc.h"
#include <stdio.h>
#include <math.h>
#include <mq2_ppm.h>

float output;
int main()

{
	//https://community.st.com/t5/stm32cubeide-mcus/fpu-is-not-initialized/td-p/620629
	#if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
	SCB->CPACR |= ((3UL << 10 * 2) |
			(3UL << 11 * 2));  /* set CP10 and CP11 Full Access */
	#endif
	USART_TX_INIT_();
	ADC_INIT_();


	while (1)
	{
		output=MQ2_PPM_OP();
		printf("The sensor value is : %.2f PPM For Carbon-Monoxide (MQ-7) \n\r",output);
		for (volatile int i = 0; i < 1000000; i++) {}  //  delay loop




	}
}

