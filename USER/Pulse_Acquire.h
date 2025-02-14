/*********************************************************************************************************
//概述：
//作者：随风飘跃    时间：       地点：
//CPU型号：         系统主频：
//版本号：V0.0        
*********************************************************************************************************/

#ifndef __PULSE_ACQUIRE_H__
#define __PULSE_ACQUIRE_H__
/*********************************************************************************************************
文件包含区
*********************************************************************************************************/
#include "include.h"
/*********************************************************************************************************
宏定义区
*********************************************************************************************************/
#define  PULSE_RATIO      100   //1吨 脉冲的数量
/*********************************************************************************************************
数据类型定义
*********************************************************************************************************/

union flow_union                                            //水量共用体类型
{
  unsigned long   flow32;
  unsigned char flow8[4];
}; 

enum Cal_State_En//霍尔状态表
{
  CAL1,
  CAL2
};

struct Get_Cal_Str
{
  union flow_union Water_Data;
  enum Cal_State_En Cal_State;
};
/*********************************************************************************************************
外部变量声明区
*********************************************************************************************************/
extern NEAR  struct Get_Cal_Str Cal;
/*********************************************************************************************************
函数声明区
*********************************************************************************************************/
void Pulse_Acquire_Config(void);
void ExtiD_Interrupt (void);                        //外中断D
void Exti0_Interrupt (void);
/********************************************************************************************************/
#endif

/******************************************END********************************************************/
