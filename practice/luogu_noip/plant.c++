#include<bits/stdc++.h>
using namespace std;
//bool fecw[10003];
int turn_fector(int n)
{
    int ans=0;
    int m=sqrt(n);
    for (int i = 1; i <= m; i++)
    {
        if(n%i==0)
            ans+=2;
    }
    if(n==m*m)
        ans--;
    return ans;
}
void turn_prime(int n,int *pri)
{
    pri[1]=0;
    for (int i = 2; i <= n; i++)
    {
        pri[i]=0;
        while(n%i==0)
        {
            n/=i;
            pri[i]++;
        }
    }
}


int main()
{
    int w,n;
    scanf("%d%d",&n,&w);
    int priw[w+2];
    int hp[n+1];
    int wp[n+1];
    memset(wp,0,sizeof(wp));
    memset(hp,0,sizeof(hp));
    turn_prime(w,priw);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&hp[i]);
        wp[i]=turn_fector(hp[i]);
    }

    //situaton 1:因数间存在空位插入质数（已完成
    for (int i = 1; i <= n; i++)//遍历因数
    {
        for (int j = 2; j <= w; j++)//遍历空数位
        {
            if(hp[i]%j!=0&&priw[j]!=0)
            {
                priw[j]--;hp[i]*=j;wp[i]*=2;
            }
        }
    }
    /*
    //situaton 2:因数间无空位插入质数，选择最优插入（debuging :<
    int wpp[n+1];
    for (int i = 2; i < w; i++)//遍历质数
    {

        if(priw[i]>0)
        {
            for (int j = 1; j <= n; j++)
                wpp[j]=wp[j];
            while(priw[i]>0)
            {
                
                for (int j = 1; j <= n && priw[i]!=0 ; j++)
                {
                    if(wpp[j]%i!=0)
                    {
                        hp[j]*=i;
                        wp[j]=turn_fector(hp[j]);//
                        priw[i]--;

                        cout<<"  "<<priw[i];//爆野指针
                    }
                }
                for (int j = 1; j <= n; j++)
                    wpp[j]/=i;
                cout<<"2";//
            }
        }
    }
    */
    long long ans=1;
    for (int i = 1; i <= n; i++)//test
    {
        //cout<<priw[i]<<" ";
            //cout<<wp[i]<<endl;
    }
    for (int i = 1; i <= n; i++)
    {
        if(wp[i]!=0)
            ans*=wp[i];
    }
    cout<<ans;
}