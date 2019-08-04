# AVR_SDK

This is my concept of AVR programming.

### Supported microcontroller
  atmega2560
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

### Installing

To install it just do

```
cd ~ && git clone https://github.com/Yanujz/AVR_SDK.git
```
## Testing stuff

Now let's check if everything is ok.
```
cd ~/AVR_SDK/examples/basic/blink
make
```
You should have something like this 
```
Compiling file : interrupt.cpp
Compiling file : portmanager.cpp
Compiling file : cppfix.cpp
Compiling file : timer.cpp
Compiling file : spimaster.cpp
Compiling file : spislave.cpp
Compiling file : i2cmaster.cpp
Compiling file : serial.cpp
Compiling file : main.cpp
```
If you have this, everything is ok.

### Uploading sketch
```
cd ~/AVR_SDK/examples/basic/blink
make upload
```
You should have something like this
```
Compiling file : interrupt.cpp
Compiling file : portmanager.cpp
Compiling file : cppfix.cpp
Compiling file : timer.cpp
Compiling file : spimaster.cpp
Compiling file : spislave.cpp
Compiling file : i2cmaster.cpp
Compiling file : serial.cpp
Compiling file : main.cpp

avrdude: AVR device initialized and ready to accept instructions
avrdude: Device signature = 0x1e9801 (probably m2560)
avrdude: reading input file "firmware/main.hex"
avrdude: writing flash (19114 bytes):
avrdude: 19114 bytes of flash written

avrdude: safemode: Fuses OK (E:FD, H:D8, L:FF)

avrdude done.  Thank you.

```
If you have this, everything is ok.

N.B: Default port is /dev/ttyUSB0, you can change parameters in Makefile configuration. All available commands and flags are listed below.

### Makefile usage
```
  Usage:

    make <target> [flags...]

  Targets:

    clean        Remove all build files
    help         Show this help prompt.
    monitor      Open putty with selected port
    ota          Remote upload
    rawMonitor   Open terminal in raw mode
    upload       Local upload

  Flags:

    COM_BAUDRATE      Com Baudrate (default: 1000000)
    COM_PORT          Com Port (default: /dev/ttyUSB0)
    FLASH_BAUDRATE    Flash Baudrate (default: 115200)
    FLASH_PORT        Flash port (default: /dev/ttyUSB0)

  Example:

    make upload FLASH_PORT=/dev/ttyACM0 FLASH_BAUDRATE=115200
    make monitor COM_PORT=/dev/ttyACM0 COM_BAUDRATE=1000000
```
## Authors

* **Yanujz**

