#include <REGX52.H>

void Delay(unsigned int ms)
{
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 120; j++);
}

unsigned char seg_tab[17] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x00};
unsigned char dig_tab[8] = {0xFE, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF, 0xBF, 0x7F};
sbit seg = P2 ^ 6;
sbit dig = P2 ^ 7;
sbit j4 = P2 ^ 3; 

void display_dig(unsigned char num, unsigned char pos)
{
    P0 = 0xFF; // Clear P0
    dig = 1, dig = 0; 
    P0 = seg_tab[num]; // Display number
    seg = 1, seg = 0;
    P0 = dig_tab[pos]; // Select digit position
    dig = 1, dig = 0;
}

void display_scan(unsigned int num)
{
    unsigned char i;
    for (i = 0; i < 8; i++)
    {
        display_dig(num % 10, 7-i);
        num /= 10;
        Delay(1);
    }
    Delay(2);
}


void main(void)
{
    unsigned int time = 0;
    
    while (1)
    {
        display_scan(time);
        time+=10;
    }
}