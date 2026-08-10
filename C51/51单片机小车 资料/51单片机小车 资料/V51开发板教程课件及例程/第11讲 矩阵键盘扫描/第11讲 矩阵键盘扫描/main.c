/*********************************************************************************
*实验名   ：矩阵键盘扫描 数码管显示
*实验效果	：按S1-S16矩阵按键，数码管8位依次显示0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F
*
*********************************************************************************/
#include<reg52.h>
#include"bstv51.h"

uchar code table[17]={0x3f , 0x06 , 0x5b ,0x4f , 0x66 , 0x6d ,0x7d ,
                   0x07 , 0x7f , 0x6f ,0x77 , 0x7c , 0x39 , 
                   0x5e , 0x79 , 0x71 , 0x00};	 //0-9&A-F&“不显示”  字型码

void delay(uint xms)	//延迟xms
{
    uint i,j;
	for(i=xms;i>0;i--)
	  for(j=112;j>0;j--);
}

void display(uchar num)	   //数码管显示函数
{
    P0=table[num];		 //段选
	DU=1;
	DU=0;
}

void keyscan4x4()
{
    uchar temp,key;


	///////////////第一行扫描///////////////////
	P3=0xfe;//1111 1110 让P3.0口输出低
	temp=P3;
	temp=temp&0xf0;//1111 0000	位与操作 屏蔽后四位
	if(temp!=0xf0)
	{
	    delay(10);
		temp=P3;
		temp=temp&0xf0;
		if(temp!=0xf0)
		{
		    temp=P3;
			switch(temp)
			{
			  case 0xee:	   //1110 1110 S1被按下
			       key=0;
				   break;
			  case 0xde:		  //1101 1110  S2被按下
				   key=1;
				   break;
			  case 0xbe:		  //1011 1110  S3被按下
				   key=2;
				   break;
			  case 0x7e:		  //0111 1110  S4被按下
				   key=3;
				   break;
			}
			while(temp!=0xf0)
			{
			    temp=P3;
				temp=temp&0xf0;
			}
			display(key);
		}
	}
			///////////////第二行扫描///////////////////
	P3=0xfd;//1111 1101 让P3.1口输出低
	temp=P3;
	temp=temp&0xf0;//1111 0000	位与操作 屏蔽后四位
	if(temp!=0xf0)
	{
	    delay(10);
		temp=P3;
		temp=temp&0xf0;
		if(temp!=0xf0)
		{
		    temp=P3;
			switch(temp)
			{
			  case 0xed:	   //1110 1101 S5被按下
			       key=4;
				   break;
			  case 0xdd:		  //1101 1101  S6被按下
				   key=5;
				   break;
			  case 0xbd:		  //1011 1101  S7被按下
				   key=6;
				   break;
			  case 0x7d:		  //0111 1101  S8被按下
				   key=7;
				   break;
			}
			while(temp!=0xf0)
			{
			    temp=P3;
				temp=temp&0xf0;
			}
			display(key);
		}
	 }
			///////////////第三行扫描///////////////////
	P3=0xfb;//1111 1011 让P3.2口输出低
	temp=P3;
	temp=temp&0xf0;//1111 0000	位与操作 屏蔽后四位
	if(temp!=0xf0)
	{
	    delay(10);
		temp=P3;
		temp=temp&0xf0;
		if(temp!=0xf0)
		{
		    temp=P3;
			switch(temp)
			{
			  case 0xeb:	   //1110 1011 S9被按下
			       key=8;
				   break;
			  case 0xdb:		  //1101 1011  S10被按下
				   key=9;
				   break;
			  case 0xbb:		  //1011 1011  S11被按下
				   key=10;
				   break;
			  case 0x7b:		  //0111 1011  S12被按下
				   key=11;
				   break;
			}
			while(temp!=0xf0)
			{
			    temp=P3;
				temp=temp&0xf0;
			}
			display(key);
		  }
		}

			///////////////第四行扫描///////////////////
	P3=0xf7;//1111 0111 让P3.0口输出低
	temp=P3;
	temp=temp&0xf0;//1111 0000	位与操作 屏蔽后四位
	if(temp!=0xf0)
	{
	    delay(10);
		temp=P3;
		temp=temp&0xf0;
		if(temp!=0xf0)
		{
		    temp=P3;
			switch(temp)
			{
			  case 0xe7:	   //1110 0111 S13被按下
			       key=12;
				   break;
			  case 0xd7:		  //1101 0111  S14被按下
				   key=13;
				   break;
			  case 0xb7:		  //1011 0111  S15被按下
				   key=14;
				   break;
			  case 0x77:		  //0111 0111  S16被按下
				   key=15;
				   break;
			}
			while(temp!=0xf0)
			{
			    temp=P3;
				temp=temp&0xf0;
			}
			display(key);

		 }
	 }

}

void main()
{
    bstv51_init(); //学习板初始化 
	P0=0;		 //位选 锁存为8位同时显示
	WE=1;
	WE=0;
	while(1)
	{
	   keyscan4x4();
	}
}










