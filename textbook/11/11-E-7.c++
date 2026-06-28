#include<bits/stdc++.h>
using namespace std;
int main()
{ 
    int n,kb,kh,kn;//kb初始高度，kh高度存储，kn序号存储
    double k;
    int h[10001];
    cin>>n;
    //输入
    for (int i = 0; i < n ; i++)
    {
        cin>>h[i];
    }
    kb=h[0];
    kn=1;
    kh=kb;
    //判断
    for (int i = 0; i < n; i++)
    {   
        k=h[i]%kb;
        if(k==0)
        {
            kn=i+1;
            kh=h[i];
        }
    }
    cout<<kn<<" "<<kh;
    return 0;
}