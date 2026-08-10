/*********************************************************************************
*实验名   ：流水灯
*实验效果	：流水灯
*
*********************************************************************************/
#include<reg52.h>
#define ON 0;
#define OFF 1;

sbit LED0=P1^0;
sbit LED1=P1^1;
sbit LED2=P1^2;
sbit LED3=P1^3;
sbit LED4=P1^4;
sbit LED5=P1^5;
sbit LED6=P1^6;
sbit LED7=P1^7;

void delay(unsigned int xms)				
{
	unsigned int i,j;
	for(i=xms;i>0;i--)		      //i=xms即延时约xms毫秒
		for(j=112;j>0;j--);
}

void main()
{
    while(1)
	{
	    LED0=ON;
		delay(200);
		LED0=OFF;

		LED1=ON;
		delay(200);
		LED1=OFF;

		LED2=ON;
		delay(200);
		LED2=OFF;

		LED3=ON;
		delay(200);
		LED3=OFF;

		LED4=ON;
		delay(200);
		LED4=OFF;

		LED5=ON;
		delay(200);
		LED5=OFF;

		LED6=ON;
		delay(200);
		LED6=OFF;

		LED7=ON;
		delay(200);
		LED7=OFF;

	}
}
