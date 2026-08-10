/**********************亚博智能小车黑线循迹例程************************
*  平台：BST-V51  + Keil uVision3 + STC89C52RC 
*  名称：智能小车例程
*  公司：深圳市亚博智能科技有限公司     
*  编写：罗工
*  日期：2016-5-10
*  晶振:11.0592MHZ
*  说明：免费开源，不提供源代码分析，有问题直接到交流群交流
*  硬件设置：要有自己动手能力，进行组装接线和传感器灵敏度的调试，才能完成实验
*  使用说明：根据下面IO口自己用杜邦线连接各种模块，可以自己修改各种模块IO口 
******************************************************************/
 //按下K4按键，1秒左右启电小车
 //按下复位健可以停止小车	

#include "reg52.h"	     //包含52系统头文件
#include <string.h>
#include "bst_car.h"	 //包含bst_car.h智能小车头文件



bit startBit = 0;  				//串口接收开始标志位
bit newLineReceived = 0; 		//串口一帧协议包接收完成


unsigned char inputString[50];  //接收数据协议

long int distance = 0;               //距离变量
unsigned int timeH, timeL;
unsigned char succeed_flag;


char returntemp[] = "$0,0,0,0,0,0,0,0,0,0,0,0000cm,8.2V#";


/******************************************************************************/
/* 函数名称  : delayt                                                         */
/* 函数描述  : 延时函数                                                       */
/* 输入参数  : x                                                              */
/* 参数描述  : 延时时间数据                                                   */
/* 返回值    : 无                                                             */
/******************************************************************************/	
void delayt(unsigned int x)
{
    unsigned char j;
    while(x-- > 0)
    {
  	    for(j = 0;j < 125;j++)
        {
            ;
        }
    }
}

/******************************************************************************/
/* 函数名称  : Measure_Distance                                               */
/* 函数描述  : 计算距离函数                                                   */
/* 输入参数  : 无                                                             */
/* 参数描述  : 无                                                             */
/* 返回值    : 无                                                             */
/******************************************************************************/
long Measure_Distance(void)
{
	unsigned int  time;
	OUTPUT = 0;
    EA = 1;
	T2MOD = 0X00;
	T2CON = 0x00; //定时器12位工作模式	 自动重装
	while(1)
	{
		EA = 0;
		OUTPUT = 1;
		delayt(1);
		OUTPUT = 0;
		while(INPUT == 0);
		succeed_flag = 0;
		EA = 1;
		EX0 = 1;
		TH2 = 0;
		TL2 = 0;
		TR2 = 1;  //开启定时器
		delayt(10);
		TR2 = 0;
		EX0 = 0;
		if(succeed_flag == 1)
		{
			time = timeH*256 + timeL;
			distance = time*0.0172;
			return distance;
		}
		else
		{
			distance = 0;

		}

	}
}


void exit0() interrupt 0  // 外部中断0  超声波接收
{
	timeH = TH2;
	timeL = TL2;
	succeed_flag = 1;
	EX0 = 0;
}

void timer2()  interrupt 5	 //定时器2
{
	 TF2 = 0;
     TH2 = 0;	  //1Ms定时
	 TL2 = 0;
}
 /******************************************************************/
/* 串口中断程序*/
/******************************************************************/

void UART_SER () interrupt 4
{
	unsigned char n; 	//定义临时变量
	static int num = 0;

	if(RI) 		//判断是接收中断产生
	{
		RI = 0; 	//标志位清零
		n = SBUF; //读入缓冲区的值

		//control=n;
	    if(n == '$')	 //协议头开始，此时开始接收协议
	    {
	      startBit = 1;
		  num = 0;
	    }
	    if(startBit == 1)  //判断到协议头标志位为1，则接收数据到数组里面
	    {
	       inputString[num] = n;     
	    }  
	    if (n == '#') 	 //协议尾结束接收，此时等待主循环解析协议
	    {
	       newLineReceived = 1; 
	       startBit = 0;
	    }
		num++;
		if(num >= 50)	 //这里是防止数据包一直接收不到协议尾时重新接收，防止数据错误
		{
			num = 0;
			startBit = 0;
			newLineReceived	= 0;
		}
	}

}

//WIFI、蓝牙初始化
void WifiInit(void)
{
   
   	SCON = 0x50; 	// SCON: 模式1, 8-bit UART, 使能接收
	TMOD |= 0x20;
	TH1=0xfd; 		//波特率9600 初值
	TL1=0xfd;
	TR1= 1;
	EA = 1;	    	//开总中断
	ES= 1; 			//打开串口中断


}
//串口发送函数
void PutString(unsigned char *TXStr)  
{                
	ES=0;     
	while(*TXStr!=0) 
	{                      
	  SBUF=*TXStr;
	  while(TI==0);
	  TI=0;    
	  TXStr++;
	}
	ES=1; 
}     
//主函数
void main(void)
{	
    P0 = 0X00;    //关电机	
	P1 = 0xff; 	  //关闭所有LED和风扇


	WifiInit();

	while(1)	//无限循环
	{ 
		 
		 distance = Measure_Distance();        //计算脉宽并转换为距离
		 

		if (newLineReceived)
	   	{
		
			if(inputString[17] == '1')  //点灯 对应（自定义2面板）
			{
				LED = (LED == 1)?0:1;  //反转电平  
			}
			
		}        
	      
       //返回状态
	   //组装超声波数据	//这里对应（自定义2显示），发送返回包
		returntemp[23] = (distance / 1000) + 0x30;
		returntemp[24] = (distance / 100 % 10) + 0x30;
		returntemp[25] = (distance / 10 % 10) + 0x30;
		returntemp[26] = (distance % 10 ) + 0x30;


       PutString(returntemp); //返回协议数据包       
       
       newLineReceived = 0;  
	   memset(inputString, 0x00, sizeof(inputString));  
		 
	 }

}
   


