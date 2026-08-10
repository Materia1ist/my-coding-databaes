/**********************亚博智能小车例程************************
*  平台：BST-V51  + Keil uVision3 + STC89C52 
*  名称：智能小车例程
*  公司：深圳市亚博软件开发有限公司
*  淘宝：http://bstmcu.taobao.com       
*  编写：罗工
*  日期：2014-9-11
*  晶振:11.0592MHZ
*  说明：免费开源，不提供源代码分析，有问题直接到交流群交流
*  QQ交流群：217588580 
*  硬件设置：要有自己动手能力，进行组装接线和传感器灵敏度的调试，才能完成实验
*  使用说明：根据下面IO口自己用杜邦线连接各种模块，可以自己修改各种模块IO口

*  本实验需要使用LCD1602液晶屏 注意调节开发板上SW1对比度，用电脑USB供电时调大一点，用电池供电时调小一点对比度。

*  学习建议：进行智能小车程序学习前，可先看51单片机开发板配套28课视频教程
 
******************************************************************/
 //上电后按下K4键程序运行，小车进行超声波避障跑
 //LCD1602液晶屏上显示探测到的实时距离

/**************************************************************
//重要说明：没有LCD1602液晶显示屏的同学，需要用杜邦线将P0.7接地程序才能正常运行
****************************************************************/

//注意程序只做参考之用，要达到最理想的避障效果，还需要同学们细心调试。

#include <reg52.h>	   //52芯片配置文件
#include <intrins.h>   //包含nop等系统函数
#include "bst_car.h"   //包含bst—v51智能小车头文件

#define LCM_Data  P0   //定义液晶屏数据口
#define Busy    0x80   //用于检测LCM状态字中的Busy标识

sbit DU = P2^6;		   //数码管段选
sbit WE = P2^7;		   //数码管位选


sbit pwm = P2^7;//输出PWM信号
unsigned char count=0;
unsigned char SEH_count = 10;  //朝向前面

int LeftDistance = 0, RightDistance = 0;
unsigned long ultrasonic[5] = {0};

unsigned char hongwai = 0; //有红外监测则停止前进标志位

sbit LCM_RW=P1^1 ;     //定义LCD引脚
sbit LCM_RS=P1^0 ;
sbit LCM_E=P2^5	 ;

unsigned char code Range[] ="==Range Finder==";//LCD1602显示格式
unsigned char code ASCII[13] = "0123456789.-M";
unsigned char code table[]="Distance:000.0cm";
unsigned char code table1[]="!!! Out of range";

unsigned char disbuff[4]={0,0,0,0};//用于分别存放距离的值0.1mm、mm、cm和m的值

unsigned int  time=0;//用于存放定时器时间值
unsigned long S = 0;//用于存放距离的值
bit  flag =0; //量程溢出标志位
char a=0; 
int ax;


unsigned char pwm_val_left  =0;//变量定义
unsigned char pwm_val_right =0;
unsigned char push_val_left =8;// 左电机占空比N/20 //速度调节变量 0-20。。。0最小，20最大
unsigned char push_val_right=8;// 右电机占空比N/20 
unsigned char pwmcount = 0;
//=========================================================================================================================
void delay(unsigned int xms)				
{
    unsigned int i,j;
	for(i=xms;i>0;i--)		      //i=xms即延时约xms毫秒
    for(j=112;j>0;j--);
}

void Delay10us(unsigned int i)    	//10us延时函数 启动超声波模块时使用
{ 
   	unsigned int j; 
	do
	{ 
  		j = 10; 
  		do
		{ 
   			_nop_(); 
   		}
		while(--j); 
	}
	while(--i); 
}  

void cmg88()//关数码管
{
    DU=1;  
    P0=0X00;
    DU=0;
}
/************************************LCD1602液晶屏驱动函数************************************************/
//*******************读状态*************************//
unsigned char ReadStatusLCM(void)
{
	LCM_Data = 0xFF; 
	LCM_RS = 0;
	Delay10us(1); 
	LCM_RW = 1;
	Delay10us(1); 
	do{
		LCM_E = 0;
		Delay10us(1); 
		LCM_E = 0;
		Delay10us(1); 
		LCM_E = 1;
		Delay10us(1); 
	}
	while (LCM_Data & Busy); //检测忙信号
	return(LCM_Data); 
}

/****************写数据************************/
void WriteDataLCM(unsigned char WDLCM) 
{
	ReadStatusLCM(); //检测忙
	LCM_Data = WDLCM;
	LCM_RS = 1;
	Delay10us(1); 
	LCM_RW = 0;
	Delay10us(1); 
	LCM_E = 0; //若晶振速度太高可以在这后加小的延时
	Delay10us(1); 
	LCM_E = 0; //延时
	Delay10us(1); 
	LCM_E = 1;
	Delay10us(1); 
}

