/**********************BST-V51实验开发板例程************************
*  平台：BST-V51 + Keil U3 + STC89C52
*  名称：人体红外感应实验
*  公司：深圳市亚博智能科技有限公司       
*  日期：2015-6
*  晶振:11.0592MHZ
*  人体在感应范围内活动的时候，数码管显示“people”，
*  没有活动的时候显示“no body”
******************************************************************/
#include<reg52.h>    //包含单片机寄存器的头文件
#include <intrins.h> 

sbit sensor=P1^0;
sbit DU=P2^6;
sbit WE=P2^7;

unsigned int time_count=0;
char flag=0;

#define led_off {P1 |= 0xf0;}
#define led_on {P1 &= 0x0f;}

unsigned char nobody[]={0x00,0x54,0x5c,0x00,0x7c,0x5c,0x5e,0x6e},
			  people[]={0x00,0x73,0x79,0x3f,0x73,0x38,0x79,0x00},
			  wei[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};

/*------------------------------------------------
               数码管显示函数
------------------------------------------------*/
void dispaly(char body)
{
	char i;
	if(body)
		for(i=0;i<8;i++)
		{
			P0=people[i];
			DU=1;
			DU=0;
			P0=wei[i];
			WE=1;
			WE=0;
			P0=0xff;
			WE=1;
			WE=0;
		}
	else
		for(i=0;i<8;i++)
		{
			P0=nobody[i];
			DU=1;
			DU=0;
			P0=wei[i];
			WE=1;
			WE=0;
			P0=0xff;
			WE=1;
			WE=0;
		}
		
}
/*------------------------------------------------
               定时器0初始化函数
------------------------------------------------*/
void timer0_init()
{
	TMOD = 0x01; //定时器0选择工作方式1
    TH0 = 0x4C;	 //设置初始值
    TL0 = 0x00; 
    EA = 1;			 //打开总中断
    ET0 = 1;		 //打开定时器0中断
    TR0 = 1;		 //启动定时器0
}
/*------------------------------------------------
                    主函数
------------------------------------------------*/
main()
{  
	timer0_init();
	while(1)
	{
		dispaly(flag);
	}
}
/*------------------------------------------------
               定时器中断函数
------------------------------------------------*/
void timer0() interrupt 1
{
    TH0 = 0x4C;	 //设置初始值,为50ms
    TL0 = 0x00;
	sensor=1; 
	if(sensor)
	{
		time_count=0;
		flag=1;
	}
	else if(flag)
		time_count++;
	if(time_count>50)//2500ms,封锁时间2.5s
	{
		time_count=0;
		flag=0;
	}
		
}