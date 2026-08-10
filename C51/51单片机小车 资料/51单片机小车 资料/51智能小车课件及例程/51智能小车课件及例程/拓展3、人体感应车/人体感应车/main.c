/**********************BST-V51实验开发板例程************************
*  平台：BST-V51 + Keil U3 + STC89C52
*  名称：人体感应车
*  公司：深圳市亚博智能科技有限公司       
*  日期：2015-6
*  晶振:11.0592MHZ
*  围绕人体转圈，人体在感应范围内活动的时候，数码管显示“people”，小车打圈
*  没有活动的时候显示“no body”，小车停下来
******************************************************************/
#include<reg52.h>    //包含单片机寄存器的头文件
#include <intrins.h> 

sbit sensor=P1^0;
sbit DU=P2^6;
sbit WE=P2^7;

sbit IN1=P1^2; // 高电平1 后退（反转）
sbit IN2=P1^3; // 高电平1 前进（正转）

sbit IN3=P1^6; // 高电平1 前进（正转）	
sbit IN4=P1^7; // 高电平1 后退（反转）

sbit EN1=P1^4; // 高电平使能 
sbit EN2=P1^5; // 高电平使能 

unsigned int time_count=0,speed_count=0;
char flag=0;

unsigned char pwm_val_left  =0;//变量定义
unsigned char pwm_val_right =0;
unsigned char push_val_left =13;// 左电机占空比N/20 //速度调节变量 0-20。。。0最小，20最大
unsigned char push_val_right=20;// 右电机占空比N/20 

unsigned char nobody[]={0x00,0x54,0x5c,0x00,0x7c,0x5c,0x5e,0x6e},
			  people[]={0x00,0x73,0x79,0x3f,0x73,0x38,0x79,0x00},
			  wei[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
/*------------------------------------------------
               前进函数
------------------------------------------------*/
void run(void)			  //向右打转函数
{
    IN1=0;
	IN2=1; //左电机正转
	IN3=1;
	IN4=0;//右电机反转
}
/*------------------------------------------------
               停止函数
------------------------------------------------*/
void stop(void)			  //停止函数
{
	EN1=1;					   
	EN2=1;//电机使能
    IN1=0;
	IN2=0; //左电机不动
	IN3=0;
	IN4=0;//右电机正转
}
/*------------------------------------------------
               数码管显示函数
------------------------------------------------*/
void dispaly(char body)
{
	char i;
	if(body)
	{
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
		run();
	}
	else
	{
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
		stop();
	}	
}
/************************************************************************/
//                   PWM调制电机转速                                   

//                   左电机调速                                        
/*调节push_val_left的值改变电机转速,占空比*/
void pwm_out_moto(void)
{  
     if(flag)
     {
          if(pwm_val_left<=push_val_left)
	      {
	           EN1=1; 
	      }
	      else 
	      {
	           EN1=0;
          }
          if(pwm_val_left>=20)
	      pwm_val_left=0;

		if(pwm_val_right<=push_val_right)	//20ms内电平信号 111 111 0000 0000 0000 00
	    {
	        EN2=1; 							//占空比6:20
        }
	    else 
	    {
	        EN2=0;
        }
	    if(pwm_val_right>=20)
	    pwm_val_right=0;
	  /*
		speed_count++;
	 	if(speed_count>1000)
	 	{
			speed_count=0;
			push_val_right--;
		  	push_val_left--;
			if(push_val_right<5)
				push_val_right=5;
			if(push_val_left<5)
				push_val_left=5;
		}
		*/
     }
     else    
     {
          EN1=0;   //若未开启PWM则EN1=0 左电机 停止
		  EN2=0;	  //若未开启PWM则EN2=0 右电机 停止
		  speed_count=0;
		  push_val_right=13;
		  push_val_left=20;
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
               定时器1初始化函数
------------------------------------------------*/
void timer1_init()
{
	TMOD = 0x01; //定时器0选择工作方式1
	TH1=0XFC;	  //1Ms定时
	TL1=0X66;
    EA = 1;			 //打开总中断
    ET1 = 1;		 //打开定时器0中断
    TR1 = 1;		 //启动定时器0
}
/*------------------------------------------------
                    主函数
------------------------------------------------*/

main()
{  
	timer0_init();
	timer1_init();
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
	if(time_count>25)//2500ms,封锁时间2.5s 为50，设置为25的话，余后还有1s的封锁时间。
	{
		time_count=0;
		flag=0;
	}
		
}

//TIMER0中断服务子函数产生PWM信号
void timer1()interrupt 3
{
     TH1=0XFC;	  //1Ms定时
	 TL1=0X66;
	 pwm_val_left++;
	 pwm_val_right++;
	 pwm_out_moto();
 }