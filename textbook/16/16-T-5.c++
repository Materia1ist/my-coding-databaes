#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    scanf("%d",&n);
    int a[n+1];
    for (int i = 1; i <= n; i++)//录入数组
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    int x,l,r,min,ans;
    bool f;
    for (int I = 1; I <= m; I++)
    {
        l=1;r=n;min=((l+r)/2);
        scanf("%d",&x);
        while(l<=r)//区间边界查找（与数学求立方根相似）
        {
            if(x>a[min])//情况1，（l,min）区间内
            {
                l=min;
                if(abs(min-r)==1&&x<a[r]&&x>a[min])
                {
                    if(x<=(a[min]+a[r])/2)
                    {ans=min;break;}
                    if(x>(a[min]+a[r])/2)
                    {ans=r;break;}
                }
                if(abs(min-l)==1&&x<a[min]&&x>a[l])
                {
                    if(x<=(a[l]+a[min])/2)
                    {ans=l;break;}
                    if(x>(a[l]+a[min])/2)
                    {ans=min;break;}
                }
            }
            if(x==a[min])//情况2，（min）区间内
            {
                ans=min;
                break;
            }
            if(x<a[min])//情况3，（min，r）区间内
            {
                r=min;
                if(abs(min-r)==1&&x<a[r]&&x>a[min])
                {
                    if(x<=(a[min]+a[r])/2)
                    {ans=min;break;}
                    if(x>(a[min]+a[r])/2)
                    {ans=r;break;}
                }
                if(abs(min-l)==1&&x<a[min]&&x>a[l])
                {
                    if(x<=(a[l]+a[min])/2)
                    {ans=l;break;}
                    if(x>(a[l]+a[min])/2)
                    {ans=min;break;}
                }
            }
            if(x>a[n])//情况4，（r,~）区间内
            {ans=n;break;}
            if(x<a[1])//情况5，（~,l）区间内
            {ans=1;break;}
            min=((l+r)/2);
        }
        printf("%d\n",a[ans]);
    }  
    return 0;
}