all:
	@avr-gcc -Os  -mmcu=atmega2560 -c main.c -o main.o
	@avr-gcc -mmcu=atmega2560 -o main.elf main.o
	@avr-objcopy -j .text -j .data -O ihex main.elf main.hex
	@avrdude -q -V -p m2560 -D -c atmelice_isp -U flash:w:main.hex
