/**********************BST-V51实验开发板例程************************
*  平台：BST-V51 + Keil U3 + STC89C52
*  名称：24L01无线接收（从机1）
*  公司：深圳市亚博智能科技有限公司       
*  日期：2015-6
*  晶振:11.0592MHZ
******************************************************************/
#include<reg52.h>
#include"NRF24L01.h"  
#include"Delay.h"

sbit led = P1^1;

void main()
{

   unsigned int num=0 ;   
   led = 1; 

   NRF24L01Int();    
  
   while(1)
    {
	   NRFSetRXMode();   //设置为接收模式  
	   GetDate();        //开始接收数据 ，实时接收	
	}	
}