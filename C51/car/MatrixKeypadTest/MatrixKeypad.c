#include <REGX52.H>

void Delay(unsigned int ms)
{
    unsigned char i, j;
    i = 2;
    j = 239;
    do
    {
        while (--j)
            ;
    } while (--i);
}

unsigned char MatrixKey()
{
    unsigned char KeyValue = 0;

    P3 = 0xFF;
    P3_0 = 0;
    if (P3_4 == 0)
    {
        Delay(20);
        if (P3_4 == 0)
        {
            while (P3_4 == 0);
            KeyValue = 1;
        }
    }
    if (P3_5 == 0)
    {
        Delay(20);
        if (P3_5 == 0)
        {
            while (P3_5 == 0)
                ;
            KeyValue = 2;
        }
    }
    if (P3_6 == 0)
    {
        Delay(20);
        if (P3_6 == 0)
        {
            while (P3_6 == 0)
                ;
            KeyValue = 3;
        }
    }
    if (P3_7 == 0)
    {
        Delay(20);
        if (P3_7 == 0)
        {
            while (P3_7 == 0)
                ;
            KeyValue = 4;
        }
    }

    P3 = 0xFF;
    P3_1 = 0;
    if (P3_4 == 0)
    {
        Delay(20);
        if (P3_4 == 0)
        {
            while (P3_4 == 0)
                ;
            KeyValue = 5;
        }
    }
    if (P3_5 == 0)
    {
        Delay(20);
        if (P3_5 == 0)
        {
            while (P3_5 == 0)
                ;
            KeyValue = 6;
        }
    }
    if (P3_6 == 0)
    {
        Delay(20);
        if (P3_6 == 0)
        {
            while (P3_6 == 0)
                ;
            KeyValue = 7;
        }
    }
    if (P3_7 == 0)
    {
        Delay(20);
        if (P3_7 == 0)
        {
            while (P3_7 == 0)
                ;
            KeyValue = 8;
        }
    }

    P3 = 0xFF;
    P3_2 = 0;
    if (P3_4 == 0)
    {
        Delay(20);
        if (P3_4 == 0)
        {
            while (P3_4 == 0)
                ;
            KeyValue = 9;
        }
    }
    if (P3_5 == 0)
    {
        Delay(20);
        if (P3_5 == 0)
        {
            while (P3_5 == 0)
                ;
            KeyValue = 10;
        }
    }
    if (P3_6 == 0)
    {
        Delay(20);
        if (P3_6 == 0)
        {
            while (P3_6 == 0)
                ;
            KeyValue = 11;
        }
    }
    if (P3_7 == 0)
    {
        Delay(20);
        if (P3_7 == 0)
        {
            while (P3_7 == 0)
                ;
            KeyValue = 12;
        }
    }

    P3 = 0xFF;
    P3_3 = 0;
    if (P3_4 == 0)
    {
        Delay(20);
        if (P3_4 == 0)
        {
            while (P3_4 == 0)
                ;
            KeyValue = 13;
        }
    }
    if (P3_5 == 0)
    {
        Delay(20);
        if (P3_5 == 0)
        {
            while (P3_5 == 0)
                ;
            KeyValue = 14;
        }
    }
    if (P3_6 == 0)
    {
        Delay(20);
        if (P3_6 == 0)
        {
            while (P3_6 == 0)
                ;
            KeyValue = 15;
        }
    }
    if (P3_7 == 0)
    {
        Delay(20);
        if (P3_7 == 0)
        {
            while (P3_7 == 0)
                ;
            KeyValue = 16;
        }
    }
    return KeyValue;
}