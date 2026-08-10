#include<reg52.h>  //包含52单片机系统头文件

//定义智能小车驱动模块输入IO口
sbit IN1=P1^2; // 高电平1 后退（反转）
sbit IN2=P1^3; // 高电平1 前进（正转）

sbit IN3=P1^6; // 高电平1 前进（正转）	
sbit IN4=P1^7; // 高电平1 后退（反转）

sbit EN1=P1^4; // 高电平使能 
sbit EN2=P1^5; // 高电平使能 

sbit K4=P3^7; //按键K4定义
sbit FM=P2^3; //蜂鸣器定义

void delay(unsigned int xms)				
{
	unsigned int i,j;
	for(i=xms;i>0;i--)		      //i=xms即延时约xms毫秒
		for(j=112;j>0;j--);
}

void run(void)			  //前进函数
{
	EN1=1;
	EN2=1;//电机使能
    IN1=0;
	IN2=1; //左电机的正转
	IN3=1;
	IN4=0;//右电机的正转
}

void back(void)			  //后退函数
{
	EN1=1;
	EN2=1;//电机使能
    IN1=1;
	IN2=0; //左电机的反转
	IN3=0;
	IN4=1;//右电机的反转
}

void right(void)		 //右转函数
{
	EN1=1;
	EN2=1;//电机使能
    IN1=0;
	IN2=1; //左电机的正转
	IN3=0;
	IN4=0;//右电机不动
}

/*void right(void)			  //右转函数 写法2供参考
{
	EN1=1;
	EN2=0;//右电机使不能！！！！！！
    IN1=0;
	IN2=1; //左电机的正转
	IN3=1;
	IN4=0;//无论IN3 IN4如何赋值右电机都不动
} */


void left(void)			  //左转函数
{
	EN1=1;
	EN2=1;//电机使能
    IN1=0;
	IN2=0; //左电机不动
	IN3=1;
	IN4=0;//右电机正转
}

void stop(void)			  //停止函数
{
	EN1=1;
	EN2=1;//电机使能
    IN1=0;
	IN2=0; //左电机不动
	IN3=0;
	IN4=0;//右电机正转
}


void spin_left(void)			  //向左打转函数
{
	EN1=1;
	EN2=1;//电机使能
    IN1=0;
	IN2=1; //左电机正转
	IN3=0;
	IN4=1;//右电机反转
}

void spin_right(void)			  //向右打转函数
{
	EN1=1;
	EN2=1;//电机使能
    IN1=1;
	IN2=0; //左电机反转
	IN3=1;
	IN4=0;//右电机正转
}

void keysacn(void)
{
A:    if(K4==0)	  //判断按键是否被按下
	{
	    delay(10);	//延时10ms
		if(K4==0)  //第二次判断按键是否被按下
		{
		    FM=0;		//蜂鸣器响
		    while(K4==0);	//判断按键是否被松开
			FM=1;			//蜂鸣器停止
		}
		else
		{
		    goto A;		 //跳转到A点重新扫描
		}
	}
	else
	{
	    goto A;			//跳转到A点重新扫描
	}

}

void fm(void)	  //蜂鸣器报警函数 可灵活应用
{
   FM=0;
   delay(1000);	 //报警时间1s
   FM=1;
}

void main(void)
{

	keysacn();	   //调用按键扫描函数
    back();		 
	delay(1000); //后退1s
	stop();		 
	delay(500);	 //停止0.5s
	run();		 
	delay(1000); //前进1s
	stop();
	delay(500);	 //停止0.5s
	left();
	delay(1000); //向左转1s
	right();
	delay(1000); //向右转1s
	spin_left();
    delay(2000); //向左旋转2s
	spin_right();
	delay(2000); //向右旋转2s
	stop();		 //停车
	while(1);  //死循环	复位键重新跑程序
	

}












