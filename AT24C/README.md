# AT24C EEPROM HAL Driver (STM32)

This project provides a simple STM32 HAL-based driver for interfacing with AT24C series I2C EEPROMs (like AT24C256) using STM32Cube HAL drivers.

## ✅ Features

* Byte-wise read and write to any 16-bit memory address
* Sequential read/write operations
* Configurable I2C interface (`hi2c1`)
* Supports standard 7-bit EEPROM addressing (e.g., 0x50 << 1)
* Compatible with CubeMX generated HAL code

## ⚙️ Configuration

Define your EEPROM's 7-bit I2C address and the I2C handle:

```c
#define A24_ADDR 0x57  // (0xA0 >> 1) if A0-A2 are grounded
#define i2c_number &hi2c1
```

## 🧠 API Functions

### Write Functions

```c
void send_data_a24c(uint16_t addr, uint8_t data, uint16_t daddr);
void send_data_a24c_sequential(uint16_t addr, uint16_t daddr,
    uint8_t data_0, uint8_t data_1, uint8_t data_2, uint8_t data_3,
    int ignore_param);
```

### Read Functions

```c
uint8_t read_data_a24c(uint16_t addr, uint16_t daddr);
void read_data_a24c_sequential(uint16_t addr, uint16_t daddr, int incr_tim);
```

## 🚀 Usage Example

```c
uint8_t addr = 0x50 << 1;
uint8_t data_tx[3] = {58, 25, 62};

// Write single bytes
send_data_a24c(addr, data_tx[0], 0x0100);
send_data_a24c(addr, data_tx[1], 0x0101);
send_data_a24c(addr, data_tx[2], 0x0102);

// Sequential write
send_data_a24c_sequential(addr, 0x0150, data_tx[2], data_tx[1], data_tx[0], 1);

// Read individual bytes
printf("%u%u%u\n", read_data_a24c(addr, 0x0100),
                     read_data_a24c(addr, 0x0101),
                     read_data_a24c(addr, 0x0102));

// Sequential read with debug output
read_data_a24c_sequential(addr, 0x0150, 3);
```

## 🛠️ Dependencies

* STM32 HAL
* STM32CubeMX-generated initialization code for I2C and UART (optional for `printf`)

## 📄 License

MIT or ST-provided license depending on source context.

## 📬 Author

Aryan Basnet

Feel free to adapt this driver to add features like page write, string support, or auto-wrap handling for larger EEPROMs.
