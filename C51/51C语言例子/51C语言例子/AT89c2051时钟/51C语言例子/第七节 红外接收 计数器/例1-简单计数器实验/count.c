/***************************************************************************
标题：	简单计数器实验
效果：	复位后，按遥控器红外发射，数码管显示第一个低电平脉冲为多少毫秒，比如NEC制遥控器为9MS
工作于：LY5A-L2A开发板
作者：	林洋电子吧
网站：	www.lydz8.com
说明：	只中断一次，下次检测必需复位 		
******************************************************************************/

//头文件:
#include "reg51.h"

//变量定义:
code unsigned char table[]=
			{0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
					//表：共阳数码管 0-9 

unsigned char l_posit=0;	//显示位置
unsigned int ly_count=0;

//引脚定义:		
sbit int1 = P3^3;	//外中断1
sbit SMG_q = P1^0;	//定义数码管阳级控制脚（千位）
sbit SMG_b = P1^1;	//定义数码管阳级控制脚（百位）
sbit SMG_s = P1^2;	//定义数码管阳级控制脚（十位）
sbit SMG_g = P1^3;	//定义数码管阳级控制脚（个位）

//函数声明:
void display(unsigned int da);//定义显示函数，参数为显示内容
void delay(unsigned int timer); 

//主函数，C语言的入口函数:			
void main(void) 
{
	EA=1;					//首先开启总中断
	EX1=1;  				//开启外部中断 1,按键5
	IT1=1;        			//设置成下降沿触发方式
	TL1=0;
	TH1=0;					//定时/计数器1初始值
	TMOD=0X10;				//定时器1的方式1，16位计数器，用来计数时间
	while(1){//主程序循环
		display(ly_count);	//显示时间，单位为毫秒，最大65毫秒
		delay(100);
	}
}
/***********外中断1入口函数，P33引脚**************************/
void hongwai(void)   interrupt 2
{
	TR1=1;				//定时器以12M晶振12分频计数，即1us计数
	while(!int1);
	TR1=0;				//停止计数
	ly_count=(int)(TH1<<8)+TL1;//获取计数值
	ly_count/=10;		//缩小显示范围，因数码管只有四位
	EX1=0;				//关闭中断，只中断一次
	TF1=0;
}

//显示函数，参数为显示内容
void display(unsigned int da)
{
	P0=0XFF;			//
	da=da%10000;	
	switch(l_posit){
	case 0:		//选择千位数码管，关闭其它位
		SMG_q=0;
		SMG_b=1;	
		SMG_s=1;		
		SMG_g=1;
		P0=table[da/1000];	//输出显示内容
		break;
	case 1:		//选择百位数码管，关闭其它位
		SMG_q=1;
		SMG_b=0;	
		SMG_s=1;		
		SMG_g=1;
		P0=table[da%1000/100]&0x7f;//加上小数点
		break;
	case 2:		//选择十位数码管，关闭其它位
		SMG_q=1;
		SMG_b=1;	
		SMG_s=0;		
		SMG_g=1;
		P0=table[da%100/10];
		break;
	case 3:		//选择个位数码管，关闭其它位
		SMG_q=1;
		SMG_b=1;	
		SMG_s=1;		
		SMG_g=0;
		P0=table[da%10];
		break;
	}
	l_posit++;		//每调用一次将轮流显示一位
	if(l_posit>3)
		l_posit=0;	
}
//延时子函数,短暂延时
void delay(unsigned int timer){		
	while(timer--);
}
