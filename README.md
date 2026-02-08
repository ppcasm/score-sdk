# Sunplus S+Core SDK
 SPG29x SDK with Mattel HyperScan support

## This is all still very much a work in progress, so it's possibly dangerous.
## I assume no risk for things that you decide to do with the tools and information provided here.  

# Table of Contents (For the Mattel HyperScan)
- [SDK Installation](#sdk-installation)
- [Loading Homebrew](#loading-homebrew)

# Support

HyperScan specific:
- HyperScan custom firmware (adds UART flash rescue and USB booting support)
- HyperScan controller support
- HyperScan LEDs
- USB FAT32 Disk Support (FAT32 formatted as MBR)
- USB Booting (with custom firmware)

SPG29x specific:
- I2C
- UART
- NOR flash interface
- Basic TVE/Framebuffer
- Custom interrupt handling

MGA BratzLife:
- Code loading from SD card on unmodified console, with examples

More will hopefully be added in the future..

# Features

This SDK includes multiple examples for how to interface with the hardware, and most of
the code should be documented. Some examples are as listed:

- [demo] - This shows a very basic controller/framebuffer demo
- [flashrecovery] - This flashes a custom bootloader to allow for CFW/OFW recovery, and live loading of firmware
- [pong] - A very terrible PONG game, I wouldn't use it for production of any kind
- [Flashcfw] - This allows flashing a CFW/OFW permanently from our custom built recovery mode on HyperScan

# SDK Installation
I've included the S+Core IDE in the tools directory. This only works for Windows, but could be installed in WINE under Linux, which was the reason I chose to develop with this method since the S+Core Binutils/GCC hasn't been supported in years it makes trying to track down and build the toolchain from source unnecessary, and a lot more accessible, plus we can ensure that anyone who uses the IDE from this repo will be on the same versions since the back-end of the IDE will be the same Bintuils/GCC.

## Installing the S+Core IDE

Get this repo and navigate to "s-core-sdk\tools\S+core IDE-V2.6.1.exe" and then double click to install.

Done.

Oh, also install python3 because some of the examples use python scripting for some post build process patching, for example with the recovery tools. (be very careful when messing with these things, and know exactly what you're doing, because you can easily brick the HyperScan playing around with the flash)

## Compiling the examples

All of the examples *SHOULD* be documented in the code. The best way to test out the examples is to get this repo, install the IDE, and then go to File->Open Workspace and then navigate to the examples folder and open the desired example folder and select the .spw/.spg file of that example, and everything should load accordingly.

The HyperScan examples provided here will actually produce a HYPER.EXE file by default in the Debug folder of the selected example (ex: /examples/cd/pong/Debug/Hyper.Exe) when compiled. Some projects have other projects embedded into them, and some are made to run from recovery mode instead of as a HyperScan app.

## Considerations
The HYPER.EXE files on HyperScan are loaded to address 0xA00901FC and their entry point is 0xA0091000 and so if you try to
compile an example that is meant to run from recovery/firmware space, you will not get results as the firmware is loaded from NOR flash (or UART for recovery) to 0xA00001FC and entry is at 0xA0001000 on HyperScan. This can be checked by looking at the *.ld file of your current project (ex: hyperscan_Prog.ld) and you'll see for example:

```sh
/* Read-only sections, merged into text segment: */
  . = 0xA0001000;
```

Which tells you that this is built for running in recovery mode, or as a firmware file, as opposed to it saying 0xA0091000 there, which would indicate it's to be ran from CD, or loaded in the HyperScan OS as a HYPER.EXE.

## Starting a new project in the IDE
The examples all link to singular library code source in the repo, under the hyperscan folder. The reason for this is that if there's any updates to the libraries, you can just update from the repo and because everything is pulling from the singular location the changes are reflected when you open any existing example, so then you just recompile and the new code gets applied to the binary. Because of this reason, when starting a new project, the easiest way to do so is to simply copy an example from the example folder, paste it in the example folder, give it a new name, and start the new project there as all of the include and source paths should remain the same and create a uniform structure to the code, and this has the added benefit of making your project be in the examples folder just in case someone wants to send a pull request. :p

It is possible, albeit not as straightforward, to start a completely new project and import the libraries and headers into the IDE. I won't go over how to do this here as this will be very dependent on where exactly in the filepath you pull your libraries, sources, and includes from, as well as there would need to be changes to your startup.s and linkerscripts and various build environment settings to get this working, but just know that it IS possible, just not recommended unless you know what you're doing, because otherwise you will not get the results you're looking for. 

# Loading Homebrew
## Loading Homebrew from CD
#### It's best to use a program like Nero Burning ROM to burn CDs for the Mattel HyperScan.
- Step 1: Go to File->New
- Step 2: Choose CD-ROM(ISO) and No Multisession
- Step 3: Go to the ISO tab and under "File name length" select either ISO Level1 or ISO Level2
- Step 4: Now go to the Format section while still in the ISO tab and select "Mode 1"
- Step 5: Now go to the Character set section while still in the ISO tab and select "ISO9660"
- Step 6: Make sure Joilet is NOT selected and now go to the "Burn" tab and select Finalize CD
- Step 7: Change the "Write method" to "Disc-at-once"
- Step 8: Now you should be able to start a new compilation and you can navigate to your "Hyper.Exe" file and burn it. 

## Loading Homebrew from UART
#### There now exists a way for us to not only debug our apps via UART, but also to load code through it as well, though this requires some very simple soldering skills. 

When you remove the 4 rubber plugs and 4 screws on the CD side of the Mattel HyperScan, you can then take the bottom of the system apart and you'll notice a label on the board that says "RX" and "TX" as well as a few others. What you'll need to do is get a UART cable and solder the "RX" line from your UART cable to the "TX" solder pad on the Mattel HyperScan, and then solder the "TX" line from your UART cable to the "RX" solder pad on the Mattel HyperScan. After that you solder a GND wire to GND. Once this is done you can do the following steps:
- Step 1: 

## Loading Homebrew from USB
We now have the ability to load homebrew through a FAT32 formatted USB drive. The only prerequisite is that you have to provide power to the USB device externally. This is usually achieved through a USB Y-Splitter with one side having the USB drive, and the other side having only power going through an adapter. It's possible to load the USB loader from a CD, but this is cumbersome at best. The custom firmware allows you to not have to use a CD to load the USB loader, and the custom firmware will recognize an inserted USB device on boot with the appropriate file and load the USB loader from there and give you a menu to launch your app using the folder filename that the hyper.exe exists in as the app name. Once this is done, depending on which method you use to load the USB loader, you can then do the following steps:
- Step 1:

# Thanks to
- Bushing - RIP :( He was responsible for the hyperscan.bin firmware file being dumped originally, and a good source of valid information
- LiraNuna - Reverse engineering, and coding, etc
- HyperScanDev - Reverse engineering, Discord moderator, etc
- Sunplus - They actually indirectly provided a lot of information and tools through other S+Core products, and at least made a very good effort to support open-source
- Mattel - I like Barbie
# License

**Free Software, Hell Yeah!**