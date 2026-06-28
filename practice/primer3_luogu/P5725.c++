#include<bits/stdc++.h>
using namespace std;
void PrintSquare (int n)
{
    int a=1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++,a++)
        {
            printf("%02d",a);
        }
        printf("\n");
    }
}
void PrintTriangle (int n)
{
    int a=1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n-i; j++)
        {
            printf("  ");
        }
        for (int j = 1; j <= i; j++,a++)
        {
            printf("%02d",a);
        }
        printf("\n");
    }
}
int main ()
{
    int n;
    scanf("%d",&n);
    PrintSquare (n);
    printf("\n");
    PrintTriangle (n);
    return 0;
}