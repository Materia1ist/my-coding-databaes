#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin>>x;
    switch (x=(x-1)/10)
    {
    case 9:
        cout<<"A";
        break;
    case 8:
        cout<<"B";
        break;
    case 7:
        cout<<"C";
        break;
    default:
        cout<<"D";
        break;
    }
}