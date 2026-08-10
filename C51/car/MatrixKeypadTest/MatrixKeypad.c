#include <REGX52.H>

void Delay(unsigned int ms)
{
    unsigned char i, j;
	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
}


unsigned char MatrixKey()
{
    unsigned char KeyValue = 0;
    P3 = 0xFF; 
    P3_4 = 0;
    if (P3_0 == 0)
    {
        Delay(20);
        if (P3_0 == 0)
        {
            while (P3_0 == 0);
            KeyValue = 1;
        }
    }
    else if (P3_1 == 0)
    {
        Delay(20);
        if (P3_1 == 0)
        {
            while (P3_1 == 0);
            KeyValue = 2;
        }
    }
    else if (P3_2 == 0)
    {
        Delay(20);
        if (P3_2 == 0)
        {
            while (P3_2 == 0);
            KeyValue = 3;
        }                                                                                                                           
    }
}