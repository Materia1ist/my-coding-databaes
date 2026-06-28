#include<bits/stdc++.h>
using namespace std;


void input_num(string* num1,string* num2)
{
	string in;
	cin>>in;
	int k=in.find("+",0),len=in.length();
	*num1=in.substr(0,k);
	*num2=in.substr(k+1,len-k);
	
}

void high_percision_addition(string *num1,string *num2,string* res)
{
	string n_up,n1=*num1,n2=*num2,nres=*res;
	int l1= (n1).length();
	int l2= (n2).length();
	if(l1>l2)
	{
		swap(n1,n2);swap(l1,l2);
	}
	n1=string(n1.rbegin(),n1.rend());	n2=string(n2.rbegin(),n2.rend());//Ä©Î²¶ÔÆë
	string s0="0";
	for(int i=0;i<=l2;i++)
	{
		if('0'<=n1[i]&&n1[i]<='9') ;else n1+=s0;
		if('0'<=n2[i]&&n2[i]<='9') ;else n2+=s0;
		nres+=s0;
		n_up+=s0;
	}
	/*cout<<n1<<endl;//test
	cout<<n2<<endl;//test
	cout<<n_up<<endl;//test
	cout<<nres<<endl;//test
	*/
	for(int i=0,add=0;i<=l2;i++)
	{
		add=n1[i]+n2[i]+n_up[i]-96-48;
		if(add-10>=0)
		{
			add-=10;
			n_up[i+1]+=1;
		}
		nres[i]+=add;
	}
	nres=string(nres.rbegin(),nres.rend());
	int f=nres.find("0",0);
	if(f==0)nres.erase(0,1);
	//cout<<nres;//test
	*res=nres;
}

int main()
{
	string num1,num2,num3;
	input_num(&num1,&num2);
	high_percision_addition(&num1,&num2,&num3);
	cout<<num3<<endl;
}
