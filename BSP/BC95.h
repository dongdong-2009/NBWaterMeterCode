#ifndef __BC95_H__
#define __BC95_H__
/*********************************************************************************************************
文件包含区
*********************************************************************************************************/
#include "include.h"
/*********************************************************************************************************
宏定义区
*********************************************************************************************************/
#define         RECV_BUFF_SIZE                512//接收缓冲区大小
#define         SEND_BUFF_SIZE               128//发送缓冲区大小
#define         CONNECT_ERROR_NUM            3  //连接错误次数
#define         SEND_ERROR_NUM               3  //发送错误次数

#define         BC95_POWER_UP_TIME           5//BC95上电时间 单位ms
#define         BC95_R_TIMEROUT_TIME         3 //接收超时 单位ms

#define         BC95_S_TIMEROUT_TIME         6000 //发送数据超时 单位ms
/*********************************************************************************************************
数据类型定义
*********************************************************************************************************/
//struct Network_Par_Str
//{
//  unsigned char IP[4];   //连接IP
//  unsigned short Port;   //连接端口
//};
//
//union Network_Par_Uni
//{
//  struct Network_Par_Str Str;
//  unsigned char Byte[6];
//};

struct Error_Connter_Str
{
  unsigned char Send;
  unsigned char Connect;
};
 

enum Start_Process_En   //启动流程
{
  BC95_RECONNECT,        //重连
  BC95_POWER_DOWN,      //掉电
  BC95_POWER_UP,        //上电
  
  NRB,                  //重启
  AT,                   //同步波特率
  CIMI,                 //查询IMSI
  CGSN,                 //查询IMEI  
  
  GETNBAND,             //查询频段
  SETNBAND,             //设置频段
  GETCFUN,              //查询电话功能
  SETCFUN,              //设置电话功能

//  GETCGDCONT,           //查询APN
//  SETCGDCONT,           //设置APN
  GETNCDP,              //查询CDP服务器
  SETNCDP,              //设置CDP服务器
  
  GETCGATT,             //查询网络激活状态
  SETCGATT,             //激活网络
  CEREG,                //查询网络注册状态
  CSQ,                  //查询信号强度
  NNMI,                 //新消息指示
  NQMGR,                //查询消息接收
  NMGR,                 //接收消息
  NMGS,                 //发送消息
  BC95_CONNECT_ERROR,      //启动错误
};

enum BC95_State_Eum
{
  NO_State              = 0x00,                                                 //无结果
  BC95_OK               = 0X01,                                                 //连接正常
  BC95_NG               = 0X02,                                                 //连接失败
  NO_Card               = 0X03                                                  //无卡
};


enum Send_Process_En//发送流程
{
  WAIT_CONNECT,//等待连接
  SEND_READY,//发送等待
  
  SEND_AII_PARA,//发送所有参数
  SEND_TEMP_ALARM,//发送温度报警
  SEND_VOL_ALARM,//发送电压报警
  SEND_MAG_ALARM,//发送磁报警  

  SEND_WAIT_OK,//等待发送成功
  SEND_ERROR,//发送失败
};

struct Send_Bit_EN         //发送标志位
{
  unsigned char All_Para:1;     //发送所有参数
  unsigned char HC_Flow:1;      //发送历史累积流量
  unsigned char Vol_Alarm:1;    //发送电压报警
  unsigned char Mag_Alarm:1;   //发送磁报警  
};
  
struct BC95_Str//BC95 总结构体
{
  char R_Buffer[RECV_BUFF_SIZE]; //接收缓冲区
  char S_Buffer[SEND_BUFF_SIZE]; //发送缓冲区
  unsigned short Recv_Length; //发送长度
  unsigned short Send_Length; //发送长度
  unsigned char Data_Buffer[RECV_BUFF_SIZE-20];//数据缓冲
  unsigned short Data_Length;//数据长度
  unsigned char R_Channel;//接收的信道
  unsigned char S_Channel;//发送的信道
  bool Data_Pend;//数据挂起
  bool Channel_Connect[6];//信道连接标志
  bool Channel_Connect_ERROR[6];//信道连接失败标志
  unsigned char Connect_Channel_Num;//连接中的信道
  enum Start_Process_En Start_Process;//连接进程
  enum Send_Process_En Send_Process;//发送进程
  struct Send_Bit_EN  Send_Bit;         //发送标志位
  struct Error_Connter_Str Err_Conner;//错误计数
  unsigned char Rssi;//信号强度
  bool Incident_Pend;//事件挂起标志
  enum BC95_State_Eum State;//状态
  bool ZIPSTATUS_Pend;//用于查询状态
  unsigned char Reconnect_Times;        //重连次数
};
 
/*********************************************************************************************************
外部变量声明区
*********************************************************************************************************/
extern struct BC95_Str BC95;//BC95 用的寄存器
/*********************************************************************************************************
函数声明区
*********************************************************************************************************/
void BC95_Power_On(void); 
void BC95_Power_Off(void);
void BC95_Reset(void);
void BC95_Process(void);
void BC95_Data_Send(unsigned char *Data,unsigned short Len);

void ZTE_BC95_PIN_INIT(void);
void BC95_Open(void);
void BC95_CLose(void);
void BC95_Start(void);
void BC95_Process(void);
void BC95_Start_Timeout_CallBalk(void);
void BC95_Delay_CallBalk(void);

void Recv_Data_Process(void);
unsigned char Send_Data_Process(void);
void ACK(unsigned char messageId,unsigned char errcode);
void Report_All_Parameters(void);
void Report_HC_Flow(void);
void Report_Settle_Time(void);
void Report_Battery_Alarm(void);
void Report_Meter_Number(void);
void Report_Valve_Status(void);
void Report_Magnetic_Alarm(void);

//void GSM_SET_AT_IP(unsigned short Port,unsigned char *IP,unsigned char Channel);
//void BC95_PowerUP_CallBalk(void);
//void GSM_Send_AT_Cmd(unsigned char *GSM_SEND_AT,unsigned short cmd_len);
//
//ErrorStatus BC95_Send(unsigned char *Send_Data,unsigned short Send_Lenght,unsigned char channel);
//unsigned short BC95_Receive(unsigned char *R_buff);
//void BC95_ZIPSTATUS(unsigned char Channel);//查询当前TCP连接
//void Send_Data_Timeout(void);//发送数据超时
//void BC95_ZIPCLOSE(unsigned char Channel);//关闭当前TCP连接
/********************************************************************************/
#endif

/******************************************END********************************************************/