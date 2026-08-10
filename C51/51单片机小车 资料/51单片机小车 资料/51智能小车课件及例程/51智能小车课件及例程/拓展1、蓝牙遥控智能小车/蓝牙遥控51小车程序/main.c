/**********************亚博智能小车黑线循迹例程************************
*  平台：BST-V51  + Keil uVision3 + STC89C52RC 
*  名称：智能小车例程
*  公司：深圳市亚博智能科技有限公司     
*  编写：罗工
*  日期：2016-5-10
*  晶振:11.0592MHZ
*  说明：免费开源，不提供源代码分析，有问题直接到交流群交流
*  硬件设置：要有自己动手能力，进行组装接线和传感器灵敏度的调试，才能完成实验
*  使用说明：根据下面IO口自己用杜邦线连接各种模块，可以自己修改各种模块IO口 
******************************************************************/
 //按下K4按键，1秒左右启电小车
 //按下复位健可以停止小车	

#include "reg52.h"	     //包含52系统头文件
#include <string.h>
#include "bst_car.h"	 //包含bst_car.h智能小车头文件

unsigned char pwm_val_left  =0;//变量定义
unsigned char pwm_val_right =0;
unsigned char push_val_left ;// 左电机占空比N/20 //速度调节变量 0-20。。。0最小，20最大
unsigned char push_val_right ;// 右电机占空比N/20 
							   // 大家可以根据循迹效果修改以上两个数值 
bit Right_PWM_ON=1;	           //右电机PWM开关
bit Left_PWM_ON =1;			   //左电机PWM开关

bit startBit = 0;  				//串口接收开始标志位
bit newLineReceived = 0; 		//串口一帧协议包接收完成

unsigned char control=0X03;		//车运动控制全局变量
unsigned char inputString[50];  //接收数据协议

long int distance = 0;               //距离变量
unsigned int timeH, timeL;
unsigned char succeed_flag;

/*小车运行状态枚举*/
enum{
  enSTOP = 0,
  enRUN,
  enBACK,
  enLEFT,
  enRIGHT
}enCarState;

#define 	enMinMin() 	{push_val_left =20;push_val_right =20;}
#define 	enMin()	 	{push_val_left =24;push_val_right =24;}
#define 	enMidle()	{push_val_left =28;push_val_right =28;}
#define		enMax()	 	{push_val_left =32;push_val_right =32;}
#define 	run_car     '1'//按键前
#define 	back_car    '2'//按键后
#define 	left_car    '3'//按键左
#define 	right_car   '4'//按键右
#define 	stop_car    '0'//按键停

int g_volume = 0;
int g_carstate = 0;
char returntemp[] = "$0,0,0,0,0,0,0,0,0,0,0,0000cm,8.2V#";





//延时函数	
void delay(unsigned int xms)				
{
    unsigned int i,j;
	for(i=xms;i>0;i--)		      //i=xms即延时约xms毫秒
    for(j=112;j>0;j--);
}
/******************************************************************************/
/* 函数名称  : delayt                                                         */
/* 函数描述  : 延时函数                                                       */
/* 输入参数  : x                                                              */
/* 参数描述  : 延时时间数据                                                   */
/* 返回值    : 无                                                             */
/******************************************************************************/	
void delayt(unsigned int x)
{
    unsigned char j;
    while(x-- > 0)
    {
  	    for(j = 0;j < 125;j++)
        {
            ;
        }
    }
}

/******************************************************************************/
/* 函数名称  : Trig_SuperSonic                                                */
/* 函数描述  : 发出声波函数                                                   */
/* 输入参数  : 无                                                             */
/* 参数描述  : 无                                                             */
/* 返回值    : 无                                                             */
/******************************************************************************/
void Trig_SuperSonic(void)//发出声波
{
	 OUTPUT = 1;
	 delayt(1);
	 OUTPUT = 0;
}
/******************************************************************************/
/* 函数名称  : Measure_Distance                                               */
/* 函数描述  : 计算距离函数                                                   */
/* 输入参数  : 无                                                             */
/* 参数描述  : 无                                                             */
/* 返回值    : 无                                                             */
/******************************************************************************/
long Measure_Distance(void)
{
	unsigned int  time;
	OUTPUT = 0;
    EA = 1;
	T2MOD = 0X00;
	T2CON = 0x00; //定时器12位工作模式	 自动重装
	while(1)
	{
		EA = 0;
		Trig_SuperSonic();
		while(INPUT == 0);
		succeed_flag = 0;
		EA = 1;
		EX0 = 1;
		TH2 = 0;
		TL2 = 0;
		TR2 = 1;  //开启定时器
		delayt(10);
		TR2 = 0;
		EX0 = 0;
		if(succeed_flag == 1)
		{
			time = timeH*256 + timeL;
			distance = time*0.0172;
			return distance;
		}
		else
		{
			distance = 0;

		}

	}
}

