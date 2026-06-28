#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=0,a;//计算使用n,结果为a
    char N[13];//ISBN码
    cin>>N;
    for (int i = 0; i<12 ; i++)
    {
        if(i==0)
        {n=n+((int(N[i])-48)*(i+1));}//**(i+？)取决于位置
        if(2<=i&&i<=4)
        {n=n+((int(N[i])-48)*i);}
        if(6<=i&&i<=10)
        {n=n+((int(N[i])-48)*(i-1));}
    }
    a=n%11;//计算识别码
    //判断是否符合条件，输出'Right'或纠正
    if(a==(int(N[12])-48) || (a==10&&((int(N[12]))==88)))//88代表X
    {cout<<"Right";}
    else
    {
        if(a==10){N[12]=88;}
        else{N[12]=a+48;}  
        cout<<N;
    }
    return 0;
}