//种树问题，bool薄纱
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int l,m,L,R,sum=0;
    scanf("%d%d",&l,&m);
    bool a[l+1];
    memset (a,1,sizeof(a));
    for (int I = 1; I <= m; I++)
    {
        scanf("%d%d",&L,&R);
        for (int i = L; i <= R; i++)
        {
            a[i]=0;
        }
    }
    for (int i = 0; i <= l; i++)
    {
        if(a[i]==1)
        sum++;
    }
    printf("%d",sum);
    return 0;
}