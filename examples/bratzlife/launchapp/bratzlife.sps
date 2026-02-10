# Sunplus S+core IDE Project File - Name = "bratzlife"
# Sunplus S+core IDE Generated Build File Format Version V2.6.1
#**DO NOT EDIT**
CFG = Debug

# Begin Project

!IF "$(CFG)" == "bratzlife - Debug"

OutPut Type = elf
OutPut Dir = Debug
Inc Path = ..\..\..\include
Lib Path = 
Compiler = ..\S_CORE~1.1\GNU\bin\gcc
Compiler DefFlag = -mscore7 -mel -g -Wall -nostartfiles
Compiler AddFlag = 
Assembler = ..\S_CORE~1.1\GNU\bin\as
Assembler DefFlag = -Wa,-gdwarf-2  -x assembler-with-cpp
Assembler AddFlag = 
Linker = ..\S_CORE~1.1\GNU\bin\ld
Linker DefFlag = -T$(LDSCRIPT) -lm -lc -lgcc
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
Stack base address = a07ffffc
Pre-Link Description = 
Pre-Link Command = 
Post-Build Description = bratzlife
Post-Build Command = 	copy .\Debug\bratzlife.elf.bin d:\MGA\payload.bin
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
Search Header File = 0
Initial Stop = StartUp
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
Project Path = C:\Users\ppcasm\Documents\score-sdk\examples\bratzlife\launchapp
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
!ELSEIF "$(CFG)" == "bratzlife - Release"

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
Linker DefFlag = -T$(LDSCRIPT) -lm -lc -lgcc
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

# Name "bratzlife - Debug
# Name "bratzlife - Release
# Begin SubItem "bratzlife files"

# Begin Group "Source Files"
#PROP Default_Filter = c;cpp;cc;C;cxx;asm;s;

# Begin Group "cpu"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\src\cpu\change_clk.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=..\..\..\src\cpu\discpu_funcs.s
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "i2c"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\src\i2c\i2c.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "irq"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\src\irq\sys_irq.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=..\..\..\src\irq\sys_isr.s
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "ppu"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\src\ppu\ppu.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "tv"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\src\tv\tv.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "uart"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\src\uart\uart.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "sdcard"
#PROP Default_Filter = *.c

# Begin Source File
SOURCE=..\..\..\src\sdcard\sdcard.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Source File
SOURCE=..\..\..\src\libgloss.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\main.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "Header Files"
#PROP Default_Filter = h;inc;

# Begin Group "cpuH"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\include\cpu\discpu_func.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "i2cH"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\include\i2c\i2c.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "irqH"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\include\irq\interrupts.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "ppuH"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\include\ppu\ppu.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "tvH"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\include\tv\font_8x16.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=..\..\..\include\tv\tv.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "uartH"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\..\include\uart\uart.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "sdcard"
#PROP Default_Filter = *.h

# Begin Source File
SOURCE=..\..\..\include\sdcard\sdcard.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Source File
SOURCE=.\Resource.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\Resource.inc
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=..\..\..\include\score7_constants.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=..\..\..\include\score7_registers.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "Resource Files"
#PROP Default_Filter = rc;

# Begin Source File
SOURCE=.\bratzlife.rc
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "External Dependencies"
#PROP Default_Filter = 

# Begin Source File
SOURCE=.\bratzlife_Prog.ld
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\bratzlife_startup.s
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

# End Group
# End SubItem
# End Project
