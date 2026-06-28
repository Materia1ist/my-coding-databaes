#include<bits/stdc++.h>
using namespace std;
bool num_canuse[1000001];
int main()
{
	memset(num_canuse,0,sizeof(num_canuse));
	int n;
	unsigned long long sum=0;
	cin>>n;
	for(int i=1;i<=n/3;i++)
	{
		num_canuse[i*3]=1;
	}
	for(int i=1;i<=n/5;i++)
	{
		num_canuse[i*5]=1;
	}
	/*for(int i=1;i<=n;i++)
	{
		if(num_canuse[i]==0)
			if(i%3==0||i%5==0)
				for(int j=1;i*j<=n;j++)
					num_canuse[i*j]++;
	} */
	for(int i=1;i<=n;i++)
	{
		if(num_canuse[i]==0)
			sum+=i;
	}
	printf("%lld",sum);
}
