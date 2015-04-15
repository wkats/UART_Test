#include "uart_rene.h"
char _cR;
int _max;
char *mensaje;
unsigned int iMsj=0;

void uart_init(void){
	  DCOCTL=0;
	  BCSCTL1 = CALBC1_1MHZ;                    // Set DCO
	  DCOCTL = CALDCO_1MHZ;

	  P1SEL = BIT1 + BIT2 ;                     // P1.1 = RXD, P1.2=TXD
	  P1SEL2 = BIT1 + BIT2 ;                    // P1.1 = RXD, P1.2=TXD

		UCA0CTL1 = UCSWRST;
		UCA0CTL1 |= UCSSEL_2;
		UCA0MCTL |= UCBRS0;
		UCA0BR0=104;
		UCA0BR1=0;
		UCA0CTL1 &= ~UCSWRST;
		IFG2 = 00;
		__enable_interrupt();
}

char uart_getc(void){
	_cR=NULL;
	IE2|=UCA0RXIE;
	while(_cR==NULL);
	return _cR;

}
void uart_printc(char _c){
	mensaje=&_c;
	_max=1;
	IE2|=UCA0TXIE;

}
void uart_prints(char _mensaje[], int _m){
	mensaje=_mensaje;
	_max=_m;
	iMsj=0;
	IE2|=UCA0TXIE;
	UCA0TXBUF=mensaje[iMsj++];
	uart_printc('\r');
	uart_printc('\n');

}
void uart_printl(char _mensaje[], int _m){
	mensaje=_mensaje;
	_max=_m;
	iMsj=0;
	IE2|=UCA0TXIE;
	UCA0TXBUF=mensaje[iMsj++];
	uart_printc('\r');
	uart_printc('\n');

}
#pragma vector=USCIAB0RX_VECTOR
__interrupt void recep_isr(void){
	_cR=UCA0RXBUF;
	IE2&=~UCA0RXIE;
	IFG2&=~UCA0RXIFG;
}

#pragma vector=USCIAB0TX_VECTOR
__interrupt void transm_isr(void){
	UCA0TXBUF=mensaje[iMsj++];
		if(iMsj==_max){
			iMsj=0;
			IE2&=~UCA0TXIE;
		}
}
