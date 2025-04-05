# USART VCP Driver (CMSIS, STM32F4xx)

This module provides a minimal USART driver built using CMSIS for STM32F4xx-based boards, specifically for serial communication over a Virtual COM Port (VCP) using a broken or generic ST-Link debugger or USB-TTL adapter.

## Features

- ⚙️ Pure CMSIS, no HAL or CubeMX required
- 🖨️ `printf()` redirection to USART2 for debug logging
- 🔌 Designed for use with Virtual COM Port over ST-Link or external USB UARTs

## File Structure

```
usart/
├── usart.c       // USART2 config, TX function, and printf redirection
└── usart.h       // Configuration macros and function prototypes
```

## Pin Mapping

- `PA2` — USART2 TX (connect to RX of USB-TTL or debugger)

## Configuration Macros (in `usart.h`)

```c
#define USART_PIN            (1U<<2)   // PA2 TX pin
#define USART_GPIO_EN        (1U<<0)   //  GPIOA clock
#define USART_EN_CLK         (1U<<17)  // USART2 clock
#define USART_GPIO_NAME       GPIOA
#define USART_EN             (1U<<13)  // USART enable
#define USART_TE_EN          (1U<<3)   // Transmitter enable
#define USART_NAME           USART2
#define DESIRED_BAUD_RATE    115200
#define MCU_CLK              84000000
#define USART_TX_STATUS      (1U<<7)   // TXE flag in SR
```

## Usage

### Initialization Sequence

```c
usart_gpio_init();   // Configure PA2 as AF7 (USART2_TX)
usart_init();        // Enable USART2 with selected baud rate
```

### Example

```c
usart_gpio_init();
usart_init();

printf("USART2 VCP is live!\n");
```

Once `__io_putchar()` is defined, standard `printf()` calls will transmit characters via USART2.

## Notes

- RX functionality is not implemented; only TX is supported (for serial output)
- Works well for debug logging and sensor data transmission
- Baud rate can be customized via macro

## License

MIT License. See main repository for full details.