//****************写指令*************************//
void WriteCommandLCM(unsigned char WCLCM,BuysC) //BuysC为0时忽略忙检测
{
	if (BuysC) ReadStatusLCM(); //根据需要检测忙
	LCM_Data = WCLCM;
	LCM_RS = 0;
	Delay10us(1); 
	LCM_RW = 0;	
	Delay10us(1); 
	LCM_E = 0;
	Delay10us(1); 
	LCM_E = 0;
	Delay10us(1); 
	LCM_E = 1;
	Delay10us(1); 
}



//*******************LCM初始化**********************//
void LCMInit(void) 
{
	LCM_Data = 0;
	WriteCommandLCM(0x38,0); //三次显示模式设置，不检测忙信号
	delay(5); 
	WriteCommandLCM(0x38,0);
	delay(5); 
	WriteCommandLCM(0x38,0);
	delay(5); 

	WriteCommandLCM(0x38,1); //显示模式设置,开始要求每次检测忙信号
	WriteCommandLCM(0x08,1); //关闭显示
	WriteCommandLCM(0x01,1); //显示清屏
	WriteCommandLCM(0x06,1); // 显示光标移动设置
	WriteCommandLCM(0x0c,1); // 显示开及光标设置
}

//*********************按指定位置显示一个字符***********************//
void DisplayOneChar(unsigned char X, unsigned char Y, unsigned char DData)
{
	Y &= 0x1;
	X &= 0xF; //限制X不能大于15，Y不能大于1
	if (Y) X |= 0x40; //当要显示第二行时地址码+0x40;
	X |= 0x80; //算出指令码
	WriteCommandLCM(X, 1); //发命令字
	WriteDataLCM(DData); //发数据
}

//**********************按指定位置显示一串字符*************************//
void DisplayListChar(unsigned char X, unsigned char Y, unsigned char code *DData)
{
	unsigned char ListLength;

  	ListLength = 0;
	Y &= 0x1;
	X &= 0xF; //限制X不能大于15，Y不能大于1
	while (DData[ListLength]>0x19) //若到达字串尾则退出
	{
		if (X <= 0xF) //X坐标应小于0xF
		{
			DisplayOneChar(X, Y, DData[ListLength]); //显示单个字符
			ListLength++;
			X++;
		}
	}
}


/***************************************************************************/


void  StartModule() 		         //启动超声波模块
{
	  TX=1;			                     //启动一次模块
      Delay10us(2);
	  TX=0;
}

 void Forward(int ms)//前进
{
	 IN2=1;
	 IN3=1;

	 IN1=0;
	 IN4=0;
	 delay(ms);
}

void Stop(void)	//停车
{

	 IN1=0; 
	 IN2=0;
	 IN3=0;
	 IN4=0;
//	 delay(ms);
}

void back(int ms)	//后退
{

	 IN1=1; 
	 IN2=0;
	 IN3=0;
	 IN4=1;
	 delay(ms);
}    
void Turn_Right(void)	 //向右旋转
{
    
	IN2=1;
	IN3=0;

	IN1=0; 
	IN4=1;
//	delay(ms);
}
void Turn_Left(void)	 //向右旋转
{
   	IN2=0;
	IN3=1;

	IN1=1;
	IN4=0;
//	delay(ms);
}
//=========================================================================================================================
/********距离计算程序***************/
unsigned long conut1(void)
{
	unsigned long dis = 0;
	time=TH1*256+TL1;
	TH1=0;
	TL1=0;
	
   //此时time的时间单位决定于晶振的频率，外接晶振为11.0592MHZ
   //那么1us声波能走多远的距离呢？1s=1000ms=1000000us 
   // 340/1000000=0.00034米
   //0.00034米/1000=0.34毫米  也就是1us能走0.34毫米
   //但是，我们现在计算的是从超声波发射到反射接收的双路程，
   //所以我们将计算的结果除以2才是实际的路程
    dis=time*0.17+10;//此时计算到的结果为毫米，并且是精确到毫米的后两位了，有两个小数点 
	return dis;
}

//冒泡排序
void bubble(unsigned long *a, int n) /*定义两个参数：数组首地址与数组大小*/

