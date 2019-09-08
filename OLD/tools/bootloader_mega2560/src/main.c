#include <avr/boot.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/iom2560.h>
/*
No. of Words in a Page and No. of Pages in the Flash
+------------------------+-----------+---------+--------------+----------+-------+
|       Flash Size       | Page Size | PCWORD  | No. of Pages |  PCPAGE  | PCMSB |
+------------------------+-----------+---------+--------------+----------+-------+
| 128K words (256Kbytes) | 128 words | PC[6:0] |         1024 | PC[16:7] |    16 |
+------------------------+-----------+---------+--------------+----------+-------+

128*16								= 2048 bits
2048*1024					= 2097152 bits
2097152/8					= 262144 Bytes
262144 / 1024 = 256 kBytes



+-------------+-----------+----------+--------------+-----------+--------+
| EEPROM Size | Page Size |  PCWORD  | No. of Pages |  PCPAGE   | EEAMSB |
+-------------+-----------+----------+--------------+-----------+--------+
| 4Kbytes     | 8 bytes   | EEA[2:0] |          512 | EEA[11:3] |     11 |
+-------------+-----------+----------+--------------+-----------+--------+

*/

/*

#if 0 //blink and send char 'B' uart 0
uint8_t page0[16*16] = {
	0x0c, 0x94, 0x72, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x11, 0x24, 0x1f, 0xbe, 0xcf, 0xef, 0xd1, 0xe2, 0xde, 0xbf, 0xcd, 0xbf,
	0x00, 0xe0, 0x0c, 0xbf, 0x0e, 0x94, 0x87, 0x00, 0x0c, 0x94, 0xa4, 0x00, 0x0c, 0x94, 0x00, 0x00,
};
uint8_t page1[16*16] = {
	0x90, 0x91, 0xc0, 0x00, 0x95, 0xff, 0xfc, 0xcf, 0x80, 0x93, 0xc6, 0x00, 0x08, 0x95, 0x80, 0xe8,
	0x84, 0xb9, 0x10, 0x92, 0xc5, 0x00, 0x88, 0xe0, 0x80, 0x93, 0xc4, 0x00, 0x88, 0xe1, 0x80, 0x93,
	0xc1, 0x00, 0x86, 0xe0, 0x80, 0x93, 0xc2, 0x00, 0x85, 0xb1, 0x80, 0x58, 0x85, 0xb9, 0x82, 0xe4,
	0x0e, 0x94, 0x80, 0x00, 0x2f, 0xef, 0x83, 0xed, 0x90, 0xe3, 0x21, 0x50, 0x80, 0x40, 0x90, 0x40,
	0xe1, 0xf7, 0x00, 0xc0, 0x00, 0x00, 0xf0, 0xcf, 0xf8, 0x94, 0xff, 0xcf, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
};
#endif




#if 0 // blink
uint8_t page0[16*16]={
	0x0c, 0x94, 0x72, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e ,0x00,
	0x0c, 0x94, 0x7e,	0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x11, 0x24, 0x1f, 0xbe, 0xcf, 0xef, 0xd1, 0xe2, 0xde, 0xbf, 0xcd, 0xbf,
	0x00, 0xe0, 0x0c, 0xbf, 0x0e, 0x94, 0x80, 0x00, 0x0c, 0x94, 0x8f, 0x00, 0x0c, 0x94, 0x00, 0x00,
};
uint8_t page1[16*16] = {
	0x80, 0xe8, 0x84, 0xb9, 0x85, 0xb1, 0x80, 0x58, 0x85, 0xb9, 0x2f, 0xef, 0x83, 0xed, 0x90, 0xe3,
	0x21, 0x50, 0x80, 0x40, 0x90, 0x40, 0xe1, 0xf7, 0x00, 0xc0, 0x00, 0x00, 0xf3, 0xcf, 0xf8, 0x94,
	0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
};
#endif

#if 0
unsigned char page0[16*16] = {
	0x0c, 0x94, 0x72, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,	0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94,	0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94,	0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00,	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94,	0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94,	0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,	0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94,	0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94,	0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00,	0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94,	0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00, 0x0c, 0x94, 0x7e, 0x00,
	0x0c, 0x94, 0x7e, 0x00, 0x11, 0x24, 0x1f, 0xbe, 0xcf, 0xef, 0xd1, 0xe2, 0xde, 0xbf, 0x0c, 0x94,
	0x7e, 0x00, 0x11, 0x24, 0x1f, 0xbe, 0xcf, 0xef, 0xd1, 0xe2, 0xde, 0xbf, 0xcd, 0xbf, 0x00, 0xe0
};
uint8_t page1[16*16]={
	0x0c, 0xbf, 0x0e, 0x94, 0x80, 0x00, 0x0c, 0x94, 0x9c, 0x00,	0x0c, 0x94, 0x00, 0x00, 0x10, 0x92,
	0xc5, 0x00, 0x88, 0xe0, 0x80, 0x93, 0xc4, 0x00,	0x88, 0xe1, 0x80, 0x93, 0xc1, 0x00, 0x86, 0xe0,
	0x80, 0x93, 0xc2, 0x00, 0x82, 0xe4,	0x90, 0x91, 0xc0, 0x00, 0x95, 0xff, 0xfc, 0xcf, 0x80, 0x93,
	0xc6, 0x00, 0x2f, 0xef,	0x34, 0xe3, 0x9c, 0xe0, 0x21, 0x50, 0x30, 0x40, 0x90, 0x40, 0xe1, 0xf7,
	0x00, 0xc0,	0x00, 0x00, 0xf0, 0xcf, 0xf8, 0x94, 0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
#endif
#if 0
uint8_t prog[] = {
	0x0C,0x94,0x46,0x00,0x0C,0x94,0x50,0x00,0x0C,0x94,0x50,0x00,0x0C,0x94,0x50,0x00, // 16 bytes
	0x0C,0x94,0x50,0x00,0x0C,0x94,0x50,0x00,0x0C,0x94,0x50,0x00,0x0C,0x94,0x50,0x00,
	0x0C,0x94,0x50,0x00,0x0C,0x94,0x50,0x00,0x0C,0x94,0x50,0x00,0x0C,0x94,0x50,0x00,
	0x0C,0x94,0x50,0x00,0x0C,0x94,0x50,0x00,0x0C,0x94,0x50,0x00,0x0C,0x94,0x50,0x00,
	0x0C,0x94,0x50,0x00,0x0C,0x94,0x50,0x00,0x0C,0x94,0x50,0x00,0x0C,0x94,0x50,0x00,
	0x0C,0x94,0x50,0x00,0x0C,0x94,0x50,0x00,0x0C,0x94,0x50,0x00,0x0C,0x94,0x50,0x00,
	0x0C,0x94,0x50,0x00,0x0C,0x94,0x50,0x00,0x0C,0x94,0x50,0x00,0x0C,0x94,0x50,0x00,
	0x0C,0x94,0x50,0x00,0x0C,0x94,0x50,0x00,0x0C,0x94,0x50,0x00,0x0C,0x94,0x50,0x00, //128

	0x0C,0x94,0x50,0x00,0x0C,0x94,0x50,0x00,0x0C,0x94,0x50,0x00,0x11,0x24,0x1F,0xBE,
	0xCF,0xEF,0xD0,0xE4,0xDE,0xBF,0xCD,0xBF,0x0E,0x94,0x52,0x00,0x0C,0x94,0x65,0x00,
	0x0C,0x94,0x00,0x00,0x54,0x9A,0x5C,0x9A,0x8F,0xE0,0x97,0xE2,0x01,0x97,0xF1,0xF7,
	0x00,0xC0,0x00,0x00,0x5C,0x98,0x9F,0xEF,0x29,0xE6,0x88,0xE1,0x91,0x50,0x20,0x40,
	0x80,0x40,0xE1,0xF7,0x00,0xC0,0x00,0x00,0xEE,0xCF,0xF8,0x94,0xFF,0xCF,0xFF,0xFF,
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
};
#endif
*/


