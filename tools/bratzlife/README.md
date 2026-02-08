\# MGA BratzLife (Sunplus S+Core SPG291)



\## Overview



\*\*MGA BratzLife\*\* is a mid-2000s handheld game device produced by \*\*MGA Entertainment\*\*, built around a \*\*Sunplus SPG291 (S+Core) system-on-chip\*\* and a custom proprietary firmware stack.



Although the device was shipped as a closed consumer product, and by default all system firmware is loaded from NAND, reverse-engineering has revealed that the stock firmware includes a \*\*fully functional, INI-driven application loader\*\* capable of loading and executing external binaries directly from an SD card. This loader is not exposed in the normal user interface and appears to be a leftover internal development or expansion mechanism.



Notably, the SD card slot is otherwise unused in retail gameplay. Evidence suggests it may have been intended for:

\- downloadable content or add-ons

\- save data

\- manufacturing or service tools

\- firmware updates



Ultimately, none of these features were enabled in production, but the loader logic remains intact.



---



\### Entering the "Test Menu"



There exists a test menu built into the MGA BratzLife firmware. At the title screen, press the following:



&nbsp;- \*\*Left, Left, Right, Right, Up, Down\*\* 



At that point you should see the test menu appear and it will let you select from the options



---



\## Hardware Specifications



\### CPU / Core

\- \*\*SoC:\*\* Sunplus SPG291

\- \*\*Endianness:\*\* Little-endian



\### Memory

\- \*\*Internal RAM:\*\* 8 MB



\### Storage

\- \*\*Primary Firmware:\*\* NAND flash

\- \*\*External Storage:\*\*

&nbsp; - SD card (used by the hidden loader)

&nbsp; - I²C EEPROM (bit-banged, used for configuration / IDs)



---



\## SD Card \& Filesystem



Older, low-capacity SD cards are recommended. Newer SDHC cards may work but are not guaranteed. A standard MBR FAT16/32 filesystem should work.



---



\## Hidden Loader Mechanism



During early boot, the firmware performs the following:



1\. Initializes the SD card controller and checks if an SD card is inserted

2\. Mounts the FAT filesystem

3\. Checks for the file:

&nbsp;  

&nbsp;  ```

&nbsp;  dev0:\\MGA\\Extra.ini

&nbsp;  ```



4\. If present, parses configuration values

5\. Optionally loads and executes an external binary



This mechanism is fully implemented in retail firmware.



---



\## `Extra.ini` Format



The loader expects a standard INI-style file with a section named `\[Extra]`.



Example:



```

\[Extra]

GameName=TESTGAME

DiscName=TESTDISC

DiscIdFile=MGA\\disc.id

LaunchApp=MGA\\payload.bin

```



\### Fields



\- \*\*GameName\*\*  

&nbsp; Displayed in error prompts if the SD card is removed before execution.



\- \*\*DiscName\*\*  

&nbsp; Secondary identifier used by the firmware UI.



\- \*\*DiscIdFile\*\*  

&nbsp; Optional ID file used by internal checks.



\- \*\*LaunchApp\*\*  

&nbsp; Path to the S+Core binary payload to load and execute.



---



\## Binary Payload Format



The binary referenced by `LaunchApp` must begin with a small header:



| Offset | Size | Description |

|------:|-----:|------------|

| 0x00 | u32 | Payload size (bytes, little-endian) |

| 0x04 | u32 | User-defined (usually 0) |

| 0x08 | u32 | Reserved (0) |

| 0x0C | u32 | Reserved (0) |

| 0x10 | ... | Raw S+Core binary payload |



\### Load Behavior



\- Payload is copied to \*\*0xA00001FC\*\*

\- This is the start of the S+Core interrupt vector table

\- Execution begins at \*\*0xA0001000\*\*



This matches standard Sunplus S+Core application layout.



---



\## Status



\- Loader confirmed present in retail firmware

\- SD card access functional

\- Arbitrary code execution achievable without exploiting memory corruption



---



\## Disclaimer



This project is for \*\*educational and preservation purposes only\*\*.





