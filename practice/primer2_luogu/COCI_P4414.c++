#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    char n[3];
    cin>>a>>b>>c;
    //冒泡排序小到大
    {int key;
    if(a>c){key=a;a=c;c=key;}
    if(b>c){key=b;b=c;c=key;}
    if(a>b){key=a;a=b;b=key;}
    }
    //带入字母
    cin>>n[0]>>n[1]>>n[2];//原理？
    for (int i=0; i<=3; i++)
    {
        if(n[i]=='A'){cout<<a<<" ";}
        if(n[i]=='B'){cout<<b<<" ";}
        if(n[i]=='C'){cout<<c<<" ";}
    }
    return 0;
}