#define ACK 255
#define PAGE_REQ 254
#define WRITE_FLASH 253
#define READ_FLASH 252
#define ACK_W_FLASH 251
#define ACK_R_FLASH 250
#define END_W_FLASH 249
#define PAGES_TOO_BIG 248
#define END_PAGE 247
#define REQ_NEW_PAGE 246
#define MAX_PAGES 992

void boot_program_page (uint32_t page, uint8_t *buf)
{
	uint16_t i;
	uint8_t sreg;
	char buff[64];
	// Disable interrupts.

	sreg = SREG;
	cli();

	eeprom_busy_wait ();

	boot_page_erase (page);
	boot_spm_busy_wait ();      // Wait until the memory is erased.

	for (i=0; i<SPM_PAGESIZE; i+=2)
	{

		// Set up little-endian word.

		uint16_t w = *buf++;
		w |= (*buf++) << 8;
		//sprintf(buff,"Filling with %04x\r\n",w);
		//printStr(buff);
		boot_page_fill (page + i, w);
		//	_delay_ms(250);
	}

	boot_page_write (page);     // Store buffer in flash page.
	boot_spm_busy_wait();       // Wait until the memory is written.

	// Reenable RWW-section again. We need this if we want to jump back
	// to the application after bootloading.

	//boot_rww_enable ();

	// Re-enable interrupts (if they were ever enabled).
	SREG = sreg;
}

