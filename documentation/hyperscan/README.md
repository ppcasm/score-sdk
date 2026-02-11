## Mattel HyperScan – Sunplus S+Core SDK Documentation

This document contains **Mattel HyperScan** specific documentation for the
Sunplus S+Core (SPG29x) SDK.

It is intended to be **verbose, technical, and practical**, and documents
real-world reverse engineering and tooling that has been developed to enable
homebrew, recovery, and custom firmware on the Mattel HyperScan.

---

## ⚠️ HyperScan-Specific Warning

It is possible under certain circumstances **to permanently brick** the HyperScan if used incorrectly, please **READ** documentation carefully.

This documentation includes information about:

- Flashing NOR firmware
- Overwriting bootloaders
- Running code at fixed physical addresses
- UART-based rescue and recovery

If you write incorrect data to flash, or boot code built for the wrong memory
layout, **you can render the system unbootable**.

Proceed only if you understand the risks.

---

## Overview

The **Mattel HyperScan** is built around a Sunplus SPG29x SoC running
a proprietary firmware.

Originally, the system only supported CD-based applications (`HYPER.EXE`) and included no official debugging or recovery paths.

Through reverse engineering, the following capabilities have been added
and documented in this SDK:

- Custom firmware support
- UART-based flash rescue
- USB-based booting
- Homebrew loading without permanent modification
- Low-level access to hardware peripherals

---

## Hardware Summary

- **SoC:** Sunplus SPG29x (S+Core)
- **Storage:** Internal Parallel NOR Flash
- **Media:** CD-ROM
- **I/O:** USB (host/device), UART (internal), SD Card (internal), controllers (I2C), LEDs, RFID
- **Audio/Video:** Analog TV output via internal TV encoder

---

## Memory Layout

Understanding memory layout is **critical**.

### Application Mode (HYPER.EXE) (CD / HyperScan OS)

| Item | Address |
|----|--------|
| Load Address | `0xA00901FC` |
| Entry Point | `0xA0091000` |

---

### Firmware / Recovery Mode

| Item | Address |
|----|--------|
| Load Address | `0xA00001FC` |
| Entry Point | `0xA0001000` |

---

## Loading Methods

### CD-Based Loading (HYPER.EXE)

This is the original and safest method.

### UART-Based Loading & Recovery

Requires soldering TX/RX/GND to labeled pads on the PCB.

### USB-Based Loading (Custom Firmware)

Requires FAT32 (MBR) USB with external power.

---

## Custom Firmware

Custom firmware adds:
- UART flash rescue
- USB booting
- Recovery tooling

---

## Example Projects

Located under:

```
examples/hyperscan/
```

Includes demos, pong, flash recovery, and CFW tools.

---

## Development Workflow

1. CD loading
2. UART access
3. UART rescue
4. USB loading
5. Firmware flashing (last)

---

## License

**Free Software, Hell Yeah!**
