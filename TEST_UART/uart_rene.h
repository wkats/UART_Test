#include<msp430.h>
#include<stdlib.h>
void uart_init(void);
char uart_getc(void);
void uart_printc(char _c);
void uart_prints(char _mensaje[],int _m);
void uart_printl(char _mensaje[], int _m);
