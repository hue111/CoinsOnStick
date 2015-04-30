#ifndef __MOTOT_H
#define __MOTOT_H
#include "stm32f30x.h"

//-----------------------------------------------------------------------------
#define YES                 1
#define NO                  0
#define StartPostion        1024                //512/4=128
#define MaxStep             16   //1.8°          //最大步数
#define MAXMOTORSPEED       390  //380           //最大步进电机速度

extern uint16_t TIM1CCR3_Val;

//-----------------------------------------------------------------------------
//步进电机开始位置
void MotorXDmxDataControl(uint8_t Dmxdata,uint8_t Finedata);
void ResetMotorFunction(void); //重新设置电机位置
static void Motor1WaitProgram(void);
static uint8_t CheckValChange1(int32_t Val);
static uint8_t CheckValChange2(int32_t Val);
static void Motor1_postion_control(int32_t postion);

void MotorXDriveInTimer(void);
static void Motor1PostionControlSpeed(void);
static void Motor1_drive(uint8_t dir,uint16_t SpeedPostion);    //STEP  步进电机步数  200步 为一圈
static uint8_t CheckValChange3(int32_t Val);
static void Motor1DynamicPostionGap(void);
static void Motor1PointerControl(void);

//-----------------------------------------------------------------------------
#endif
