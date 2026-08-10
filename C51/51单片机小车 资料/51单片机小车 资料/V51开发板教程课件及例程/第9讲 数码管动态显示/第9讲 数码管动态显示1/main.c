/*********************************************************************************
*实验名   ：数码管动态显示
*实验效果	：8位数码管显示数字12345678
*注意   ： 每位数码管显示之间延迟时间小于3ms可看见8位数码管同时点亮
*
*********************************************************************************/
#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int

sbit DU=P2^6;
sbit WE=P2^7;

uchar code sz[17]={0x3f , 0x06 , 0x5b ,0x4f , 0x66 , 0x6d ,0x7d ,
                   0x07 , 0x7f , 0x6f ,0x77 , 0x7c , 0x39 , 
                   0x5e , 0x79 , 0x71 , 0x00};	 //0-9&A-F&“不显示”  字型码

void delay(uint xms)		  //xms等于几就延迟几毫秒
{
    uint i,j;
	for(i=xms;i>0;i--)
	    for(j=112;j>0;j--);
}

void main()
{
    while(1)
	{
	    P0=sz[8];	//数字8
		DU=1;
		DU=0;
		P0=0x7f;
		WE=1;
		WE=0;
		delay(2);		//延迟小于3ms人眼则看到8位数码管同时点亮

		P0=sz[7];	//数字7
		DU=1;
		DU=0;
		P0=0xbf;
		WE=1;
		WE=0;
		delay(2);

		P0=sz[6];	//数字6
		DU=1;
		DU=0;
		P0=0xdf;
		WE=1;
		WE=0;
		delay(2);

		P0=sz[5];	//数字5
		DU=1;
		DU=0;
		P0=0xef;
		WE=1;
		WE=0;
		delay(2);

		P0=sz[4];	//数字4
		DU=1;
		DU=0;
		P0=0xf7;
		WE=1;
		WE=0;
		delay(2);

		P0=sz[3];	//数字3
		DU=1;
		DU=0;
		P0=0xfb;
		WE=1;
		WE=0;
		delay(2);

		P0=sz[2];	//数字2
		DU=1;
		DU=0;
		P0=0xfd;
		WE=1;
		WE=0;
		delay(2);

		P0=sz[1];	//数字1
		DU=1;
		DU=0;
		P0=0xfe;
		WE=1;
		WE=0;
		delay(2);



	}
}




















