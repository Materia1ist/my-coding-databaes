/*********************************************************************************
*实验名   ：蜂鸣器流水灯
*实验效果	：程序烧录进后蜂鸣器配合流水灯发出声响
*
*********************************************************************************/
#include<reg52.h>
#define ON 0;
#define OFF 1;
sbit FM=P2^3;

void delay(unsigned int xms);
void main()
{
    unsigned char i;//无符号字符型范围0-255
    while(1)
	{
	    P1=0xfe;//1111 1110	使第一个LED灯点亮
	    for(i=0;i<8;i++)
		{
		    delay(100);
			P1<<=1;//P1=P1<<1	 
			P1=P1|0X01;//0000 0001 
			FM=ON;
			delay(100);
			FM=OFF;
		}
	}
}

void delay(unsigned int xms)				
{
	unsigned int i,j;
	for(i=xms;i>0;i--)		      //i=xms即延时约xms毫秒
		for(j=112;j>0;j--);
}