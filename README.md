## Sunplus S+Core SDK

A work-in-progress SDK for **Sunplus SPG29x (S+Core)** based systems, with
support for **Mattel HyperScan**, **MGA BratzLife**, and planned
support for additional SPG29x consoles (e.g. Zone3D).

> ⚠️ **WARNING**
>
> This project is experimental and low-level. It includes tools and examples
> that interact directly with flash memory, bootloaders, and hardware registers.
> **You can permanently brick your hardware if you misuse them.**
>
> You assume all risk for anything you do with the tools and information in this repository.

---

## Table of Contents

- [Overview](#overview)
- [Supported Platforms](#supported-platforms)
- [SDK Features](#sdk-features)
- [SDK Installation](#sdk-installation)
- [Building & Running Examples](#building--running-examples)
- [Platform-Specific Documentation](#platform-specific-documentation)
  - [Mattel HyperScan](documentation/hyperscan/README.md)
  - [MGA BratzLife](documentation/bratzlife/README.md)
- [Starting New Projects](#starting-new-projects)
- [Thanks To](#thanks-to)
- [License](#license)

---

## Overview

This SDK provides a unified development environment for **Sunplus S+Core /
SPG29x** systems. It includes:

- A prepackaged S+Core IDE and toolchain
- Shared low-level hardware libraries
- Platform-specific abstractions
- Example projects for real hardware

The goal is to **centralize S+Core development** while cleanly separating
console specific behavior so new platform support can be added without breaking
existing ones.

---

## Supported Platforms

| Platform | Status | Notes |
|--------|--------|-------|
|  **[Mattel HyperScan](documentation/hyperscan/README.md)** | ✅ Supported | CD, UART, USB booting, custom firmware |
|  **[MGA BratzLife](documentation/hyperscan/README.md)** | ✅ Supported | SD-based loading on unmodified hardware |
| **Zone3D** | ⏳ Planned | Structure in place, support coming later |

---

## SDK Features

### Core (All SPG29x Platforms)

- UART support
- Hardware I2C support
- NOR flash interface
- Custom interrupt handling
- Basic TV encoder / framebuffer support

---

### Platform-Specific Support

These live alongside the core SDK and are **opt-in per platform**. Some examples would be things like:

- Controller inputs
- Console specific peripherals (RFID, LEDs, etc)


---

## SDK Installation

### Supported Host OS

- **Windows** (native)
- **Linux via WINE**

---

### Installing the S+Core IDE

1. Clone this repository
2. Navigate to:

   s-core-sdk/tools/S+core IDE-V2.6.1.exe

3. Install

---

### Python Requirement

Some examples require you to install **Python 3** for post-build tooling.

---

## Building & Running Examples

1. Open the S+Core IDE
2. File → Open Workspace
3. Open an example project
4. Build

---

## Platform-Specific Documentation

---

### Mattel HyperScan
[View full HyperScan documentation →](documentation/hyperscan/)

### HyperScan-Specific Features

- Custom firmware
- UART flash recovery
- USB boot support
- Controller & LED support
- CD loading

---

### MGA BratzLife
[View full BratzLife documentation →](documentation/bratzlife/)

### BratzLife-Specific Features

- SD card code loading
- Works on unmodified hardware

---

## Starting New Projects

The easiest way is to copy an existing example from the appropriate platform folder, rename it, and open the project in the IDE and modify it.

---

## Thanks To

- Bushing - (RIP) He was responsible for the hyperscan firmware being dumped originally, and a good source of valid information
- LiraNuna - Support
- HyperScanDev - Support
- Sunplus -  They actually indirectly provided a lot of information and tools through other S+Core products, and at least made a very good effort to support open-source
- Mattel - I like Barbie
- MGA - I also like Bratz

---

## License

**Free Software, Hell Yeah!**