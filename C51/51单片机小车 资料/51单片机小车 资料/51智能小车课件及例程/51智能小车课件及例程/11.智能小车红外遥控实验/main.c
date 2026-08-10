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

*  学习建议：进行智能小车程序学习前，可先看51单片机开发板配套28课视频教程
 
******************************************************************/
 //上电后小车直接进入待命状态，通过遥控控制小车前后左右停

/**************************************************************
//重要说明：一定要把P3.2 IO口上的杜邦线取下，程序才能正常运行
//因为P3.2为单片机外部中断触发脚，本实验采用外部中断方式判断红外信号
****************************************************************/

//遥控器对应小车前后左右位置请看红外摇控器编码说明图
		
#include<reg52.h>
#include"bst_car.h"
   

#define Imax 14000    //此处为晶振为11.0592时的取值, 
#define Imin 8000    //如用其它频率的晶振时,
#define Inum1 1450    //要改变相应的取值。
#define Inum2 700 
#define Inum3 3000 

unsigned char f=0;
unsigned char Im[4]={0x00,0x00,0x00,0x00};
unsigned char show[2]={0,0};
unsigned long m,Tc;
unsigned char IrOK;

   
/************************************************************************/	
//延时函数	
   void delay(unsigned int k)
{    
     unsigned int x,y;
	 for(x=0;x<k;x++) 
	   for(y=0;y<2000;y++);
}
/************************************************************************/	
//外部中断解码程序
void intersvr0(void) interrupt 1 using 1
{
    Tc=TH0*256+TL0;      //提取中断时间间隔时长
    TH0=0; 
    TL0=0;              //定时中断重新置零
    if((Tc>Imin)&&(Tc<Imax))
    { 
        m=0;
        f=1;
        return;
    }       //找到启始码

    if(f==1)
    {
        if(Tc>Inum1&&Tc<Inum3) 
        {
            Im[m/8]=Im[m/8]>>1|0x80; m++; 
        }
        if(Tc>Inum2&&Tc<Inum1) 
        {
         Im[m/8]=Im[m/8]>>1; m++; //取码
        }
        if(m==32) 
        {
         m=0;  
         f=0;
         if(Im[2]==~Im[3]) 
        {
           IrOK=1; 
        }
        else IrOK=0;   //取码完成后判断读码是否正确
        }
               //准备读下一码
   }
 
}
/************************************************************************/
//全速前进
void  run(void)
{  
	 Left_moto_go ;   //左电机往前走
	 Right_moto_go ;  //右电机往前走
}

//全速后退
     void  backrun(void)
{
	 Left_moto_back ;   //左电机后退
	 Right_moto_back ;  //右电机后退
}

//右转
     void  rightrun(void)
{
	 Left_moto_go ;   //左电机前进
	 Right_moto_Stop ;  //右电机停止
}

//左转
     void  leftrun(void)
{
	 Left_moto_Stop ;   //左电机停止
	 Right_moto_go ;  //右电机前进
}
//STOP
     void  stoprun(void)
{
	 Left_moto_Stop ;   //左电机停止
	 Right_moto_Stop ;  //右电机停止
}


/*********************************************************************/		 
/*--主函数--*/
void main(void)
{
	 
    m=0;
    f=0;

    IT0=1;
    EX0=1;
 
    TMOD=0x11;  
    TH0=0;
	TL0=0;
    TR0=1;
	EA=1;



	
	delay(100);	   


	while(1)							/*无限循环*/
	{ 

	    if(IrOK==1) 			  //如果处理好后进行红外处理
        {
           	switch(Im[2])
   		   {
            case 0x18:  run(); 			     //前进
                        break;
            case 0x52:  backrun();  			 //后退	 
                        break;
            case 0x08:  leftrun(); 			 //左转
                        break;
	        case 0x5A:  rightrun(); 			 //右转
                        break;
	        case 0x1C:  stoprun();			     //停止
                        break;
	        default:break;

   		    }

           IrOK=0;
        }
	 
					 
	 }
}
		