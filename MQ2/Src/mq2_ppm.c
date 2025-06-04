#include "stm32f4xx.h"
#include "adc.h"
#include <math.h>
#include <mq2_ppm.h>
#include <stdio.h>

#define VREF     5.0f
#define ADC_RES  4095.0f
#define RL       10.0f
#define RO       10.0f

#define A       -667.2f
#define B        1334f



float MQ2_PPM_OP(void) {
	start_conversion_adc();
	uint32_t adc_val = adc_read();
	float voltage = ((float)adc_val / ADC_RES) * VREF;
	 if (voltage < 0.01f) {
	        // Avoid division by zero or invalid reading
	        return -1;
	    }
	 float Rs = RL * (VREF - voltage) / voltage;
	 float ratio = Rs / RO;
	 float ppm = powf(10, (log10f(ratio) - B) / A);
   return ppm;
}


