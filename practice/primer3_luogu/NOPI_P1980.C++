#include<bits/stdc++.h>
using namespace std;
void Mycode (int n,int x)
{
    int sum=0,k;
    for (int i = 1; i <= n; i++)
    {
        k=i;
        while (k>=10)
        {
            if(k%10==x)
            {sum++;}
            k/=10;
        }
        if(k%10==x)
        {sum++;}
    }
    printf("%d",sum);
}
int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    Mycode (n,x);
    return 0;
}