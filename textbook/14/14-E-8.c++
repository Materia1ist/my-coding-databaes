#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long a,b,c,d,n,f;
    cin>>n;
    for (a=2; a <= n; a++)
    {
        f=0;
        //穷举
        //cout<<a<<" ";
        for (b = 1; b < a; b++)
        {
            //cout<<b<<" ";
            for (c = 1; c <= b; c++)
            {
                //cout<<c<<" ";
                d=(a*a*a)-(b*b*b)-(c*c*c);
                for (int i = 1; i < sqrt(d); i++)
                {
                    if(i*i*i==d)
                    {f=1;d=i;break;}
                }
                //cout<<d<<endl;
                if(f==1)
                break;
            }
            if(f==1)
            break;
        }
        //排序
        if(f==1)
        {
            int k,kb=b,kc=c,kd=d;
            if(kb>kd)
            {k=kb;kb=kd;kd=k;}
            if(kb>kc)
            {k=kb;kb=kc;kc=k;}
            if(kc>kd)
            {k=kc;kc=kd;kd=k;}
            cout<<"Cube = "<<a<<", Triple = ("<<kb<<","<<kc<<","<<kd<<")"<<endl;
        }
        
    }
    return 0;
}