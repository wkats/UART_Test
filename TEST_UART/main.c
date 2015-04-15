#include "uart_rene.h"

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	uart_init();
	char recibido[12]="Recibido: \r\n";
	while(1){
		//uart_printc(uart_getc());
		recibido[9]= uart_getc();
		uart_prints(recibido,sizeof(recibido));
	}

}
