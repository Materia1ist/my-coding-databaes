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

void display(unsigned char num, unsigned char pos)
{
    P0 = 0xFF; // Clear P0
    dig = 1, dig = 0; 
    P0 = seg_tab[num]; // Display number
    seg = 1, seg = 0;
    P0 = 0x00;//dig_tab[pos]; // Select digit position
    dig = 1, dig = 0;
}

void main(void)
{
    while (1)
    {
        unsigned char a;
        for (a = 0; a < 16; a++)
        {
            display(a, a);
            if(a % 2 == 1)
            {
                j4 = 1;
            }
            else
            {
                j4 = 0;
            }
            Delay(500);
        }
    }
}