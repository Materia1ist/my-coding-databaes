#include <REGX52.H>
#include "lcd.h"

void main()
{
    LCD_Init();          // 先初始化
    LCD_ShowString(1, 1, "Hello world!"); // 显示字符串
    LCD_ShowNum(2, 1, 1145, 6); // 显示数字
    while(1)
    {
    }
}