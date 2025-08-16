
# QTR-8A Analog Reflectance Sensor Driver (CMSIS)

This directory contains a CMSIS-based driver implementation for interfacing the **QTR-8A analog reflectance sensor** with the STM32F4 series microcontrollers, specifically tested on STM32F4xx-based boards.

## Overview

The QTR-8A sensor provides 8 analog output channels that correspond to reflectance detected by IR sensors. This driver reads up to 6 channels using ADC1 with direct register-level (CMSIS) access, offering high-speed, low-overhead sampling for embedded robotics applications such as line following.

## Features

- CMSIS-only driver (no HAL or CubeMX)
- High-speed single-conversion ADC reads
- Easy-to-extend design for additional analog channels
- Modular conversion functions per channel

## Pins Used

| Sensor Channel | MCU Pin | ADC Channel |
|----------------|---------|-------------|
| 1              | PA0     | IN0         |
| 2              | PA1     | IN1         |
| 3              | PA4     | IN4         |
| 4              | PB0     | IN8         |
| 5              | PA6     | IN6         |
| 6              | PA7     | IN7         |

> PC0 and PC1 are not used in this version to simplify configuration.

## File Structure

```
qtr8a/
 ├── qtr8a.c       // Source file with ADC and GPIO config
 └── qtr8a.h       // Header file with function declarations (optional)
```

## Usage

1. Include the `qtr8a.c` file in your project.
2. Call `adc_init()` once during startup to initialize clocks, GPIOs, and ADC settings.
3. Use the provided `conv_startX()` functions to read each reflectance sensor.

### Example
```c
adc_init();
uint32_t left_sensor = conv_start1();
uint32_t right_sensor = conv_start6();
```

## Notes

- This driver assumes single-channel polling reads. If faster multi-channel reads are needed, consider using DMA or scan conversion.
- This implementation uses ADC1 only.

## License

MIT License. See main repository for full license details.
