#include <REGX52.H>
#include "LCD1602.h"
#include "MatrxiKeypad.h"

volatile unsigned char BlinkEnable = 0;

void Timer0Init(void)       // 100微秒@12.000MHz
{
    TMOD &= 0xF0;
    TMOD |= 0x01;           // 定时器0，方式1，16位

    TL0 = 0x9C;
    TH0 = 0xFF;

    TF0 = 0;
    ET0 = 1;
    EA  = 1;
    PT0 = 0;

    P1_0 = 0;
    P1_1 = 1;
    P2_3 = 1;

    TR0 = 1;
}

void main(void)
{
    unsigned long KeyValue = 0;
    unsigned char KeyNumber;
    unsigned char Digit;
    unsigned char DigitCount = 0;

    LCD_Init();
    Timer0Init();

    while (1)
    {
        KeyNumber = MatrixKey();

        /*
         * 按键1～9表示数字1～9；
         * 按键10表示数字0；
         * 其他按键暂时不处理。
         */
        if (KeyNumber >= 1 && KeyNumber <= 10)
        {
            Digit = KeyNumber;

            if (Digit == 10)
            {
                Digit = 0;
            }

            if (DigitCount < 7)
            {

                KeyValue *= 10UL;
                KeyValue += Digit;

                ++DigitCount;


                LCD_ShowNum(1, DigitCount, Digit, 1);

                if (KeyValue == 7355608UL)
                {
                    BlinkEnable = 1;
					P1_0 = 1;
                    //LCD_ShowString(2, 1, "LED Blinking");
                }
            }
        }
    }
}

void Timer0_Routine(void) interrupt 1
{
    static unsigned int T0Count = 0;
    static unsigned int T1Count = 1;

    TL0 = 0x9C;
    TH0 = 0xFF;

    if (BlinkEnable)
    {
        ++T0Count;

        /*
         * 初始为：
         * 10000 × 100微秒 = 1秒
         *
         * T1Count逐渐增加后，闪烁逐渐加快。
         */
        if (T0Count >= 40000 / T1Count)
        {
            T0Count = 0;

            P1_0 = !P1_0;
            P1_1 = !P1_1;
            P2_3 = !P2_3;

            /*
             * 限制最大值，防止除法结果最终变成0。
             */
            if (T1Count < 2000)
            {
                ++T1Count;
            }
        }
    }
    else
    {
        T0Count = 0;
        T1Count = 1;
    }
}