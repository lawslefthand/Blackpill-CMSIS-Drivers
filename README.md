# STM32 Blackpill CMSIS Drivers

A comprehensive collection of **CMSIS** and **HAL-based drivers** written in C for the STM32F401CEU-powered **Blackpill** development boards. This repository focuses on providing **clean, modular, and reusable drivers** for commonly used peripherals, enabling developers to have full control over the hardware.

While primarily targeted at the STM32F401CEU, these drivers are also compatible with the STM32F411CEU with minimal modifications (mainly in clock configuration).

---

## Key Features

* **Modular and Scalable Architecture** – Each driver is implemented independently, making it easy to integrate only what is needed.
* **Optimized for Performance** – Minimal abstraction layers to ensure low overhead and high efficiency.
* **Portable Across STM32F4 Series** – Code can be easily adapted to other MCUs in the STM32F4 family.
* **Blackpill-Oriented Testing** – Verified and tested on STM32F401CEU-based Blackpill boards.
* **CMSIS-Level Control** – Direct register-level access with the option to mix with HAL if needed.

---

## Drivers Included

The repository currently includes (with new drivers being added regularly):

* **GPIO Driver** – Digital input/output, alternate functions, pull-up/pull-down configuration.
* **RCC Driver** – Clock control and configuration for system and peripherals.
* **I2C Driver** – Master mode communication support with common sensor modules.
* **USART Driver** – UART/USART communication with interrupt-based or polling modes.
* **SysTick Driver** – System tick configuration for timing and delays.
* **SPI Driver** *(Work in Progress)* – Full-duplex synchronous communication.

---

## Board Pinout

![STM32 Blackpill Pinout](https://github.com/user-attachments/assets/61edcc62-1b1b-4fc0-8368-e75bea8b4cd0)

---

## Documentation

Each driver is documented within its respective header file (`.h`). The documentation includes:

* Register definitions and explanations
* Usage examples
* Configuration options
* Integration notes for combining multiple drivers

Additionally, example projects are provided in the `examples/` directory to help new users get started quickly.

---

## Getting Started

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/stm32-blackpill-drivers.git
   ```

2. Include the desired driver from the `drivers/` folder in your project.

3. Configure the system clock and peripherals in your `system_stm32f4xx.c` or CMSIS startup file.

4. Refer to the provided examples for integration guidance.

---

## Contributions

We welcome contributions of any kind:

* New driver implementations
* Example projects
* Bug fixes and optimizations
* Documentation improvements

Before submitting a pull request:

* Follow the existing code style
* Provide adequate documentation in the header files
* Test the changes on hardware where possible

---

## License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for full details.

---

### 🔗 Related Resources

* [STM32F401 Reference Manual](https://www.st.com/resource/en/reference_manual/dm00096844-stm32f401xcc-advanced-armbased-32bit-mcus-stmicroelectronics.pdf)
* [CMSIS Documentation](https://arm-software.github.io/CMSIS_5/)
* [Blackpill Board Overview](https://stm32-base.org/boards/STM32F401CCU6-Black-Pill)
