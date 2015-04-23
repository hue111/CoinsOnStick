#include "main.h"

int main(){
	uint8_t time = 0;
	uint8_t loop_i = 0;
	usart2_init();
	delay_init();
	
	
	 //发送内部数据
	while(1){  
		printf("\n%d s\t passed!",time++);
		delay_ms(1000);
	} 
	 //处理由串口接受到的数据
	while(1){
		Usart2Received_DMA1start();
		for(loop_i=0;loop_i<8;loop_i++){
			printf("%c\t",DstBuffer[loop_i]);
		}
		delay_ms(1000);
		printf("\nwait for the next putin :\n");
	}
	while(1){}
	return 0;
}

int fputc(int ch, FILE *f)
{
	USART_SendData(USART2, (unsigned char) ch);//------------
	while (!USART_GetFlagStatus(USART2, USART_FLAG_TXE) == SET)
		;
	return (ch);
}
