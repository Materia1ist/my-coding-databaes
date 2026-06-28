//数据解压
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n=0,i=1;
    int a[21000];
    char k,f='0';
    while (cin>>k)
    {
        if(k==f)
        {
            a[i]++;
        }
        else
        {
            i++;
            a[i]++;
            f=k;
        }
        n++;
    }
    //cout<<n<<" "<<i<<endl;
    printf("%.0lf ",sqrt(n));
    for (int j = 1; j <= i; j++)
    {
        printf("%d ",a[j]);
    }
    return 0;
}