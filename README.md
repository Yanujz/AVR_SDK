# AVR_SDK

This is my concept of AVR programming.

### Supported microcontroller
  atmega2560 atmega328p
### Supported boards
Arduino mega R3
Arduino uno R3
  
#
In future others boards will be supported.
These libraries are shared as is, without any warranty.

## Getting Started
### Prerequisites

First of all install some dependencies:

#### Ubuntu 18.04.1 LTS
```
sudo apt install libftdi1 libusb-0.1-4 binutils-avr gcc-avr avr-libc avrdude
```

#### Fedora 30
```
sudo dnf install libftdi libusb avr-binutils gcc-avr avr-libc avrdude avr-gcc-c++
```
#### Arch Linux
```
sudo pacman -S libftdi libusb-compat avr-binutils avr-gcc avr-libc avrdude
```

### Installing

To install it just do

```
cd ~ && git clone https://github.com/Yanujz/AVR_SDK.git
```
## Building libs for MCU
You'll need to build libraries for each microcontroller you use. (change mcu to any supported mcu)

```
cd ~/AVR_SDK/libs && make atmega2560

```

## Testing stuff

Now let's check if everything is ok. (change mcu to any supported mcu)
```
cd ~/AVR_SDK/examples/basic/blink
make atmega2560
```
You should have something like this 
```
Compiling file : main.cpp

AVR Memory Usage
----------------
Device: atmega2560

Program:     286 bytes (0.1% Full)
(.text + .data + .bootloader)

Data:          0 bytes (0.0% Full)
(.data + .bss + .noinit)
```
If you have this, everything is ok.

### Uploading sketch
Now let's upload the firmware. (change mcu to any supported mcu)
```
cd ~/AVR_SDK/examples/basic/blink
make atmega2560_upload
```
You should have something like this
```
avrdude: Version 6.3
         Copyright (c) 2000-2005 Brian Dean, http://www.bdmicro.com/
         Copyright (c) 2007-2014 Joerg Wunsch

         System wide configuration file is "/etc/avrdude.conf"
         User configuration file is "/home/zetes/.avrduderc"
         User configuration file does not exist or is not a regular file, skipping

         Using Port                    : /dev/ttyACM0
         Using Programmer              : stk500v2
         Overriding Baud Rate          : 115200
         AVR Part                      : ATmega2560
         Chip Erase delay              : 9000 us
         PAGEL                         : PD7
         BS2                           : PA0
         RESET disposition             : dedicated
         RETRY pulse                   : SCK
         serial program mode           : yes
         parallel program mode         : yes
         Timeout                       : 200
         StabDelay                     : 100
         CmdexeDelay                   : 25
         SyncLoops                     : 32
         ByteDelay                     : 0
         PollIndex                     : 3
         PollValue                     : 0x53
         Memory Detail                 :

                                  Block Poll               Page                       Polled
           Memory Type Mode Delay Size  Indx Paged  Size   Size #Pages MinW  MaxW   ReadBack
           ----------- ---- ----- ----- ---- ------ ------ ---- ------ ----- ----- ---------
           eeprom        65    10     8    0 no       4096    8      0  9000  9000 0x00 0x00
           flash         65    10   256    0 yes    262144  256   1024  4500  4500 0x00 0x00
           lfuse          0     0     0    0 no          1    0      0  9000  9000 0x00 0x00
           hfuse          0     0     0    0 no          1    0      0  9000  9000 0x00 0x00
           efuse          0     0     0    0 no          1    0      0  9000  9000 0x00 0x00
           lock           0     0     0    0 no          1    0      0  9000  9000 0x00 0x00
           calibration    0     0     0    0 no          1    0      0     0     0 0x00 0x00
           signature      0     0     0    0 no          3    0      0     0     0 0x00 0x00

         Programmer Type : STK500V2
         Description     : Atmel STK500 Version 2.x firmware
         Programmer Model: AVRISP
         Hardware Version: 15
         Firmware Version Master : 2.10
         Vtarget         : 0.0 V
         SCK period      : 0.1 us

avrdude: AVR device initialized and ready to accept instructions
avrdude: Device signature = 0x1e9801 (probably m2560)
avrdude: safemode: hfuse reads as D8
avrdude: safemode: efuse reads as FD
avrdude: reading input file "build/firmware/main.hex"
avrdude: writing flash (286 bytes):
avrdude: 286 bytes of flash written
avrdude: verifying flash memory against build/firmware/main.hex:
avrdude: load data flash data from input file build/firmware/main.hex:
avrdude: input file build/firmware/main.hex contains 286 bytes
avrdude: reading on-chip flash data:
avrdude: verifying ...
avrdude: 286 bytes of flash verified

avrdude: safemode: hfuse reads as D8
avrdude: safemode: efuse reads as FD
avrdude: safemode: Fuses OK (E:FD, H:D8, L:FF)

avrdude done.  Thank you.

```
If you have this, everything is ok.

N.B: If upload command fails you may change default port into makefile or set global variable in command line. Please use "make help" command to get more information about this.

### Makefile usage
```
  Usage:

    make <target> [flags...]

  Targets:

    all                   Default target. (default atmega2560)
    atmega2560_buildlib   Build libraries for atmega2560.
    atmega2560            Compile for atmega2560.
    atmega2560_upload     Upload to an atmega2560 target. (FLASH_PORT = /dev/ttyACM0, FLASH_BAUDRATE = 115200)
    atmega328p_buildlib   Build libraries for atmega328p.
    atmega328p            Compile for atmega328p.
    atmega328p_upload     Upload to an atmega328p target. (FLASH_PORT = /dev/ttyUSB0, FLASH_BAUDRATE = 115200)
    clean                 Remove all build files
    help                  Show this help prompt.
    monitor               Open putty with selected port
    rawMonitor            Open terminal in raw mode. (Must be installed)
    size                  Show Memory Usage

  Flags:

    COM_BAUDRATE      Com Baudrate (default: 1000000)
    COM_PORT          Com Port (default: /dev/ttyUSB0)
    FLASH_BAUDRATE    Flash Baudrate (default: 115200)
    FLASH_PORT        Flash port (default: /dev/ttyUSB0)

  Example:

    make atmega2560
    make atmega2560_upload FLASH_PORT=/dev/ttyACM0 FLASH_BAUDRATE=115200
    make monitor COM_PORT=/dev/ttyACM0 COM_BAUDRATE=1000000

```
## Authors

* **Yanujz**

