# AVR ATmega32 Drivers — MG Architecture

> **Plug-and-Play, Register-Level Embedded C Drivers for Microchip AVR ATmega32.**  
> Engineered from scratch using a modular **Layered Architecture (`LIB` → `MCAL` → `HAL` → `APP`)** for clean integration, high readability, and zero hardware dependency in application code.

<img width="554" height="554" alt="images" src="https://github.com/user-attachments/assets/e8a517b5-49f8-4e63-974e-dfeb15410ef6" />

---

## Why Use This Repository?
* **Zero Dependency & Portable:** Written in pure Embedded C with direct register access—no external frameworks required.
* **Strict Decoupling:** Every peripheral is isolated into standardized files (`_Interface.h`, `_Config.h`, `_Private.h`, `_Register.h`, `_Program.c`), allowing you to drop any single driver directly into your project.
* **Hardware Verified:** Tested and validated on physical **ATmega32** target hardware as well as Proteus simulation.

<p align="center">
  <img src="media/ldr_adc_demo.gif" alt="LDR ADC Light Monitor Proteus simulation demo" width="1427">
</p>

---

## Architecture Layout

```text
├── LIB/      # Standard data types & bit manipulation macros
├── MCAL/     # Internal ATmega32 peripheral drivers
├── HAL/      # External hardware module drivers
└── APP/      # Ready-to-run system examples & integration tests
