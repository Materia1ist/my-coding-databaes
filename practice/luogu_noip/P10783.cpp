#include<bits/stdc++.h> 
#define ll long long
using namespace std;
ll dp[20][300000];
ll n,lim;
/*
void bfs(int p,int k){
	queue<pair<ll,ll> > q;//init
	q.push({p,k});
	ll ans = 0;
	memset (tag,1,sizeof(tag));
	
	while(!q.empty())
	{
		p = q.front().first;
		k = q.front().second;
		q.pop();
		tag[p] = 0;
		ans += dp[0][p];
		if(k != 0)
		{
			if(p*2 <= n && tag[p*2]){
				q.push({p*2,k-1});
			}
			if(p*2+1 <= n && tag[p*2+1]){
				q.push({p*2+1,k-1});
			}
			if(p/2 && tag[p/2]){
				q.push({p/2,k-1});
			}
		}
	} 
	dp[k][p] = ans;
}
*/
void dfs(ll p)
{
	if(p*2 > lim)//cant get down
	{
		for(int i = 1; i <= n; i++)dp[i][p] = dp[0][p];
		return;
	}
	dfs(p*2);dfs(p*2+1);
	for(int i = 1; i <= n; i++)dp[i][p] = dp[i-1][p*2] + dp[i-1][p*2+1];
	return;	
}
ll solve(ll x,ll y,ll k)
{
	ll mid,hx=0,hy=0,xt = x,yt = y,ans = 0;//hx = the high from x to the min ancestor of xy
	while (xt!=yt)
	{
		if(xt < yt)
		{
			swap(xt,yt);
			swap(hx,hy);
                cout<< "::"<<hx<<" "<<hy;
		} 
		hx++;xt/=2;
	}
	if(x < y)
	{
		swap(x,y);
	} 
	mid = x;
	if(hx < hy)
	{
		swap(hx,hy);
	} 
	for(int i = 1; i <= (hx + hy) / 2; i++)
	{
		mid /= 2;
	}
	k -= hx;
	if(k < 0) return 0;
	if(k == 0) return dp[0][mid];
	if((hx + hy) % 2 == 0)
	{
		ans += dp[k][mid];
	}
    
	else
	{
		ans += dp[k][mid];
		ans += dp[k-1][mid^1];
		mid /= 2;
		ans += dp[0][mid];
	}

	return ans;
}
int main(){
	ll m;
	cin>>n>>m;
	lim = (1<<n) - 1;
	for(int i = 1; i <= lim; i++)
	{
		scanf("%lld",&dp[0][i]);		 
	}
	for(int i = lim; i; i--)
	{
		dfs(i);		 
	}
	
//	for(int i = 1; i <= lim; i++)
//	{
//		dfs(i);
//	}
//	for(int i = 1;i <= n; i++)
//	{
//		scanf("%lld",&dp[0][i]);
//	}
//	for(int i = 1;i <= 18;i++)
//	{
//		for(int j = 1; j <= n; j++)
//		{
//			bfs(j,i);
//		} 
//		cout<<'.';
//	}
	while(m--)
	{
		ll x,y,k;
		scanf("%lld%lld%lld",&x,&y,&k);
		printf("%lld\n",solve(x,y,k));
	}
}