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

**Proceed only if you understand the risks.**

---

## Table of Contents

- [Overview](#overview)
- [Hardware Summary](#hardware-summary)
- [Entering Test Menu](#entering-test-menu)
- [Boot Description/System Overview](#boot-description--system-overview))
- [Memory Layout](#memory-layout)
- [Loading Homebrew](#loading-homebrew)
- [Example Projects](#example-projects)
- [Custom Firmware/Bootloader](#custom-firmware)
- [System Specific Notes](#system-specific-notes)
- [Thanks To](#thanks-to)
- [License](#license)

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

- **SoC:** Sunplus SPG290 (S+Core)
- **RAM:** 16MB
- **Storage:** Internal Parallel NOR Flash
- **Media:** CD-ROM
- **I/O:** USB (host/device), UART (internal), SD Card (internal), Controllers (i2c), LEDs, RFID
- **Audio/Video:** Analog TV output via internal TV encoder

---

## Entering Test Menu

While on the main HyperScan screen, where it says **"Insert Disc"** you start by holding the **LEFT** shoulder button, **START** button, and the **GREEN** button. Then you should see a message that says **"Please Wait"**, and then you press **RED, RED, GREEN, GREEN, YELLOW, BLUE** in that order.

You should then be greeted with a screen that lets you test USB host/device mode, Controllers, etc.

---

## Boot Description / System Overview

The **Mattel HyperScan** is configured to start booting from a 1MB parallel NOR flash mapped to address **0x9F000000**. At that point after initalizations are complete, the main "HyperScan OS" is copied out of NOR flash, and into SDRAM starting at address **0xA00001FC** (interrupt vector) and has its entry at **0xA0001000** (OS entry)

When the HyperScan OS is loaded it will then subsequently load a **HYPER.EXE** file from the root of an inserted CD. This application will load to **0xA00901FC** (non-main interrupt vector, largely unused) and application entry will then happen at **0xA0091000** (APP entry)

The HyperScan OS provides callbacks that provide much of the functions that the HyperScan is capable of doing (RFID, CD, etc) and the SDK does utilize most of these capabilities through callback macros in order to facilitate development how it was decidedly meant to be used on the system.

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

## Loading Homebrew

### CD Based Loading (HYPER.EXE)

This is the original and safest method. See the "CD Development Guide.doc" for instructions on how to burn a **HYPER.EXE** file on to a CD.

The **HYPER.EXE** file must exist on the root of a CD in order for HyperScan OS to load and execute. Anything that loads after that would need to load from that executable.

### UART Based Loading & Recovery

This requires internal soldering to the **TX/RX/GND** labeled pads on the PCB. It also requires either a **HYPER.EXE** based UART loader to be loaded from CD, or the custom firmware/bootloader that allows for recovery (see [FlashRecovery](examples/hyperscan/cd/flashrecovery/) repo code for more details). 

You can find some these tools under the project root in [HyperScan](/tools/hyperscan) and [S+Core](/tools/score7)

The custom recovery is installed from CD, and is under the [FlashRecovery](/hyperscan/cd/flashrecovery/) project in the repo.

Once the custom recovery is installed, if you start the HyperScan with the CD door opened any time afterwards, you'll see all of the LEDs turn on and you can then use the **TX/RX/GND** PCB connections to load a binary to **0xA00001FC** and entry at **0xA0001000**

The idea here is that we treat the start of NOR flash as a "boot block" that never gets touched, and so we can write custom firmwares that will still allow us to recover if an issue arises.

You will see the LEDs "spin" to let you know that your recovery app is uploading. When it's done uploading they will turn off as code execution starts at **0xA0001000**

This will also let you temporarily test CFW modifications by simply uploading the entire CFW at recovery time, before making any permanent changes with [FlashCFW](/examples/hyperscan/recovery/flashcfw)

### USB Based Loading (Custom Firmware)

This requires a FAT32 (MBR) formatted USB with external power. It also requires soldering the UART wires **TX/RX/GND** labeled internally on the PCB, and installing the custom recovery bootloader and then accompanying custom firmware (see project root [CFWPatcher](/tools/hyperscan/CFWPatcher) for more info)

The reason is because it would be hugely unsafe to flash any custom firmware without a way to recover, and the only way to recover without removing and externally fashing is through the custom UART recovery bootloader. 

The idea here is that you install the custom recovery bootloader found in [FlashRecovery](/examples/hyperscan/cd/flashrecovery) which then creates a sort of "boot block" that we never touch, so that we ensure that should we need to recover from a bad CFW, we can.

It is required that you install the custom UART recovery bootloader, and from there you can install custom firmwares (including the one that supports USB booting) using the [CFWPatcher]/tools/hyperscan/CFWPatcher tool to create the CFW, and then flash that CFW binary with the project at [FlashCFW](/examples/hyperscan/recovery/flashcfw)

If everything goes well then you should be able to add a Y-power cable that will provide exernal power to a USB thumb drive, and then build the project at [USBLoader](/examples/hyperscan/usb/usbloader) and save it on the root of the USB drive as **usbload.bin**

By default it will load **usbload.bin** to the address that normal HyperScan load to at **0xA00901FC** and entry at **0xA0091000** but it does support **".ini"** files.

To use the ".ini" support, place **usbload.ini** on root of USB, and the configuration options are as listed:

LOAD_ADDR=<Load_Address>

START_ADDR=<Start_Address>

LOAD_FILE=<Load_Filename>

**Load_Address** is the address to load the binary to (example: 0xA00001FC)

**Start_Address** is the entry point address (example: 0xA0001000)

**Load_Filename** is the file name you want to load (default is usbload.bin, or otherwise specified by LOAD_FILE=<binary_name>)

---

## Example Projects

Located under:

[HyperScan Example Projects](examples/hyperscan/)

Includes rough demos of things like PONG, flash recovery, CFW tools, and even DOOM!

The layout might seem confusing at first, but the examples on HyperScan are categorized by the medium on which they're intended to run. For example "all" means the compiled examples should run from CD, USB, etc. The examples under "cd" should only be ran from CD. Apps ran from under "recovery" should be ran from the optional custom recovery bootloader if you have it installed, and of course the ones under "usb" should be loaded from USB. DOOM is an example of this because the example version uses the USB to store the game and assets (though this might change in the future).

---

## Custom Firmware

Custom firmware adds:
- UART flash rescue
- USB booting
- CFW live testing

---

## System Specific Notes

N/A

---
## License

**Free Software, Hell Yeah!**
