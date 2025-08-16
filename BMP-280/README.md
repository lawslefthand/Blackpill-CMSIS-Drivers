# BMP280 I2C Driver (CMSIS)

This directory contains a CMSIS-based driver for interfacing with the **Bosch BMP280** temperature and pressure sensor using I2C. Designed for STM32F4xx-based boards, this driver avoids using HAL and provides low-level register control with support for temperature, pressure, and altitude calculations.

## Features

- Fully CMSIS-based (no HAL/CubeMX)
- Pressure, temperature, and altitude readouts
- Supports user-defined oversampling and filter settings
- I2C interface implementation from scratch

## File Structure

```
bmp280/
 ├── bmp280_i2c.c       // Low-level I2C driver and BMP280 functions
 └── bmp280_i2c.h       // Function declarations
```

## Quick Start

### Hardware Required

- STM32F4 board
- BMP280 module (I2C version)
- Pull-up resistors on SDA and SCL lines (typically 4.7kΩ)

### Default I2C Address

The BMP280 default I2C address is `0x76`. (Check if your module uses `0x77` instead.)

## API Summary

- `bmp_i2c_setup()` – Initializes I2C and verifies sensor connection
- `bmp_i2c_write(uint8_t reg, uint8_t data)` – Writes a register
- `temperature(int compensation)` – Returns temperature in °C
- `pressure()` – Returns pressure in Pa
- `altitude()` – Calculates altitude in meters based on pressure

## Example Usage

```c
init_usart_tx();
bmp_i2c_setup();

while (1) {
    bmp_i2c_write(0xF5, CONFIG_SETTING);
    bmp_i2c_write(0xF4, CTRL_MEAS_SETTING);

    double temp = temperature(0);
    double press = pressure();
    double alt = altitude();

    printf("Temp: %f\n", temp);
    printf("Pressure: %f\n", press);
    printf("Altitude: %f\n", alt);

    delay_ms(1000);
}
```

> Tip: Rewriting config registers inside the loop is useful in power-unstable environments.

## Notes

- Sensor must be powered and connected via I2C before calling `bmp_i2c_setup()`
- Altitude is computed using the standard sea-level pressure (1013.25 hPa)

## License

MIT License. See root repository for licensing details.

