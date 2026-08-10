/*********************************************************************************
*实验名   ：数码管动态显示
*实验效果	：8位数码管同时显示数字“12345678”
*
*********************************************************************************/
#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int

sbit DU=P2^6;
sbit WE=P2^7;

uchar code sz[17]={0x3f , 0x06 , 0x5b ,0x4f , 0x66 , 0x6d ,0x7d ,
                   0x07 , 0x7f , 0x6f ,0x77 , 0x7c , 0x39 , 
                   0x5e , 0x79 , 0x71 , 0x00};	   //0-9&A-F&“不显示”  字型码


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
		P0=0xff;
		WE=1;
		WE=0;


		P0=sz[7];	//数字7
		DU=1;
		DU=0;
		P0=0xbf;
		WE=1;
		WE=0;
		P0=0xff;
		WE=1;
		WE=0;

		P0=sz[6];	//数字6
		DU=1;
		DU=0;
		P0=0xdf;
		WE=1;
		WE=0;
		P0=0xff;
		WE=1;
		WE=0;

		P0=sz[5];	//数字5
		DU=1;
		DU=0;
		P0=0xef;
		WE=1;
		WE=0;
		P0=0xff;
		WE=1;
		WE=0;

		P0=sz[4];	//数字4
		DU=1;
		DU=0;
		P0=0xf7;
		WE=1;
		WE=0;
		P0=0xff;
		WE=1;
		WE=0;

		P0=sz[3];	//数字3
		DU=1;
		DU=0;
		P0=0xfb;
		WE=1;
		WE=0;
		P0=0xff;
		WE=1;
		WE=0;

		P0=sz[2];	//数字2
		DU=1;
		DU=0;
		P0=0xfd;
		WE=1;
		WE=0;
		P0=0xff;
		WE=1;
		WE=0;

		P0=sz[1];	//数字1
		DU=1;
		DU=0;
		P0=0xfe;
		WE=1;
		WE=0;
		P0=0xff;
		WE=1;
		WE=0;



	}
}




