//前进
 void run(void)
{
    //push_val_left=5;	 //速度调节变量 0-20。。。0最小，20最大
	//push_val_right=5;
	Left_moto_go ;   //左电机往前走
	Right_moto_go ;  //右电机往前走
}

//左转
 void leftrun(void)
{	 
     //push_val_left=5;
	 //push_val_right=5;
	 Right_moto_go ;  //右电机往前走
     Left_moto_Stop ;  //左电机停止
//	 delay(100);
//	 Right_moto_Stop;		//微信打开注释 
//	 delay(100);

}

//右转
void  rightrun(void)
{ 
	 //push_val_left=5;
	 //push_val_right=5;
     Left_moto_go  ;   //左电机往前走
	 Right_moto_Stop   ;  //右电机往前走
//	 delay(100);
//	 Left_moto_Stop;	 //微信打开注释 
//	 delay(100);
	
}

//后退
void back(void)
{

   Left_moto_back  ;  // 左轮后退
   Right_moto_back  ;  // 左轮后退
}

//停转
void stop(void)
{
  Right_moto_Stop  ;   //停转
  Left_moto_Stop   ;   //
}


//左旋转
void tleft(void)
{
  Left_moto_go  ;   //左电机往前走
  Right_moto_back  ;  // 左轮后退
}

//右旋转
void tright(void)
{
  Left_moto_back  ;   //左电机往前走
  Right_moto_go ;  // 左轮后退
}




/************************************************************************/
//                   PWM调制电机转速                                   

