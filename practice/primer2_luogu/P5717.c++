//三角形分类
#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a,b,c,a2,b2,c2;//三边长与三边平方
    cin>>a>>b>>c;
    a2=a*a;b2=b*b;c2=c*c;
    /*如果是直角三角形，输出Right triangle；
    如果是锐角三角形，输出Acute triangle；
    如果是钝角三角形，输出Obtuse triangle；
    如果是等腰三角形，输出Isosceles triangle；
    如果是等边三角形，输出Equilateral triangle*/
    if(a+b<=c||a+c<=b||b+c<=a)
    {cout<<"Not triangle"<<endl;return 0;}
    if(a2+b2==c2||a2+c2==b2||b2+c2==a2)
    {cout<<"Right triangle"<<endl;}
    if(a2+b2>c2&&a2+c2>b2&&b2+c2>a2)
    {cout<<"Acute triangle"<<endl;}
    if(a2+b2<c2||a2+c2<b2||b2+c2<a2)
    {cout<<"Obtuse triangle"<<endl;}
    if(a==c||a==b||b==a)
    {cout<<"Isosceles triangle"<<endl;}
    if(a==c&&a==b&&b==a)
    {cout<<"Equilateral triangle"<<endl;}
    return 0;
}