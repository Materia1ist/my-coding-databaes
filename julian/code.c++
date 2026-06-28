#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int k_mon,sum_year=-4713,y=0,m=0,d=0;
bool sign_y=0;
void ydm(long long n)
{
    sign_y=0;sum_year=-4713;m=1;d=1;mon[2]=28;
    while(n>=365)
    {
        if(sum_year==-1){sum_year++;sign_y=1;n--;}//移除公元0年
        else if(sum_year<=0)//公元前
        {
            if((sum_year+1)%4!=0)
            {
                n-=365;sum_year++;
            }
            else
            {
                n-=366;sum_year++;
            }
        }
        else if(sum_year)//公元后
        {
            if(sum_year<=1582)
            {
                if((sum_year)%4)
                {
                    n-=365;sum_year++;
                }
                else
                {
                    n-=366;sum_year++;
                }
            }
            else
            {
                if(((sum_year%4==0)&&(sum_year%100!=0))||sum_year%400==0)
                {
                    n-=366;sum_year++;
                }
                else
                {
                    n-=365;sum_year++;
                }
            }
        if(sum_year==1582)n+=10;
    }
    }


    if((((sum_year%4==0)&&(sum_year%100!=0))||sum_year%400==0)&&sum_year>1582)
    {
        mon[2]++;
    }
    else if(sum_year%4==0&&sum_year<=1582&&sum_year>=1)
    {
        mon[2]++;
    }
    else if((sum_year+1)%4==0&&sum_year<0)
    {
        mon[2]++;
    }
    //return;    
    for (int i = 1; i < 12; i++)
    {
        if(n-mon[i]>=0)
        {
            n-=mon[i];m++;
        }
        else break;
    }
    d+=n;
    y=abs(sum_year);
    if(y==0&&d==31){y==1;sign_y=0;}
    if(d==0&&sign_y==0){d=31;m=12;y++;}
    if(d==0&&sign_y==1){d=31;m=12;y--;}
}
int main()
{
   //freopen("P7075_1.in","r",stdin);
    //freopen("julian1.ans","w",stdout);
    int Q;long long n=000;//1721000;
    //int k=1;
    cin>>Q;
    while(Q)
    {
        //long long n=000;
        cin>>n;
        //n++;
        ydm(n);
        if(sign_y)printf("%d %d %d\n",d,m,y);
        else printf("%d %d %d BC\n",d,m,y);
        //else printf("%d:%d %d %d %d BC\n",k,n,d,m,y);
        Q--;//k++;
    }
    //fclose(stdin);
    //fclose(stdout);
}