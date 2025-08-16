
 # MQ2 Gas Sensor Driver for STM32F401CCU6

This project provides a basic driver and interface for the **MQ2 gas sensor**, implemented on the **STM32F401CCU6** microcontroller. The sensor detects gases like **LPG, smoke, alcohol, propane, hydrogen, methane, and carbon monoxide**.

| Path             | File Name     | Description                                 |
|------------------|---------------|---------------------------------------------|
| MQ2/inc/         | UART.h        | UART configuration and function declarations |
| MQ2/inc/         | adc.h         | ADC initialization and reading functions     |
| MQ2/inc/         | mq2_ppm.h     | Functions to convert ADC data to PPM         |
| MQ2/src/         | UART.c        | UART initialization and send routines        |
| MQ2/src/         | adc.c         | ADC driver code                              |
| MQ2/src/         | mq2_ppm.c     | Logic for PPM calculation from sensor data   |
| MQ2/             | main.c        | Main file demonstrating sensor usage         |



---

## 🔧 Hardware Used

- **MCU**: STM32F401CCU6 ("Black Pill")
- **Sensor**: MQ2 gas sensor
- **Power Supply**: 5V for sensor, 3.3V logic for STM32
- **ADC**: Built-in STM32F4 ADC
- **UART**: For serial output (via USB-Serial or ST-Link V2) , use serial debugger tool 

---

## Features

- Reads analog gas sensor data via ADC
- Converts raw values to **PPM (parts per million)** using a simple calibration curve
- Sends data over UART
- Modular and clean code with reusable driver structure

---

##  Wiring (MQ2 → STM32F401)

| MQ2 Pin | Description  | STM32F401 Pin |
|---------|--------------|----------------|
| VCC     | +5V Power    | 3.3V             |
| GND     | Ground       | GND            |
| AOUT    | Analog Out   | `PA1` (ADC)    |

> 💡 Adjust the pin in `adc.c` if using a different GPIO.

---

## Output Example

The UART output (115200 baud rate) looks like:
**The sensor value is : 30 PPM**

---

## How to Build

1. Open the project in **STM32CubeIDE** or **Keil uVision**.
2. Ensure correct ADC and UART pins are configured in `.ioc` or `main.c`.
3. Compile and flash the code to your STM32 board.
4. Open a serial terminal (e.g., PuTTY, TeraTerm) to view output.



## MQ2 Sensor Working Principle

The MQ2 sensor detects gas concentrations based on a change in resistance of a heated sensitive material(TIN DIOXIDE). The sensor outputs an analog voltage proportional to gas concentration.

- **Rs**: Sensor resistance in gas
- **Ro**: Sensor resistance in clean air

  
## Calibration Method

1. **Environment**: Sensor powered on for 24 hours in clean air (burn-in time).
2. **Measured Ro**: Using voltage divider formula:           Rs = (Vc * RL / Vout) - RL
3. **Known Clean Air Value**:
- `Rs/Ro ≈ 9.8` in clean air (from MQ2 datasheet)
- Calculated `Ro` using average `Rs / 9.8`
  

## License

This project is open-sourced under the MIT License. See `LICENSE` file.

---

## Contributing

Pull requests and forks are welcome. If you find any bugs or want to suggest improvements, feel free to raise an issue.

---

## Acknowledgements

- STMicroelectronics for libraries
- MQ2 datasheets and community for calibration curve data



