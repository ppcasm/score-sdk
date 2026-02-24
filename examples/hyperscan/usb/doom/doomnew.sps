# Sunplus S+core IDE Project File - Name = "doomnew"
# Sunplus S+core IDE Generated Build File Format Version V2.6.1
#**DO NOT EDIT**
CFG = Debug

# Begin Project

!IF "$(CFG)" == "doomnew - Debug"

OutPut Type = elf
OutPut Dir = Debug
Inc Path = ..\..\..\..\include,.\doomgeneric
Lib Path = 
Compiler = ..\S_CORE~1.1\GNU\bin\gcc
Compiler DefFlag = -mscore7 -mel -g -Wall -Os
Compiler AddFlag = -Dhyperscan -Dmax_heap_size=8*(1024*1024)
Assembler = ..\S_CORE~1.1\GNU\bin\as
Assembler DefFlag = -Wa,-gdwarf-2  -x assembler-with-cpp
Assembler AddFlag = 
Linker = ..\S_CORE~1.1\GNU\bin\ld
Linker DefFlag = -T$(LDSCRIPT)   -lm -lc -lgcc
Linker AddFlag = -Wl,-Map,$@.map
RM = ..\S_CORE~1.1\GNU\bin\rm
RM Flag = 
AR = ..\S_CORE~1.1\GNU\bin\ar
AR Flag = 
OBJCOPY = ..\S_CORE~1.1\GNU\bin\objcopy
OBJCOPY Flag = 
OBJDUMP = ..\S_CORE~1.1\GNU\bin\objdump
OBJDUMP FLag = 
IMG2BIN = ..\S_CORE~1.1\GNU\bin\img2bin
IMG2BIN FLag = 
Lik Lib = 
Stack base address = a0f68000
Pre-Link Description = 
Pre-Link Command = 
Post-Build Description = 
Post-Build Command = 	cd ./Debug && move doomnew.elf.bin hyper.Exe	cd ./Debug && move hyper.exe  D:\apps\doom\hyper.exe
Custom Build Enable = 0
WorkDir = 
Custom Build = 
Custom Clean = 
Makefile = 1
SymBol File = 0
Binary File = 1
Dasm File = 0
Resource File = 0
LD File = 0
Use C++ Configuration = 0
Search Header File = 1
Initial Stop = Main
Stop Point = 
Use_DBCT = 0
Remote_Device = COM1
BOOL_CUSTOM_CMD = 0
STR_CUSTOM_CMD = 
Parallel = LPT1
Device = Simulator
TCP_Address = 
TCP_Port = 
Serial_Device = 
Serial_Speed = 
Probe_Speed = LOW
Remote_Manner = Serial
Remote_Manner = 
Enable OSInfo = 0
OSInfo Dll = 
Project Path = C:\Users\ppcasm\Documents\score-sdk\examples\hyperscan\usb\doom
OSInfo INIT = 
Show Cycles = 0
Exception Debug = 0
ROM Debug = 0
Adjust Reloc = 0
Check Sum = 0
ReDownload Data = 0
Class View = 1
Original Path = 
Replaced Path = 
Debug Level = 0
EXCP_ADDR = 0xA0000000
Initial Address = 
Address Check = 0
!ELSEIF "$(CFG)" == "doomnew - Release"

OutPut Type = elf
OutPut Dir = Release
Inc Path = 
Lib Path = 
Compiler = ..\S_CORE~1.1\GNU\bin\gcc
Compiler DefFlag = -mscore7 -mel -O2 -Wall
Compiler AddFlag = 
Assembler = ..\S_CORE~1.1\GNU\bin\as
Assembler DefFlag = -x assembler-with-cpp
Assembler AddFlag = 
Linker = ..\S_CORE~1.1\GNU\bin\ld
Linker DefFlag = -T$(LDSCRIPT)   -lm -lc -lgcc
Linker AddFlag = -Wl,-Map,$@.map
RM = ..\S_CORE~1.1\GNU\bin\rm
RM Flag = 
AR = ..\S_CORE~1.1\GNU\bin\ar
AR Flag = 
OBJCOPY = ..\S_CORE~1.1\GNU\bin\objcopy
OBJCOPY Flag = 
OBJDUMP = ..\S_CORE~1.1\GNU\bin\objdump
OBJDUMP FLag = 
IMG2BIN = ..\S_CORE~1.1\GNU\bin\img2bin
IMG2BIN FLag = 
Lik Lib = 
Stack base address = a0fffffc
Pre-Link Description = 
Pre-Link Command = 
Post-Build Description = 
Post-Build Command = 
Custom Build Enable = 0
WorkDir = 
Custom Build = 
Custom Clean = 
Makefile = 1
SymBol File = 0
Binary File = 0
Dasm File = 0
Resource File = 1
LD File = 1
Use C++ Configuration = 0
Search Header File = 0
Initial Stop = Main
Stop Point = 
Use_DBCT = 0
Remote_Device = COM1
BOOL_CUSTOM_CMD = 0
STR_CUSTOM_CMD = 
Parallel = LPT2
Device = Simulator
TCP_Address = 
TCP_Port = 
Serial_Device = 
Serial_Speed = 
Probe_Speed = LOW
Remote_Manner = Serial
Remote_Manner = 
Enable OSInfo = 0
OSInfo Dll = 
Project Path = 
OSInfo INIT = 
Show Cycles = 0
Exception Debug = 0
ROM Debug = 0
Adjust Reloc = 0
Check Sum = 0
ReDownload Data = 1
Class View = 1
Original Path = 
Replaced Path = 
Debug Level = 0
EXCP_ADDR = 0xA0000000
Initial Address = 
Address Check = 0
!ENDIF

