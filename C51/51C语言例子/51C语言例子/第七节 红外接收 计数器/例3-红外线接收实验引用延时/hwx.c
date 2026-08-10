/***************************************************************************
标题：	NEC红外线接收实验引用延时
效果：	运行程序，按遥控器按键，在数码管上显示相应的地址码-控制码（以16进制显示）
		分两段，前段是地址码，后段为控制码，用点隔开，显示两字节，忽略反码
工作于：LY5A-L2A开发板
作者：	林洋电子吧
网站：	www.lydz8.com
******************************************************************************/
//头文件:
#include "reg51.h"

//IO引脚定义:
sbit hwx=P3^3;		//红外接收数据引脚，
sbit SMG_q = P1^0;	//定义数码管阳级控制脚（千位）
sbit SMG_b = P1^1;	//定义数码管阳级控制脚（百位）
sbit SMG_s = P1^2;	//定义数码管阳级控制脚（十位）
sbit SMG_g = P1^3;	//定义数码管阳级控制脚（个位）
/********数据定义*************************************************************/
code unsigned char table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,
							0x88,0x8c,0xc6,0xa1,0x86,0x8e};	//共阳数码管段值表 0-9 a-f

unsigned char l_posit=0;	//显示位置

unsigned char ly_disdate[4]={0,0,0,0};		//显示缓冲
unsigned char ly_lhj[4];					//保存NEC的四个字节数据
unsigned char ly_ct=0;
bit ly_flag=1;								//成功接收标志

//函数声明:
void display();//定义显示函数，直接显示缓冲区数值
void delay(void); 
void delay100us(void);


/***********主函数开始********************************************************/	
void main(void)
{
	EA=1;					//首先开启总中断
	EX1=1;  				//开启外部中断1,红外接收数据引脚
	IT1=1;        			//设置成下降沿触发方式
	while(1){	
		if(ly_flag){			//接收成功处理显示缓冲，以16进制显示
			ly_flag=0;
			ly_disdate[0]=ly_lhj[0]/16;
			ly_disdate[1]=ly_lhj[0]%16;
			ly_disdate[2]=ly_lhj[2]/16;
			ly_disdate[3]=ly_lhj[2]%16;
		}
		display();//显示缓冲内容
		delay();	
	}		

}

/***********外中断1入口函数，P33引脚，红外线接收IC数据脚**************************/
void hongwai(void)   interrupt 2
{
	unsigned char i,ia;
	/**************开始判断是否为NEC波形引导码的前9MS和后4.5MS******************************/
	ly_ct=0;			//计数时间清0
	while(!hwx)
		delay100us();		//调用0.1MS延时计数，ly_ct每调用一次加1
	if(ly_ct<80||ly_ct>100)	//NEC引导码前9MS，ly_ct约等于90,给个误差值，用80-100之间来判断
		return;

	ly_ct=0;
	while(hwx){	
		delay100us();
		if(ly_ct>50)		//NEC引导码引导码的后4。5MS，ly_ct约45
			return;		
	}
	if(ly_ct<40)			//NEC引导码引导码的后4。5MS，ly_ct约45
		return;

	/***********开始接收四个字节内容**************************************/	
	for(i=0;i<4;i++){
		for(ia=0;ia<8;ia++){
			while(!hwx);		//低电平开始，不处理只等待高电平接收		
			
			ly_ct=0;
			while(hwx){			//高电平开始，
				delay100us();
				if(ly_ct>20)		
					return;		
			}
			//高电平结束，判断数据1或0向变量移入
			ly_lhj[i]>>=1;			//数据由高位移入低位
			if(ly_ct>10)				//时间量TH1高于10，即高于1MS判断为1
				ly_lhj[i]|=0x80;
		}
	}
	ly_flag=1;	//接收成功
	TF1=0;
}
//显示函数，参数为显示内容
void display()
{
	P0=0XFF;			//	
	switch(l_posit){
	case 0:		//选择千位数码管，关闭其它位
		SMG_q=0;
		SMG_b=1;	
		SMG_s=1;		
		SMG_g=1;
		P0=table[ly_disdate[0]];	//输出显示内容
		break;
	case 1:		//选择百位数码管，关闭其它位
		SMG_q=1;
		SMG_b=0;	
		SMG_s=1;		
		SMG_g=1;
		P0=table[ly_disdate[1]]&0x7f;	//加上小数点
		break;
	case 2:		//选择十位数码管，关闭其它位
		SMG_q=1;
		SMG_b=1;	
		SMG_s=0;		
		SMG_g=1;
		P0=table[ly_disdate[2]];
		break;
	case 3:		//选择个位数码管，关闭其它位
		SMG_q=1;
		SMG_b=1;	
		SMG_s=1;		
		SMG_g=0;
		P0=table[ly_disdate[3]];
		break;
	}
	l_posit++;		//每调用一次将轮流显示一位
	if(l_posit>3)
		l_posit=0;	
}

//延时子函数,短暂延时
void delay(void){		
	unsigned char i=10;
	while(i--);
}
void delay100us(void)
{
	unsigned char i=15;
	while(i--);
	ly_ct++;
}
