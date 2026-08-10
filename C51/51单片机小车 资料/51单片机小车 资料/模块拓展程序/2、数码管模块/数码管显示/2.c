/**********************BST-V51实验开发板例程************************
*  平台：BST-V51 + Keil U3 + STC89C52
*  名称：数码管模块实验
*  公司：深圳市亚博智能科技有限公司         
*  日期：2013-11
*  晶振:11.0592MHZ
*  说明：免费开源，不提供源代码分析.
******************************************************************/


#include <reg51.h>

sbit dula=P2^6;		//段选信号的锁存器控制
sbit wela=P2^7;		//位选信号的锁存器控制

unsigned char code table[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
						//数码管各位的码表
void delay(unsigned int i)
{
	unsigned int m,n;
	for(m=i;m>0;m--)
		for(n=90;n>0;n--);
}

void main()
{

	unsigned char num;
	while(1)
	{
		for(num=0;num<8;num++)
		{
			P0=table[num];	   
			wela=1;
			wela=0;

			P0=0x4f;	  //数字“3”的代码
			dula=1;
			dula=0;
			delay(1000);
		}
	}
}