//                   左电机调速                                        
/*调节push_val_left的值改变电机转速,占空比*/
void pwm_out_left_moto(void)
{  
     if(Left_PWM_ON)
     {
          if(pwm_val_left<=push_val_left)
	      {
	           EN1=1; 
	      }
	      else 
	      {
	           EN1=0;
          }
          if(pwm_val_left>=32)
	      pwm_val_left=0;
     }
     else    
     {
          EN1=0;   //若未开启PWM则EN1=0 左电机 停止
     }
}
/******************************************************************/
/*                    右电机调速                                  */  
void pwm_out_right_moto(void)
{ 
    if(Right_PWM_ON)
    { 
        if(pwm_val_right<=push_val_right)	//20ms内电平信号 111 111 0000 0000 0000 00
	    {
	        EN2=1; 							//占空比6:20
        }
	    else 
	    {
	        EN2=0;
        }
	    if(pwm_val_right>=32)
	    pwm_val_right=0;
    }
    else    
    {
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
	 pwm_out_left_moto();
	 pwm_out_right_moto();
 }	
void exit0() interrupt 0  // 外部中断0  超声波接收
{
	timeH = TH2;
	timeL = TL2;
	succeed_flag = 1;
	EX0 = 0;
}

void timer2()  interrupt 5	 //定时器2
{
	 TF2 = 0;
     TH2 = 0;	  //1Ms定时
	 TL2 = 0;
}
 /******************************************************************/
/* 串口中断程序*/
/******************************************************************/

void UART_SER () interrupt 4
{
	unsigned char n; 	//定义临时变量
	static int num = 0;

	if(RI) 		//判断是接收中断产生
	{
		RI = 0; 	//标志位清零
		n = SBUF; //读入缓冲区的值

		//control=n;
	    if(n == '$')
	    {
	      startBit = 1;
		  num = 0;
	    }
	    if(startBit == 1)
	    {
	       inputString[num] = n;     
	    }  
	    if (n == '#') 
	    {
	       newLineReceived = 1; 
	       startBit = 0;
	    }
		num++;
		if(num >= 50)
		{
			num = 0;
			startBit = 0;
			newLineReceived	= 0;
		}
	}

}


//pwm初始化
void pwmint(void)
{
	TMOD=0X01;
	TH0= 0XFC;  //1ms定时
    TL0= 0X66;
	TR0= 1;
	ET0= 1;
	EA = 1;	    //开总中断

}

//WIFI、蓝牙初始化
void WifiInit(void)
{
   
   	SCON = 0x50; 	// SCON: 模式1, 8-bit UART, 使能接收
	TMOD |= 0x20;
	TH1=0xfd; 		//波特率9600 初值
	TL1=0xfd;
	TR1= 1;
	EA = 1;	    	//开总中断
	ES= 1; 			//打开串口中断


}
//串口发送函数
void PutString(unsigned char *TXStr)  
{                
	ES=0;     
	while(*TXStr!=0) 
	{                      
	  SBUF=*TXStr;
	  while(TI==0);
	  TI=0;    
	  TXStr++;
	}
	ES=1; 
}     
//主函数
void main(void)
{	
    P0 = 0X00;    //关电机	
	P1 = 0xff; 	  //关闭所有LED和风扇
	FIRE = 0;

    pwmint();
	WifiInit();

	while(1)	//无限循环
	{ 
		 
		 distance = Measure_Distance();        //计算脉宽并转换为距离
		 

		if (newLineReceived)
	   	{
			switch(inputString[1])
			{
				case run_car:   g_carstate = enRUN; break;
				case back_car:  g_carstate = enBACK;break;
				case left_car:  g_carstate = enLEFT;break;
				case right_car: g_carstate = enRIGHT;break;
				case stop_car:  g_carstate = enSTOP;break;
				default:g_carstate = enSTOP;break;
			}
			if(inputString[3] == '1')  //左旋转
			{
				TR0= 1;
				tleft();
				delay(2000);//延时2s 
				stop();
				TR0= 0;
			}
			else if(inputString[3] == '2')	// 右旋转
			{
			   	TR0= 1;
				tright();
				delay(2000);//延时2s 
				stop();
				TR0= 0;
			}
			if(inputString[5] == '1')  //鸣笛
			{
				FM = 0;
				delay(1000);
				FM = 1;
			}
			if(inputString[7] == '1')  //加速
			{
				g_volume++;
				if(g_volume>=4)
				{
					g_volume = 4;
				}
			}
			if(inputString[9] == '1')  //减速
			{
				g_volume--;
				if(g_volume<=0)
				{
					g_volume = 1;
				}
			}   
			if(inputString[17] == '1')  //点灯
			{
				LED = (LED == 1)?0:1;  //反转电平 
				delay(200);//延时2s
				LED = (LED == 1)?0:1;  //反转电平
				delay(200);//延时2s
				LED = (LED == 1)?0:1;  //反转电平
				delay(200);//延时2s
				LED = (LED == 1)?0:1;  //反转电平 
				delay(200);//延时2s
				LED = (LED == 1)?0:1;  //反转电平 
				delay(200);//延时2s
				LED = (LED == 1)?0:1;  //反转电平
				delay(200);//延时2s
				LED = (LED == 1)?0:1;  //反转电平
				delay(200);//延时2s
				LED = (LED == 1)?0:1;  //反转电平 
				delay(200);//延时2s
			}
			
			if(inputString[19] == '1')  //灭火
			{
				FIRE = (FIRE == 1)?0:1;
			}        
	      
	       //返回状态
		   //组装超声波数据
			returntemp[23] = (distance / 1000) + 0x30;
			returntemp[24] = (distance / 100 % 10) + 0x30;
			returntemp[25] = (distance / 10 % 10) + 0x30;
			returntemp[26] = (distance % 10 ) + 0x30;


	       PutString(returntemp); //返回协议数据包       
	       
	       newLineReceived = 0;  
		   memset(inputString, 0x00, sizeof(inputString));  
	 
	    }
    
	    switch(g_carstate)
	    {
			case enSTOP: stop();TR0= 0;break;
			case enRUN:run();TR0= 1;break;
			case enLEFT:leftrun();TR0= 1;break;
			case enRIGHT:rightrun();TR0= 1;break;
			case enBACK:back();TR0= 1;break;
			default:stop();TR0= 0;break;
	    }
		switch(g_volume)
		{
			case 1: enMinMin();break;
			case 2: enMin();break;
			case 3: enMidle();break;
			case 4: enMax();break;
			default:enMidle();break;
		}

			 
	 }

}
   


