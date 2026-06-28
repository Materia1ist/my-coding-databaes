#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int a[3],k[3];
    int key;
    cin>>a[0]>>a[1]>>a[2];
    k[0]=a[0];k[1]=a[1];k[2]=a[2];
    //从大到小排序
    {
        if(a[0]<a[2])
        {key=a[2];a[2]=a[0];a[0]=key;}
        if(a[0]<a[1])
        {key=a[1];a[1]=a[0];a[0]=key;}
        if(a[1]<a[2])
        {key=a[2];a[2]=a[1];a[1]=key;}
    }
    //输出排名
    {
        for (int i = 0; i < 3;i++)
        {
            if(a[0]==k[i])cout<<1<<" ";
            if(a[1]==k[i])cout<<2<<" ";
            if(a[2]==k[i])cout<<3<<" ";
        }    
    }
    return 0;
}