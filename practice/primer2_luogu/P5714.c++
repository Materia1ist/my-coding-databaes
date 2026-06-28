//计算后判断
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    double m,h,BMI;//分别表示体重（单位为 kg），身高（单位为 m）,BMI 其算法是h/m^2
    cin>>m>>h;
    BMI=m/(h*h);
    if(BMI<18.5)
    {printf("Underweight");}
    if(BMI>=24)
    {cout<<setw(6)<<BMI<<endl<<"Overweight";}
    if(BMI>=18.5&&BMI<24)
    {printf("Normal");}
    return 0;
}