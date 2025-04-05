#include <stdint.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "stm32f4xx.h"
#include "bmp280_i2c.h"
#include "usart.h"
#include "main.h"

#define CTRL_MEAS_SETTING 0b11111111
#define CONFIG_SETTING   0xFF

int main() {

	init_usart_tx();
	printf("bmp pre-init sucess");
	bmp_i2c_setup();
    printf("bmp init sucess");




	while (1) {

		printf("waiting");

	  	bmp_i2c_write(0xF5, 0xFF); //Recommended to apply init every loop if power loss is to be expected.
	    	bmp_i2c_write(0xF4,  0xFF );


		double temp = 0;
		double press = 0;
		double alt = 0;

		temp = temperature(0);
		press = pressure();
		alt = altitude();

		printf("temp %f\n", temp);
		printf("press %f\n", press);
		printf("temp %f\n", alt);
        delay_ms(1000);


	}


}