uint8_t page[SPM_PAGESIZE];
uint16_t counter = 0;
//extern void uartinit(int baud);
//#define MYUBRR(x) (F_CPU/16/(float)x-1)
void uartinit()
{
	UBRR0H = 0;
	UBRR0L = 8;
	// Enable receiver and transmitter //
	UCSR0B = (1<<RXEN0)|(1<<TXEN0)| (0 << RXCIE0);
	// Set frame format: 8data, 1stop bit //
	UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);


}


void printChar(char ch)
{
	while ( !( UCSR0A & (1<<UDRE0)) );
	UDR0 = ch;
}

void printStr(char *str)
{
	register uint8_t i = 0;
	while (str[i]) {
		printChar(str[i]);
		++i;
	}
}

uint8_t uartReceive()
{
	while (!(UCSR0A & (1<<RXC0)));
	return UDR0;
}

char isAvailable()
{
	return (UCSR0A & (1<<RXC0))>>RXC0; // Return true means is available
}

void serialFlush()
{
	uint8_t dummy;
	while(UCSR0A & (1<<RXC0))
		dummy = UDR0;
}

void programmingMode(){
	serialFlush();
	printChar(PAGE_REQ);
	uint16_t pages = uartReceive();
	if (pages > MAX_PAGES){
		printChar(PAGES_TOO_BIG);
		return;
	}
	printChar(ACK);
	printChar(pages);

	//volatile uint8_t temp;
	PORTB=0x80;

	for (uint16_t j = 0; j < pages; ++j) {
		printChar(REQ_NEW_PAGE);
		while (1) {

			while((UCSR0A & (1<<RXC0))>>RXC0){ // uart available
				while (!(UCSR0A & (1<<RXC0)));
				page[counter] = UDR0;
				asm volatile("nop");
				UDR0 = page[counter];
				//PORTB^=0x80;
				//temp = (*(volatile uint8_t *)(0XC6));

				//counter++;
				if(++counter == SPM_PAGESIZE){
					PORTB=0x00;
					printChar(END_PAGE);
					counter = 0;
					goto END;
					//break;
				}
			}
		}
END:
		//printChar(END_PAGE);
		boot_program_page( j*SPM_PAGESIZE, page);
	}
	printChar(END_W_FLASH);
	boot_rww_enable ();
	asm("jmp 0x0000");
}


int main(){
	_delay_ms(1);
	DDRB = 0x80;

	uint16_t ntry = 0;
	uint8_t tmp = 0;
	uint16_t i = 0;
	UBRR0H = 0;
	UBRR0L = 0;
	// Enable receiver and transmitter //
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	// Set frame format: 8data, 1stop bit //
	UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
	//	UBRR0H = 0;
	//	UBRR0L = 8;
	//	// Enable receiver and transmitter //
	//	UCSR0B |= (1<<RXEN0)|(1<<TXEN0)| (1 << RXCIE0);
	//	// Set frame format: 8data, 1stop bit //
	//	UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);

	//sei();


	char buff[50];
	//sprintf(buff,"SPM Pagesize: %d\r\n",SPM_PAGESIZE);
	//	Serial *serial0 = SerialManager::getInstance(SERIAL0);

	//	serial0->init(BAUD_1000000);
	//	//
	//	//
	//sei();
	//printStr("\e[1;1H\e[2J");
	//printStr("ciao dal bootloader\r\n");
	//printStr(buff);

	//printStr("Loading program\r\n");
	//boot_program_page( 0, page0);
	//boot_program_page( 256, page1);
	//printStr("Program loaded\r\n");
	//printStr("ciao dal bootloader\r\n");
	//while (ntry != 65535) {
	PORTB ^= 0x80;
	while((UCSR0A & (1<<RXC0))>>RXC0){ // uart available
		tmp = uartReceive();

		if(tmp == WRITE_FLASH){
			printChar(ACK_W_FLASH);
			programmingMode();
			//boot_rww_enable ();
		}
	}
	//++ntry;
	//printChar('a');
	//_delay_us(1);
	//}
	//printChar(253);
	//_delay_ms(2000);
	//}
	for (int i = 0;i <10;++i) {
		sprintf(buff,"Jumping to firmware %d\r\n",  i);
		printStr(buff);
		_delay_ms(250);
	}
	//_delay_ms(5000);
	//start at flash_start = 0x0000
	//boot_spm_busy_wait();
	//start the actual program
	//boot_rww_enable();				// enable application section
	//	printStr("Jumping to firmware\r\n");

	asm("jmp 0x0000");
}



