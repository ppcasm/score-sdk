## MGA BratzLife – Sunplus S+Core SDK Documentation

This document contains **MGA BratzLife** specific documentation for the
Sunplus S+Core (SPG29x) SDK.

It is intended to be **verbose, technical, and practical**, and documents
real-world reverse engineering and tooling that has been developed to enable
homebrew on the MGA BratzLife TV Plug-and-Play game.

---

## Table of Contents

- [Overview](#overview)
- [Hardware Summary](#hardware-summary)
- [Entering Test Menu](#entering-test-menu)
- [Boot Description/System Overview](#boot-description--system-overview))
- [Memory Layout](#memory-layout)
- [Loading Homebrew](#loading-homebrew)
- [Example Projects](#example-projects)
- [System Specific Notes](#system-specific-notes)
- [License](#license)

---

## Overview

The **MGA BratzLife** game is a TV Plug-and-Play game built around a Sunplus SPG29x SoC running
a proprietary firmware.

Originally, the system only supported a single application ran from an internal NAND flash, and included an SD card slot on the front of the console that was unused during regular game play. The system included no official debugging or recovery paths.

Through reverse engineering, the following capabilities have been added
and documented in this SDK:

- Custom code loading from SD cards
- Low-level access to hardware peripherals
- EEPROM savegame modification support

---

## Hardware Summary

- **SoC:** Sunplus SPG291 (S+Core)
- **RAM:** 8MB
- **Storage:** Internal NAND Flash
- **Media:** SD Card (but this was unused in production)
- **I/O:** UART (internal), SD Card, Controller (IR)
- **Audio/Video:** Analog TV output via internal TV encoder

---

## Entering Test Menu

While on the main Bratz intro screen, you press **LEFT, LEFT, RIGHT, RIGHT, UP, DOWN** in that order.

You should then be greeted with a screen that lets you test SD card, controllers, etc.

---

## Boot Description / System Overview

The **MGA BratzLife** game is configured to start booting from a 32MB NAND flash mapped to address **0x9F000000** with entry at **0x9F001000.** At that point after initalizations are complete, the code app then copies a bit out of flash into SDRAM at address **0xA0700000** and this then starts a NAND loader that loads the real game. 

At some point the code checks if an SD card is inserted, and if it is it will do some more checks and attempt to load assets from the SD card under certain conditions.

One of the more **interesting** conditions is that if an SD card is inserted on boot, it will look for a **.ini** file on SD card under **/MGA/Extra.ini** and parse it.

See [Loading Homebrew](#loading-homebrew) for more information.


---

## Memory Layout

Understanding memory layout is **critical**.

### Firmware (When loaded to RAM)

| Item | Address |
|----|--------|
| Load Address | `0xA00001FC` |
| Entry Point | `0xA0001000` |

---

## Loading Homebrew

### Code execution from SD card

As alluded to in the overview section, the game has a hidden **LaunchApp** capability.

**Note:** It's probably best to use older SD cards in order to get this to work. It needs to be formatted in FAT32 (MBR) format and contain a file named **Extra.ini** in **/MGA/Extra.ini** on the SD card. There is an example file that is included in this documents folder in the repo [Extra.ini](/documentation/bratzlife/Extra.ini)

You must make sure that the **GameName** entry exists and has a value set in the ini file, as well as **LaunchApp** with an appropriate path name pointing to a working executable, the SDK will take care of the rest ( see [System Specific Notes](#system-specific-notes) for more information. )

---

## Example Projects

Located under:

[BratzLife Example Projects](../../examples/bratzlife/)

Includes rough demos of things like a homebrew loader, and an EEPROM save editor!

---

## System Specific Notes

### SD card loader

The system includes a hidden SD card loader from the factory. This can be used to actually load game assets from SD card if configured and set up correctly, but more importantly it allows homebrew to be loaded. This works by having a file named **Extra.ini** in **/MGA/Extra.ini** on a properly formatted SD card. The format for the ini file is as follows:

- GameName - Basically the name of the app loaded by LaunchApp (example: payload)
- DiscName - Not needed and seems largely unused. My guess is that it's a test with other medium, or something else
- DiscIdFile - Same info as DiscName.
- LaunchApp - Full patch name of the S+Core payload you wish you execute (example: dev0:MGA\payload.bin)

There exists a bug in the loader. It seems that when they developed the loader they had the loader stored right after the interrupt vector table, which effectively ends at address **0xA0000300.** The loader is actually at address **0xA0000310** but the problem is that when the file pointed to by LaunchApp is read from the SD card, the size is obtained, and the space is allocated, and then the copy function at **0xA0000310** is called.

This means that the loader actually self modifies and corrupts under any circumstance where the loader isn't present at that address. This is because it copies from the source address to **0xA00001FC** and eventually tries to execute at entry address **0xA0001000** which places 0xA0000310 in the line of fire during that copy.

My guess is that they never really noticed it, or didn't care, because any time they uploaded code to test they probably always uploaded code with the same layout that had the loader in that memory range. The SDK remedies this by simply placing the appropriate bytes at that address to recreate the loader so that it doesn't technically corrupt, but simply just writes the same values to the same addresses. This works across all platforms because the linker treats it as a contigious section after the interrupt vector, and so it'll always fall on the same address, and the other interrupt handling code for dispatch, save_regs, etc, will just get moved down.

The plan at some point is to make a loader that let's you choose to launch binaries from a menu system, either an ELF loader, or just a flat loader, but the solution here works in a way that it doesn't have an effect on future applications and interrupts can just always be handled as normal as long as the code remains unchanged in that area after the vector table. 

---
## License

**Free Software, Hell Yeah!**
