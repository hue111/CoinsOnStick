#include "main.h"

int main(){
	uint8_t time = 0;
	uint16_t RxDATA = 19;
	usart2_init();
	delay_init();
	while(1)  
	{  
		RxDATA = USART_ReceiveData(USART2);;
		if(RxDATA != 0){
			printf("%d s\t DATA is\t%d\n",time++,RxDATA);
		}
		else{
			printf("%d s\t NoDATAComeIn!\n",time++);
		}
		delay_ms(1000);
	} 
  
	while(1);
	return 0;
}

int fputc(int ch, FILE *f)
{
	USART_SendData(USART2, (unsigned char) ch);//------------
	while (!USART_GetFlagStatus(USART2, USART_FLAG_TXE) == SET)
		;
	return (ch);
}
