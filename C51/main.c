#include <REGX52.H>

void delay();

void main(void) 
{
    char table[4] = {0x89, 0x88, 0xc7, 0xc0};
    P1 = 0xf0;
    while(1)
    {
      int i;
       for(i = 0; i < 4; i++)
       {
           P0 = table[i];
           P1 = ~(0x10 << i);
           delay();
           P1 = 0x00;
       }
    }
}

void delay()
{
    unsigned char i;
    for(i = 0; i < 200; i++)
    {}
}