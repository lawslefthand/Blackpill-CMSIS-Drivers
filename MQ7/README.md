# MQ7 Carbon Monoxide Sensor Driver for STM32F401CCU6

This project provides a basic driver and interface for the **MQ7 carbon monoxide (CO) gas sensor**, implemented on the **STM32F401CCU6** microcontroller. The MQ7 is widely used for detecting **CO concentrations** in the range of 20–2000 ppm.

| Path     | File Name  | Description                                  |
| -------- | ---------- | -------------------------------------------- |
| MQ7/inc/ | UART.h     | UART configuration and function declarations |
| MQ7/inc/ | adc.h      | ADC initialization and reading functions     |
| MQ7/inc/ | mq7\_ppm.h | Functions to convert ADC data to CO PPM      |
| MQ7/src/ | UART.c     | UART initialization and send routines        |
| MQ7/src/ | adc.c      | ADC driver code                              |
| MQ7/src/ | mq7\_ppm.c | Logic for PPM calculation from sensor data   |
| MQ7/     | main.c     | Main file demonstrating sensor usage         |

---

## Hardware Used

* **MCU**: STM32F401CCU6 ("Black Pill")
* **Sensor**: MQ7 carbon monoxide sensor
* **Power Supply**: 5V for sensor heater, 3.3V logic for STM32
* **ADC**: Built-in STM32F4 ADC
* **UART**: For serial output (via USB-Serial or ST-Link V2)

---

## Features

* Reads analog sensor data using STM32 ADC
* Converts raw ADC values to **CO concentration (ppm)**
* Outputs sensor data via UART
* Modular, reusable driver design for portability

---

## Wiring (MQ7 → STM32F401)

| MQ7 Pin | Description      | STM32F401 Pin |
| ------- | ---------------- | ------------- |
| VCC     | +5V Heater Power | 5V supply     |
| GND     | Ground           | GND           |
| AOUT    | Analog Out       | `PA1` (ADC)   |

> Update the GPIO pin in `adc.c` if using a different channel.

---

## Output Example

UART output at 115200 baud rate:

```
CO Concentration: 120 PPM
```

---

## How to Build

1. Open the project in **STM32CubeIDE** or **Keil uVision**.
2. Configure ADC channel and UART pins in `.ioc` or `main.c`.
3. Compile and flash to your STM32 board.
4. Use a serial terminal (PuTTY, TeraTerm, or Arduino IDE Serial Monitor) to read values.

---

## MQ7 Sensor Working Principle

The MQ7 sensor detects CO based on the change in resistance of a heated **SnO₂ (tin dioxide)** sensing element.

* **Low heater voltage (1.5V for \~90s)**: Sensor is in measurement phase
* **High heater voltage (5V for \~60s)**: Sensor cleans itself

The resistance ratio **Rs/Ro** is used to determine CO concentration:

* **Rs** = Sensor resistance in CO gas
* **Ro** = Sensor resistance in clean air

Using the MQ7 datasheet curve:

```
PPM = a * (Rs/Ro)^b
```

Where `a` and `b` are constants derived from calibration.

---

## Calibration Method

1. **Burn-in**: Run sensor for 24 hours in clean air.
2. **Measure Ro**: Use voltage divider:

   ```
   Rs = (Vc * RL / Vout) - RL
   ```

   Then calculate Ro using datasheet reference ratio.
3. **Calibration Curve**: Apply curve fitting for Rs/Ro vs CO concentration.

---

## License

This project is licensed under the **MIT License**. See `LICENSE` file for details.

---

## Contributing

Contributions are welcome:

* New drivers (other MQ-series sensors)
* Improvements to calibration accuracy
* Documentation enhancements

Raise an issue or submit a pull request with your changes.

---

