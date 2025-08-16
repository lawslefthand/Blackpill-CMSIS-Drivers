![4877_top_ORIG_2021_03](https://github.com/user-attachments/assets/9978fc25-602d-43a1-9f4f-04f3449879b7)
# STM32 Blackpill CMSIS Drivers

A comprehensive collection of **CMSIS** and selective **HAL-based drivers** written in C for the STM32F401CEU-powered **Blackpill** development boards. This repository focuses on providing **clean, modular, and reusable drivers** for commonly used peripherals, enabling developers to have full control over the hardware.

While primarily targeted at the STM32F401CEU, these drivers are also compatible with the STM32F411CEU with minimal modifications (mainly in clock configuration).

---

## Key Features

* **Modular and Scalable Architecture** – Each driver is implemented independently, making it easy to integrate only what is needed.
* **Optimized for Performance** – Minimal abstraction layers to ensure low overhead and high efficiency.
* **Portable Across STM32F4 Series** – Code can be easily adapted to other MCUs in the STM32F4 family.
* **Blackpill-Oriented Testing** – Verified and tested on STM32F401CEU-based Blackpill boards.
* **CMSIS-Level Control** – Direct register-level access with the option to mix with HAL if needed.

---
## Board Pinout
F411CCU:
<img width="1280" height="739" alt="STM32-STM32F4-STM32F411-STM32F411CEU6-pinout-low-resolution png" src="https://github.com/user-attachments/assets/4248c9c3-d492-4764-b207-18cf1837b7a2" />
F401CEU:
<img width="1280" height="779" alt="STM32-STM32F4-STM32F401-STM32F401CCU6-pinout-low-resolution jpg" src="https://github.com/user-attachments/assets/6a1b8725-3bf2-4acb-b415-4d1c36f9c89c" />


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
