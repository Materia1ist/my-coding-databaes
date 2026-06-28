#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l,key=1;
    cin>>l;
    for (int i = 1; i <= l; l-- )//纵边循环
    {
        for (int i = 1; i <=l ; i++)//横边循环
        {
            cout<<setw(2)<<setfill('0')<<key;
            key++;
        }
        cout<<endl; 
    }
    return 0;
}