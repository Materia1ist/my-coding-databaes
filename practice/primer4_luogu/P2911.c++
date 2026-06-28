#include<bits/stdc++.h>
using namespace std;


int main()
{
    int s[100];
    memset (s,0,sizeof(s));
    int n[4];
    scanf("%d%d%d",&n[1],&n[2],&n[3]);
    for (int a = 1; a <= n[1] ; a++)
    {
        for (int b = 1; b <=n[2]; b++)
        {
            for (int c = 1; c <= n[3]; c++)
            {
                s[a+b+c]++;
            }
        }
    }
    int max=0;
    for (int i = 1; i <= 90; i++)
    {
        if(s[i]>s[max])max=i;
    }
    printf("%d",max);
}