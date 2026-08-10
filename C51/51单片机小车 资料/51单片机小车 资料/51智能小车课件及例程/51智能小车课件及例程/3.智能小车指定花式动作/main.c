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


void spin_right(void)			  //向右打转函数
{
	EN1=1;
	EN2=1;//电机使能
    IN1=0;
	IN2=1; //左电机正转
	IN3=0;
	IN4=1;//右电机反转
}

void spin_left(void)			  //向左打转函数
{
	EN1=1;
	EN2=1;//电机使能
    IN1=1;
	IN2=0; //左电机反转
	IN3=1;
	IN4=0;//右电机正转
}



void main(void)
{
    int i;
    delay(2000); //延时2s后启动
    run();
	delay(1000);
	back();
	delay(1000);					   //全速前进急停后退（电压足够的情况下会甩尾）
	stop();
	delay(500);

	for(i=0;i<5;i++)
	{
	    run();
		delay(100);						   //小车间断性前进5步
		stop();
		delay(80);
	}

	for(i=0;i<5;i++)
	{
	    back();
		delay(100);					   //小车间断性后退5步
		stop();
		delay(80);
	}

	for(i=0;i<5;i++)
	{
	    left();
		delay(1000);				 //大弯套小弯连续左旋转
		spin_left();
		delay(500);
	}

	for(i=0;i<5;i++)
	{
	    right();
		delay(1000);				 //大弯套小弯连续右旋转
		spin_right();
		delay(500);
	}

	for(i=0;i<10;i++)
	{
	    right();
		delay(100);				 //间断性原地右转弯
		stop();
		delay(100);
	}

	for(i=0;i<10;i++)
	{
	    left();
		delay(100);				 //间断性原地左转弯
		stop();
		delay(100);
	}

	for(i=0;i<10;i++)
	{
	    left();
		delay(300);				 //走S形前进
		right();
		delay(300);
	}

	for(i=0;i<10;i++)
	{
	    spin_left();
		delay(300);				 //间断性原地左打转
		stop();
		delay(300);
	}

	for(i=0;i<10;i++)
	{
	    spin_right();
		delay(300);				 //间断性原地右打转
		stop();
		delay(300);
	}


	while(1);  //死循环	复位键重新跑程序
	

}












