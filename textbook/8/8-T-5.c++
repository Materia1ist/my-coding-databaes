//小写转换为大写，大写不变
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    char a;
    cin>>a;
    if(97<=(int(a))&&(int(a))<=122)
    {a=a-32;
    cout<<a;}
}