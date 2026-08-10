#ifndef __BSTCAR_H__
#define __BSTCAR_H__
/************BST-V51智能小车头文件*************/

/*超声波*/
sbit INPUT  = P3^2;                //回声接收端口
sbit OUTPUT = P2^1;                //超声触发端口

#define VELOCITY_30C	3495       //30摄氏度时的声速，声速V= 331.5 + 0.6*温度； 
#define VELOCITY_23C	3453       //23摄氏度时的声速，声速V= 331.5 + 0.6*温度； 


//蜂鸣器驱动口定义
sbit FM=P2^3; 

//定义点灯
sbit LED = P1^0;




#endif