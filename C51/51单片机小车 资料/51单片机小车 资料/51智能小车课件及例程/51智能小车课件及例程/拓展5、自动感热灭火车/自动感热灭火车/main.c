/**********************亚博智能小车自动感热灭火************************
*  平台：BST-V51  + Keil uVision3 + STC89C52 
*  名称：智能小车例程
*  公司：深圳市亚博智能科技有限公司    
*  编写：罗工
*  日期：2014-9-10
*  晶振:11.0592MHZ
*  说明：免费开源，不提供源代码分析
*  硬件设置：要有自己动手能力，进行组装接线和传感器灵敏度的调试，才能完成实验
******************************************************************/
 //按下K4按键，1秒左右启电小车
 //按下复位健可以停止小车	
 //注意程序只做参考之用，要达到最理想的避障效果，还需要同学们细心调试。

#include <reg52.h>	     //包含52系统头文件
#include "bst_car.h"	 //包含bst_car.h智能小车头文件

unsigned char pwm_val_left  =0;//变量定义
unsigned char pwm_val_right =0;
unsigned char push_val_left =6;// 左电机占空比N/20	//速度调节变量 0-20。。。0最小，20最大
unsigned char push_val_right=6;// 右电机占空比N/20
char pwm=1;	           //PWM开关
char fan_flag=0,done=0,direction=0;// direction 1,左方遇到火焰；2右方遇到火焰
unsigned int fire_count=0;

//延时函数	
void delay(unsigned int xms)				
{
    unsigned int i,j;
	for(i=xms;i>0;i--)		      //i=xms即延时约xms毫秒
    for(j=112;j>0;j--);
}

//前进
 void run(void)
{
    //push_val_left=5;	 //速度调节变量 0-20。。。0最小，20最大
	//push_val_right=5;
	Left_moto_go ;   //左电机往前走
	Right_moto_go ;  //右电机往前走
}
//停止
 void stop(void)
{
    //push_val_left=5;	 //速度调节变量 0-20。。。0最小，20最大
	//push_val_right=5;
	Left_moto_Stop ;   //左电机往前走
	Right_moto_Stop ;  //右电机往前走
}

//左退
void  leftback(void)
{ 
	 //push_val_left=5;
	 //push_val_right=5;
     Left_moto_back  ;   //左电机往前走
	 Right_moto_go   ;  //右电机停止	
}

//右退
void  rightback(void)
{ 
	 //push_val_left=5;
	 //push_val_right=5;
     Right_moto_back  ;   //左电机往前走
	 Left_moto_go   ;  //右电机停止	
}

/************************************************************************/
//                   PWM调制电机转速                                   

//                   左电机调速                                        
/*调节push_val_left的值改变电机转速,占空比*/
void pwm_out_moto(void)
{  
     if(pwm)
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
     }
     else    
     {
          EN1=0;   //若未开启PWM则EN1=0 左电机 停止
		  EN2=0;	  //若未开启PWM则EN2=0 右电机 停止
     }
}
       
       
//TIMER0中断服务子函数产生PWM信号
void timer0()interrupt 1 using 2
{
     TH0=0XFC;	  //1Ms定时
	 TL0=0X66;
	 pwm_val_left++;
	 pwm_val_right++;
	 pwm_out_moto();
	 if(fire_count>200)
	 {
	 	fan_flag=0;
		fire_count=0;
		fan=1;
		done=1;
	}
	if(Left_2_led==1&&Right_2_led==1&&fan_flag==1)
	 	fire_count++;	   
	fan=0;
}	

void keyscan(void)              //按键扫描函数
{
    A:    if(K4==0)			//判断是否有按下信号
		{
		    delay(10);		  //延时10ms
			if(K4==0)			//再次判断是否按下
			 {
			    FM=0;               //蜂鸣器响  		
			    while(K4==0);	//判断是否松开按键
			    FM=1;               //蜂鸣器停止  
		 	 }
		    else
		     {
		       goto A;        //跳转到A重新检测
	              }
		}
		else
		{
		  goto A;             //跳转到A重新检测
		}
}


//主函数
void main(void)
{	
    P1=0X00;    //关电机	
    keyscan();	//按键启动检测
	delay(1000);//1s后启动

	TMOD=0X01;
    TH0= 0XFC;  //1ms定时
    TL0= 0X66;
    TR0= 1;
    ET0= 1;
	EA = 1;	    //开总中断


	while(1)	//无限循环
	{ 
			//有信号为0  没有信号为1
			if((Right_2_led==0&&Left_2_led==0)||fan_flag)		//两边传感器同时检测到障碍物
		    {	  
				 pwm=0;
				 stop();
				 fan_flag=1;
				 fan=1;
			}
	        else if(Left_2_led==1&&Right_2_led==1)
		    {
				pwm=1;
				 leftback();
				 delay(50);		           
				 stop();
				 delay(100);
				 fan=0;
			}		  
			else if(Left_2_led==0&&Right_2_led==1)	    //左边检测到障碍物
			{
				 pwm=1;
				 leftback();
				 delay(50);		           
				 stop();
				 delay(300);
				 fan=0;    
			}			   
			else if(Right_2_led==0&&Left_2_led==1)		//右边检测到障碍物
			{	  
				 pwm=1;
				 rightback();
				 delay(50);
				 stop();
				 delay(300);
				 fan=0;	
                
			}	 
	 }
}
   


