/*********************************************************************************************************
//概述：
//作者：随风飘跃    时间：       地点：
//CPU型号：         系统主频：
//版本号：V0.0        
*********************************************************************************************************/
#ifndef  __save_h
#define  __save_h
/*********************************************************************************************************
文件包含区
*********************************************************************************************************/
#include "include.h"
/*********************************************************************************************************
宏定义区
*********************************************************************************************************/
/*******************************************************************************************************
管脚定义
***********************************************************************************************************/

/*********************************************************************************************************
数据类型定义
*********************************************************************************************************/
/*********************************************************************************************************
外部变量声明区
*********************************************************************************************************/
/*********************************************************************************************************
函数声明区
*********************************************************************************************************/
void WriteRom (unsigned short addr, void *pbuff, unsigned char length);
void Save_IP(unsigned char *IP,unsigned char Num);
void Save_Version(void);
unsigned char Sum_Check(unsigned char *sdata,unsigned short NUM);                //计算和校验
void Read_ACUM_Flow(unsigned short addr,union flow_union *Flow);
void Save_Add_Flow(union flow_union *Flow);       //存储累积水量
void Save_SDCF_Flow(union flow_union *Flow);
void Save_Cal(enum Cal_State_En *Cal);       //存储霍尔状态
void Read_BAT_Alarm_Value(void);     //读取电压告警值
void Save_BAT_Alarm_Value(void);     //保存电压告警值
void Read_Settle_Date(void);         //读取结算日期
void Save_Settle_Date(void);         //保存结算日期
void Read_Settle_Time(void);            //读取日结算时间
void Save_Settle_Time(void);            //保存日结算时间
void Read_Report_Cycle(void);        //读取上报周期
void Save_Report_Cycle(void);        //保存上报周期
void Read_Meter_Number(void);           //读取表号
void Save_Meter_Number(void);           //保存表号
/********************************************************************************************************/
#endif

/******************************************END********************************************************/