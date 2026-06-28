//7-E-4
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    char a[3];
    char m;
    double _1,_2;
    cin>>a;
    _1=(a[0])-48;
    _2=(a[2])-48;
    switch (a[1])
    {
    case '+':
        cout<<_1+_2;
        break;
    case '-':
        cout<<_1-_2;
        break;
    case '*':
        cout<<_1*_2;
        break;
    case '/':
        cout<<_1/_2;
        break;
    }
    return 0;
}