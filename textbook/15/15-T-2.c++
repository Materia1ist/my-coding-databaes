#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[11];
    int h,sum;
    for (int i = 1; i <= 10; i++)
    {
        cin>>a[i];
    }
    cin>>h;
    for (int i = 1; i <= 10; i++)
    {
        if (a[i]<=h)
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}