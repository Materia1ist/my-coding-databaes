
/**********************BST-V51实验开发板例程************************
*  平台：BST-V51 + Keil U3 + STC89C52
*  名称：DS1302模块实验
*  公司：深圳市亚博智能科技有限公司        
*  日期：2013-11
*  晶振:11.0592MHZ
*  说明：免费开源，不提供源代码分析.
******************************************************************/
#include <reg52.h>
#include "ds1302.h"
#include "display.h"
#define uchar unsigned char
unsigned char code table[]={
0x3f  , 0x06 , 0x5b , 0x4f ,
0x66 , 0x6d ,0x7d , 0x07 , 
0x7f  , 0x6f , 0x77 , 0x7c ,
0x39 , 0x5e , 0x79 , 0x71 ,0xbf
};
void main()
{
	uchar t0,t1,t2,t3,t4,t5;
	SYSTEMTIME CurrentTime;
	Initial_DS1302();
	DS1302_SetTime(DS1302_HOUR,10);	//设置的时间是10：54：30
	DS1302_SetTime(DS1302_MINUTE,54);
	DS1302_SetTime(DS1302_SECOND,30);   
	while(1)
	{
		DS1302_GetTime(&CurrentTime);
		DateToStr(&CurrentTime);
		TimeToStr(&CurrentTime);
		t0=CurrentTime.TimeString[0];
		t1=CurrentTime.TimeString[1];
		t2=CurrentTime.TimeString[3];
		t3=CurrentTime.TimeString[4];
		t4=CurrentTime.TimeString[6];
		t5=CurrentTime.TimeString[7];
		display(table[t0],table[t1],table[t2],table[t3],table[t4],table[t5]);
	}
}