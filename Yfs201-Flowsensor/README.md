![water-flow-sensor-0 5-inch-yf-s201-800x800](https://github.com/user-attachments/assets/e103a08e-e811-4614-aeac-b8d3b95ab5f4)

## Flow Sensor Driver for STM32 Blackpill boards (F401CCU/F401CEU)

This sections contains an STM32-based driver for the YF-S201 flow sensor using the TIM1 peripheral for pulse counting. The driver calculates flow rate, turbine RPM, and total volume.

## Features
- Measures **flow rate (L/min)** based on sensor pulses
- Calculates **turbine RPM**
- Tracks **total volume passed**
- Uses **TIM1 in input capture mode**

## Hardware Requirements
- STM32F4 microcontroller
- YF-S201 flow sensor
- USART for debug output

## Installation
1. Clone this repository:
   ```sh
   git clone https://github.com/your-repo/flow-sensor-driver.git
   ```
2. Include the `flow_sensor.h` and `flow_sensor.c` files in your STM32CubeIDE project.

## Functions
### Initialization
```c
void clk_en(void);
void gpio_config(void);
void pwm_upcounter_config(void);
```
These functions configure the necessary clocks, GPIOs, and TIM1 for counting pulses.

### Flow Rate Calculation
```c
int flow_rate(void);
```
- Returns flow rate in **liters per minute (L/min)**.

### Volume Measurement
```c
int volume(void);
void reset_volume(void);
```
- `volume()`: Returns total volume passed in liters.
- `reset_volume()`: Resets total volume count.

### Turbine RPM Calculation
```c
int turbine_rpm(void);
```
- Returns turbine RPM based on 8 pulses per revolution.

### Delay Function
```c
void delay_ms(uint32_t ms);
```
- Implements millisecond delay using SysTick.

## Connections
| YF-S201 Pin | STM32F4 Pin |
|------------|------------|
| VCC (Red)  | 5V         |
| GND (Black)| GND        |
| Signal (Yellow) | PA8 (TIM1 CH1) |

# Flow Sensor Pulse/Liter Data

| Sensor Type | Code    | Pulse/Liter |
|-------------|--------|-------------|
| YF-S201     | YFS201 | 7.5         |
| YF-S401     | YFS401 | 5880        |
| YF-B1       | YFB1   | 660         |
| YF-B1-S     | YFB1S  | 1077        |
| OF10ZAT     | OF10ZAT| 400         |
| OF10ZZT     | OF10ZZT| 400         |
| OF05ZAT     | OF05ZAT| 2174        |
| OF05ZZT     | OF05ZZT| 2174        |

## Definitions
For correct sensor configuration, use the following in your flow.c:

```c
#define Pulse_per_litre 7.5      // Set according to your sensor model
#define Blade_numb number 8       // Number of blades in the turbine
```

## Usage
Example code in `main.c`.

## Note
Always put a small delay (250ms-1000ms) or you wont receive proper values due to the timer requiring a 1s internal delay for pulse counter.

## License
This project is licensed under the MIT License.








