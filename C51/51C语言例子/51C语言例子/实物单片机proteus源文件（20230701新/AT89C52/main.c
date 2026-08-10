#include <REGX52.H>

void delay(void);

void main(void) 
{
    unsigned char table[4] = {0x89, 0x88, 0xc7, 0xc0};
    unsigned char n[4]    = {0xfe, 0xfd, 0xfb, 0xf7};
    unsigned char i;

    P1 = 0xf0;
    P2 = 0x00;
    while(1)
    {
        for(i = 0; i < 4; i++)
        {
            P1 = 0xff;          // 先关位选，消残影
            P0 = table[i];      // 送段码
            P1 = n[i];          // 开位选
            delay();
            P0 = 0x00;          // 消隐
        }
    }
}

void delay(void)
{
    unsigned int i;
    for(i = 0; i < 100; i++)
    {}
}