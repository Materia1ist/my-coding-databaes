/*********************************************************************************
*实验名   ：流水灯（移位方式）
*实验效果	：流水灯
*
*********************************************************************************/
#include<reg52.h>
#define ON 0;
#define OFF 1;
void delay(unsigned int xms); //延迟函数的声明 
void main()
{
    unsigned char i;//0-255
    while(1)
	{
	    P1=0xfe;//1111 1110
	    for(i=0;i<8;i++)
		{
		    delay(200);
			P1<<=1;//P1=P1<<1	 
			P1=P1|0X01;//0000 0001 
		}
	}
}

void delay(unsigned int xms)		 //延迟函数		
{
	unsigned int i,j;
	for(i=xms;i>0;i--)		      //i=xms即延时约xms毫秒
		for(j=112;j>0;j--);
}