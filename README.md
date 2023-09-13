# ARM Cortex-M3 Drivers

Welcome to the ARM Cortex-M3 Drivers repository! This repository contains drivers for the STM32F103 ARM Cortex-M3 microcontroller.

## Layers

1. **Library Layer**: This layer includes common utility modules such as `std_types` and `common_macros` for standardized types and macros.

2. **MCAL (Microcontroller Abstraction Layer) Layer**: This layer provides low-level drivers for various microcontroller peripherals, including:
   - RCC (Reset and Clock Control)
   - DIO (Digital Input/Output)
   - AFIO (Alternate Function I/O)
   - EXTI (External Interrupts)
   - STK (SysTick Timer)
   - NVIC (Nested Vectored Interrupt Controller)
   - ADC (Analog-to-Digital Converter)
   - GPT (General Purpose Timers)
   - UART (Universal Asynchronous Receiver-Transmitter)
   - SPI (Serial Peripheral Interface)
   - I2C (Inter-Integrated Circuit)
   - FPEC (Flash Memory Programming/Erasing Controller)


## Module Structure

Each module within the layers follows a consistent structure:

- `config.h`: Configuration settings for the module.
- `interface.h`: Public APIs and user interface functions.
- `private.h`: Private register definitions and functions.
- `program.c`: Implementation of the module.


## Contribution

Contributions to this repository are welcome! If you find any issues, have enhancements, or want to add support for more modules, please feel free to create pull requests.

## License

This repository is open-source and distributed under the [MIT License](LICENSE).

