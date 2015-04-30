#include "main.h"


int main(){
	
	usart2_init();//����2��ʼ��
	delay_init();
	
	IIC_Init();
	MPU6050_initialize();
	
	TIM1_Int_Init(65535,36-1);      //��ʱ��1��ʼ��
	TIM3_PWM_Init(CyclePWM,0);      //��ʱ��3��ʼ�� 
	ResetMotorFunction(); 			//�������õ��λ��
	
	while(!MPU6050_testConnection()){
		printf("NO DEVINCE!");
		delay_ms(2000);
	}
	while(1){
		int16_t gyroData[3] = {0};
		int16_t accData[3] = {0};
		MPU6050GyroRead(gyroData);
		printf("GyroData\tX %.2f`\tY %.2f`\tZ %.2f`\t\n",gyroData[0]/16.4,gyroData[1]/16.4,gyroData[2]/16.4);
		delay_ms(50);
		MPU6050AccRead(accData);
		printf("accData\tX %.2fg\tY %.2fg\tZ %.2fg\t\n",accData[0]/4096.0,accData[1]/4096.0,accData[2]/4096.0);
		delay_ms(50);
		
		printf("PUT in the MotorDMXDataControl(such as 55)\n");
		Usart2Received_DMA1start();
		ResetMotorFunction();
		MotorXDmxDataControl(DstBuffer[0], DstBuffer[1]); //��д����Ĵ�����־λ
		
	}
	return 1;
	
	
	
	
	
//	/*�����ڲ�����*/
//	while(1){  
//		printf("\n%d s\t passed!",time++);
//		delay_ms(1000);
//	} 
//	/*�����ɴ��ڽ��ܵ�������*/
//	while(1){
//		Usart2Received_DMA1start();
//		for(loop_i=0;loop_i<8;loop_i++){
//			printf("%c\t",DstBuffer[loop_i]);
//		}
//		delay_ms(1000);
//		printf("\nwait for the next putin :\n");
//	}
	
}


