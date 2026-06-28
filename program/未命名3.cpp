#include<bits/stdc++.h>
using namespace std;
int sta[100002];
int top=0;
int main()
{
	char s;
	int sum=0;
	memset(sta,-1,sizeof(sta));
	while(cin>>s)
	{
		if(s=='0')
		{
			if(sta[top]==1)
				top--,sum+=2;//pop 
			else
				sta[++top]=0;//push

		}
		else
		{
			if(sta[top]==0)
				top--,sum+=2;//pop 
			else
				sta[++top]=1;//push
		}
	}
	cout<<sum;
}
