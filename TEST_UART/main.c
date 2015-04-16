#include "uart_rene.h"
#include<string.h>
void imprimirMenu(void);

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	uart_init();
	char recibido[12]="Recibido: \r\n";
	uart_prints2(recibido,12);
	while(1){
		//uart_printc(uart_getc());
		recibido[9]= uart_getc();
		uart_prints(recibido);
		//uart_prints("Hola mundo\n\r",12);
		//uart_printc("A");
	}
}
void imprimirMenu(void){
	/*uart_prints("Seleccione la Velocidad del Motor: ",sizeof());
	uart_prints("1. Lenta");
	uart_prints("2. Media");
	uart_prints("3. Alta");
	uart_prints("4. Máxima");*/
	return;
}
