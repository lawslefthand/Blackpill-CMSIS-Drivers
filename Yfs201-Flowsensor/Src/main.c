#include "flow.h"
#include "stm32f4xx.h"
#include "usart.h"
#include "main.h"
#include <stdio.h>

int main() {
	init_usart_tx();
	clk_en();
	gpio_config();
	pwm_upcounter_config();
	while (1) {
		printf("Flow rate is %dLitres per Minute\n", flow_rate());
		delay_ms(1000);
		printf("Turbine RPM is %d\n", turbine_rpm());
		delay_ms(1000);
		printf("Volume is %d\n", volume());
		delay_ms(1000);
	}
}
