#ifndef SERIAL_H
#define SERIAL_H
void uart_init(int baud);
void printStr(char *str);
void printChar(char ch);
char uartReceive(void);
char uart_isAvailable(void);
#endif
