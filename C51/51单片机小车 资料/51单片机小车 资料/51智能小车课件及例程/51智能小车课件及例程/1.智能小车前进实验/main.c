#include<reg52.h>  //包含52单片机系统头文件

//定义智能小车驱动模块输入IO口
sbit IN1=P1^2; // 高电平1 后退（反转）
sbit IN2=P1^3; // 高电平1 前进（正转）

sbit IN3=P1^6; // 高电平1 前进（正转）	
sbit IN4=P1^7; // 高电平1 后退（反转）

sbit EN1=P1^4; // 高电平使能 
sbit EN2=P1^5; // 高电平使能 

void delay(unsigned int xms)				
{
	unsigned int i,j;
	for(i=xms;i>0;i--)		      //i=xms即延时约xms毫秒
		for(j=112;j>0;j--);
}

void run(void)
{
	EN1=1;
	EN2=1;//电机使能
    IN1=0;
	IN2=1; //左电机的正转
	IN3=1;
	IN4=0;//右电机的正转
}

void main(void)
{
    delay(500);//延时500ms
	run();	   //调用前进函数
	while(1);  //死循环
	

}












