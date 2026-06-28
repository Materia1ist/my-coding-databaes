#include<bits/stdc++.h>
using namespace std;
int tong[3005][28];
int main()
{
    int n,m;
    cin>>n>>m;
    bool ans[n+1];memset(ans,0,sizeof(ans));memset(tong,0,sizeof(tong));
    string s;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        for(int j=0;j<m;j++)
        {
            tong[i][(s[j]-'a'+1)]+=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        int p;
        for(int j=1;j<=m;j++)
            if(tong[i][j]!=0)
            {
                p=j;break;
            }
        bool f1=0;//
        for(int j=1;j<=n;j++)//
        {
            f1=0;
            if(i!=j)
            {printf("%d\n",j);
                f1=1;
                for(int k=26;k;k--)
                {
                    if(tong[j][k]!=0)
                    {
                        if(k>=p) f1=0;
                    }
                    if(f1==0) break;
                }
            }
            if(f1==1)
            {
                ans[i]=0;
                break;
            }
        }
    }
    for(int a=1;a<=n;a++)
    {
        for(int i=1;i<=26;i++) 
            printf("%d ",tong[a][i]);
        printf("\n");
    }
    for(int i=1;i<=n;i++)
        printf("%d",ans[i]);
    return 0;
}
