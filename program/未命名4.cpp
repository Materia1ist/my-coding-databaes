#include<bits/stdc++.h>
using namespace std;
int lian(char a[],int i)
{
	int sum=1;
	while(1)
	{
		if(a[i]==a[i+1])
		{
			i++;
			sum++;
		}
		else
			break;
	}
	return sum;
}
int main()
{
	int N=0;
	long long sum=0,sum1=0,sum2=0,sum3=0;
	cin>>N;
	char a[N+1];
	for(int i=1;i<=N;i++)
		cin>>a[i];
	for(int i=1,k1=N-3,f1=1;i<=k1;i++)
	{
		sum1=0;
		for(int ij=1,k2=N-i,f2=1;ij<=k2;ij++)
		{
			sum2=0;
			if(a[i]!=a[i+ij])
			{
				sum2=0;
				for(int jk=1,k3=N-i-ij;jk<=k3;jk++)
				{
					if(a[i+ij]!=a[i+ij+jk]&&a[i]!=a[i+ij+jk])
					{
						if(ij!=jk)
							sum2++;
					}
				}
				f2=lian(a,i+ij);
				sum2*=f1;
				sum1+=sum2;
				i+=f1-1;
			}
		}
		f1=lian(a,i);
		sum1*=f1;
		sum+=sum1;
		i+=f1-1;
	}
	cout<<sum;
}
