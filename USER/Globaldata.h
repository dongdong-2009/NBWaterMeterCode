#ifndef __GLOBALDATA_H__
#define __GLOBALDATA_H__
/*********************************************************************************
文件包含区
*********************************************************************************/
#include "stm8l15x.h"
/*********************************************************************************
常量定义区
*********************************************************************************/
/*********************************************************************************
公共变量定义区
*********************************************************************************/
extern u8 Device_Status;            //设备状态
extern signed char Temp;                     //设备温度
extern u16 BAT_Vol;                     //电池实时电压
extern u16 BAT_Alarm_Vol;           //电池告警电压
extern u8 Settle_Date;          //结算日期
extern RTC_TimeTypeDef Settlement_Time;          //日结算时间
extern u16 Report_Cycle;             //上报周期，时
extern u32 Report_Cycle_counter;     //上报周期计数，秒
extern u8 Gather_Cycle_counter;     //采集周期计数，秒
extern u8 Meter_Number[7];             //表号
/*********************************************************************************
外部变量声明区
*********************************************************************************/
/*********************************************************************************
私有变量定义区
*********************************************************************************/ 
/*********************************************************************************
测试变量定义区
*********************************************************************************/
/*********************************************************************************
内部函数定义区
*********************************************************************************/
/*********************************************************************************
功能代码定义区
*********************************************************************************/
unsigned char Int_to_ASCLL(unsigned char data);
unsigned char ASCLL_to_Int(unsigned char data);
unsigned char BCD_to_Int(unsigned char data);
/*********************************************************************************
 Function:      //
 Description:   //
 Input:         //
                //
 Output:        //
 Return:      	//
 Others:        //
*********************************************************************************/

/*********************************************************************************
 Function:      //
 Description:   //
 Input:         //
                //
 Output:        //
 Return:      	//
 Others:        //
*********************************************************************************/

/*********************************************************************************
 Function:      //
 Description:   //
 Input:         //
                //
 Output:        //
 Return:      	//
 Others:        //
*********************************************************************************/

/*********************************************************************************
 Function:      //
 Description:   //
 Input:         //
                //
 Output:        //
 Return:      	//
 Others:        //
*********************************************************************************/

/*********************************************************************************
 Function:      //
 Description:   //
 Input:         //
                //
 Output:        //
 Return:      	//
 Others:        //
*********************************************************************************/

/*********************************************************************************
 Function:      //
 Description:   //
 Input:         //
                //
 Output:        //
 Return:      	//
 Others:        //
*********************************************************************************/

/*********************************************************************************
 Function:      //
 Description:   //
 Input:         //
                //
 Output:        //
 Return:      	//
 Others:        //
*********************************************************************************/
#endif
/******************************************END********************************************************/