# Name "doomnew - Debug
# Name "doomnew - Release
# Begin SubItem "doomnew files"

# Begin Group "Source Files"
#PROP Default_Filter = c;cpp;cc;C;cxx;asm;s;

# Begin Group "hyperscan"
#PROP Default_Filter = 

# Begin Group "fatfs"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\..\src\hyperscan\fatfs\diskio.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=..\..\..\..\src\hyperscan\fatfs\ff.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "hs_controller"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\..\src\hyperscan\hs_controller\hs_controller.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# End Group
# Begin Group "i2c"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\..\src\i2c\i2c.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "irq"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\..\src\irq\sys_irq.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=..\..\..\..\src\irq\sys_isr.s
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "mp3drv"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\..\src\mp3drv\mp3drv.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "norflash"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\..\src\norflash\norflash.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "tv"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\..\src\tv\tv.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "uart"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\..\src\uart\uart.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "cpu"
#PROP Default_Filter = *.c

# Begin Source File
SOURCE=..\..\..\..\src\cpu\cache.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Source File
SOURCE=.\doomgeneric\am_map.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\d_event.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\d_items.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\d_iwad.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\d_loop.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\d_main.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\d_mode.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\d_net.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\doomdef.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\doomgeneric.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\doomgeneric_hyperscan.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\doomstat.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\dstrings.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\dummy.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\f_finale.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\f_wipe.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\g_game.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\gusconf.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\hu_lib.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\hu_stuff.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\i_endoom.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\i_input.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\i_joystick.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\i_scale.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\i_sound.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\i_system.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\i_timer.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\i_video.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\info.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=..\..\..\..\src\libgloss.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\m_argv.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\m_bbox.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\m_cheat.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\m_config.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\m_controls.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\m_fixed.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\m_menu.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\m_misc.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\m_random.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\memio.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\mus2mid.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\p_ceilng.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\p_doors.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\p_enemy.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\p_floor.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\p_inter.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\p_lights.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\p_map.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\p_maputl.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\p_mobj.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\p_plats.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\p_pspr.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\p_saveg.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\p_setup.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\p_sight.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\p_spec.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\p_switch.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\p_telept.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\p_tick.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\p_user.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\r_bsp.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\r_data.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\r_draw.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\r_main.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\r_plane.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\r_segs.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\r_sky.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\r_things.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\s_sound.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\sha1.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\sounds.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\st_lib.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\st_stuff.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\statdump.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\tables.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\v_video.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\w_checksum.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\w_file.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\w_file_stdc.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\w_main.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\w_wad.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\wi_stuff.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\z_zone.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "Header Files"
#PROP Default_Filter = h;inc;

# Begin Group "hyperscanH"
#PROP Default_Filter = 

# Begin Group "fatfsH"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\..\include\hyperscan\fatfs\diskio.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=..\..\..\..\include\hyperscan\fatfs\ff.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=..\..\..\..\include\hyperscan\fatfs\ffconf.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "hs_controllerH"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\..\include\hyperscan\hs_controller\hs_controller.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# End Group
# Begin Group "i2cH"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\..\include\i2c\i2c.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "irqH"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\..\include\irq\interrupts.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "mp3drvH"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\..\include\mp3drv\mp3.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=..\..\..\..\include\mp3drv\mp3drv.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "norflashH"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\..\include\norflash\norflash.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "tvH"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\..\include\tv\font_8x16.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=..\..\..\..\include\tv\tv.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "uartH"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\..\include\uart\uart.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Source File
SOURCE=.\doomgeneric\am_map.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\config.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\d_englsh.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\d_event.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\d_items.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\d_iwad.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\d_loop.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\d_main.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\d_mode.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\d_player.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\d_textur.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\d_think.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\d_ticcmd.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\deh_main.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\deh_misc.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\deh_str.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\doom.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\doomdata.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\doomdef.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\doomfeatures.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\doomgeneric.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\doomkeys.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\doomstat.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\doomtype.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\dstrings.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\f_finale.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\f_wipe.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\g_game.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\gusconf.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\hu_lib.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\hu_stuff.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\i_cdmus.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\i_endoom.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\i_joystick.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\i_scale.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\i_sound.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\i_swap.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\i_system.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\i_timer.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\i_video.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\info.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\inttypes.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\m_argv.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\m_bbox.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\m_cheat.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\m_config.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\m_controls.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\m_fixed.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\m_menu.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\m_misc.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\m_random.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\memio.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\mus2mid.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\net_client.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\net_dedicated.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\net_defs.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\net_gui.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\net_io.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\net_loop.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\net_packet.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\net_query.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\net_sdl.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\net_server.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\p_inter.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\p_local.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\p_mobj.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\p_pspr.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\p_saveg.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\p_setup.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\p_spec.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\p_tick.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\r_bsp.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\r_data.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\r_defs.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\r_draw.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\r_local.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\r_main.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\r_plane.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\r_segs.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\r_sky.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\r_state.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\r_things.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\s_sound.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=..\..\..\..\include\score7_constants.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=..\..\..\..\include\score7_registers.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\sha1.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\sounds.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\st_lib.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\st_stuff.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\statdump.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\stdint.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\tables.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\v_patch.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\v_video.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\w_checksum.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\w_file.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\w_main.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\w_merge.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\w_wad.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\wi_stuff.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric\z_zone.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "Resource Files"
#PROP Default_Filter = rc;

# Begin Source File
SOURCE=.\doomnew.rc
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "External Dependencies"
#PROP Default_Filter = 

# Begin Source File
SOURCE=.\doomnew_Prog.ld
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomnew_startup.s
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\Makefile
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "External Headers"
#PROP Default_Filter = h;

# Begin Source File
SOURCE=.\doomgeneric\strings.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# End SubItem
# End Project
