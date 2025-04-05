/*
 * flow.h
 *
 *  Created on: Mar 31, 2025
 *      Author: danba
 */

#ifndef INC_FLOW_H_
#define INC_FLOW_H_

#ifndef FLOW_SENSOR_H
#define FLOW_SENSOR_H

#include <stdint.h>
#include "stm32f4xx.h"

void clk_en(void);
void gpio_config(void);
void pwm_upcounter_config(void);
void delay_ms(uint32_t ms);
int flow_rate(void);
int turbine_rpm(void);
void counter_reset(void);
int volume(void);

#endif // FLOW_SENSOR_H

#endif /* INC_FLOW_H_ */
