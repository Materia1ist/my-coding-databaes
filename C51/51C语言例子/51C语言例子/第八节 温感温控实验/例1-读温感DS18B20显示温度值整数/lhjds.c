/***************************************************************************
标题：	温感实验
效果：	读取温度值数码管显示
工作于：LY5A-L2A开发板
作者：	林洋电子吧
网站：	www.lydz8.com
说明：	板使用12M晶振
******************************************************************************/

//头文件:
#include "reg51.h"
#include "ds18b20.h"	//引入DS18B20头文件

//变量定义:
unsigned char ly_dis[4];//定义显示缓冲区
code unsigned char table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xc6};
					//表：共阳数码管 0-9 C
unsigned char l_posit=0;	//显示位置

//引脚定义:	
sbit SMG_q = P1^0;	//定义数码管阳级控制脚（千位）
sbit SMG_b = P1^1;	//定义数码管阳级控制脚（百位）
sbit SMG_s = P1^2;	//定义数码管阳级控制脚（十位）
sbit SMG_g = P1^3;	//定义数码管阳级控制脚（个位）

//函数声明:
void display(void);//显示函数，显示缓冲区内容
void delay(void); 

//主函数，C语言的入口函数:	
void main()
{
	unsigned int i=0;
	char ltemp;
	while(1){
		if(i==0)				//先发转换命令，再读数值，以减少速度慢带来的显示抖动
			tmpchange();      	//温度转换
		if(i==100){
			ltemp=tmp()/16;		//得到十进制温度值，因为DS18B20可以精确到0.0625度，这里取整数显示
			if(ltemp<0){		//判断第一位显示整数还是负号
				ly_dis[0]=0xbf;
				ltemp=0-ltemp;	
			}
			else
				ly_dis[0]=ltemp/100;//显示百位值
			ltemp=ltemp%100;
			ly_dis[1]=ltemp/10;	//显示温度十位值
			ly_dis[2]=ltemp%10;	//显示温度个位值
			ly_dis[3]=10;		//最后一位显示一个C单位
		}
		i++;
		if(i==3000)				//3000一个读取周期
			i=0;
		display();	//调用显示	
		delay();
	}
}

//显示函数，参数为显示内容
void display()
{
	P0=0XFF;			//	
	switch(l_posit){
	case 0:		//选择千位数码管，关闭其它位
		SMG_q=0;
		SMG_b=1;	
		SMG_s=1;		
		SMG_g=1;
		P0=table[ly_dis[0]];	//输出显示内容
		break;
	case 1:		//选择百位数码管，关闭其它位
		SMG_q=1;
		SMG_b=0;	
		SMG_s=1;		
		SMG_g=1;
		P0=table[ly_dis[1]];
		break;
	case 2:		//选择十位数码管，关闭其它位
		SMG_q=1;
		SMG_b=1;	
		SMG_s=0;		
		SMG_g=1;
		P0=table[ly_dis[2]];
		break;
	case 3:		//选择个位数码管，关闭其它位
		SMG_q=1;
		SMG_b=1;	
		SMG_s=1;		
		SMG_g=0;
		P0=table[ly_dis[3]];
		break;
	}
	l_posit++;		//每调用一次将轮流显示一位
	if(l_posit>3)
		l_posit=0;	
}

//延时子函数,短暂延时
void delay(void){		
	unsigned char i=10;
	while(i--);
}