{
	int i,j,temp;	
	for(i = 0;i < n-1; i++)	
	{	
		for(j = i + 1; j < n; j++) /*注意循环的上下限*/
		{
			if(a[i] > a[j])
			{
				temp = a[i];		
				a[i] = a[j];		
				a[j] = temp;			
			}
		}
	}

}
unsigned long Distance(void)
{
	int num = 0;
	unsigned long Distance = 0;


	while(num < 5) // 测5次数据
	{
		RX = 1;
		StartModule(); 				
	    while(RX==0);    
	
		TR1=1;			    //开启计数
	    while(RX);			//当RX为1计数并等待
	    TR1=0;				//关闭计数
	    
		S = conut1();
		ultrasonic[num] = S;
		num++;
	}
	num = 0;
	bubble(ultrasonic, 5);
	Distance = (ultrasonic[1]+ultrasonic[2]+ultrasonic[3])/3; //去掉最大和最小取中间平均值   
	return Distance;
}

void DisplayLCD1602(unsigned long v_s)
{
  	if((v_s>=5000)||flag==1) //超出测量范围
	{
	    flag=0;
        DisplayListChar(0, 1, table1);
	}
	else
	{
        disbuff[0]=v_s%10;
	    disbuff[1]=v_s/10%10;
	    disbuff[2]=v_s/100%10;
	    disbuff[3]=v_s/1000;
	    DisplayListChar(0, 1, table);
	    DisplayOneChar(9, 1, ASCII[disbuff[3]]);
	    DisplayOneChar(10, 1, ASCII[disbuff[2]]);	
	    DisplayOneChar(11, 1, ASCII[disbuff[1]]);
        DisplayOneChar(12, 1, ASCII[10]);
	    DisplayOneChar(13, 1, ASCII[disbuff[0]]);
	 }
}
void Deal(void)
{
	unsigned long Dis = 0;
	Dis = Distance();
	DisplayLCD1602(Dis);
	

	  if(S<100)
	 { 

	   back(0);  //后退缓冲

	 }
	 else if(S>100&&S<300)
	 {


	    Forward(0);	//无障碍物 直行


	 }
	 else Stop();


	 


	 
}

/********************************************************/
void zd0() interrupt 3 		 //T0中断用来计数器溢出,超过测距范围
{
    flag=1;			 //中断溢出标志
	RX=0;
}

/********************************************************/
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
          if(pwm_val_left>=20)
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
	    if(pwm_val_right>=20)
	    pwm_val_right=0;
    }
    else    
    {
        EN2=0;	  //若未开启PWM则EN2=0 右电机 停止
    }
} 



/********************************************************/ 
 /*车速控制*/
void InitPWMTimer(void)
{
	TMOD |= 0x01;//开定时器0
  	TH0 = 0xff;   //配置定时器0初值，溢出时间为0.1ms
    TL0 = 0xa3;
	
	EA=1;//开总断
	TR0=1;//开定时器0
	ET0=1;
}

void timer0(void) interrupt 1//定时器0中断函数
{
 	TR0 = 0;      //关闭定时器0
    TH0 = 0xff;   //重装初值0.1ms
    TL0 = 0xa3;
    //舵机1
    if(count <= SEH_count) //控制占空比左右
    {
        //如果count的计数小于（5-25）也就是0.5ms-2.5ms则这段小t周期持续高电平。产生方波
        pwm = 1;
    }
    else
    {
        pwm = 0;
		//TR0 = 0; //关定时器0
    }

	count++;
	pwmcount++;
    if (count >= 200) //T = 20ms则定时器计数变量清0
    {
        count = 0;
    }
	if(pwmcount >= 10)
	{
		pwm_val_left++;
		pwm_val_right++;
		pwm_out_left_moto();
		pwm_out_right_moto();
		pwmcount = 0;
	}

    TR0 = 1; //开启定时器0
}

/*************主程序********************/
void main(void)
{

	cmg88();//关数码管
	delay(400); //启动等待，等LCM讲入工作状态
	LCMInit(); //LCM初始化
	delay(5);//延时片刻

	DisplayListChar(0, 0, Range);
	DisplayListChar(0, 1, table);
    
	TMOD=TMOD|0x10;//设T1为方式1，GATE=1；
    EA=1;					   //开启总中断
    TH1=0;
    TL1=0;          
    ET1=1;             //允许T1中断
    

 	InitPWMTimer();	 //初始化舵机PWM
	//=======================================================================================================================			
	keyscan() ;  //按键扫描
	while(1)
	{
	        
	    //判断红外避障是否触发
		if(Left_2_led == 0 && Right_2_led == 0)
		{
			back(1);
		}
		else if(Left_2_led == 1 && Right_2_led == 0)
		{
			stop();
		}
		else if(Left_2_led == 1 && Right_2_led == 1)
		{
			Forward(1);	
		}

		//Deal();
    
   	}

} 



                            