#include<bits/stdc++.h>
using namespace std;

char sign[3]={'o','*','-'};


void output(int n,short int a)
{
	while(n)
	{
		printf("%c",sign[a]);
		n--;
	}
}

void output_01(int n)
{
	while(n)
	{
		printf("o*");
		n--;
	}
}

void step(int n)
{
	//Êä³ö³õÊ¼×´Ì¬
	output(n,0); output(n,1); output(2,2); 
	printf("\n");
	int i=1;
	for(;n-i>=3;i++)
	{
		output(n-i,0); output(2,2); output(n-i,1); output_01(i);
		printf("\n");
		output(n-i,0); output(n-i,1); output(2,2); output_01(i);
		printf("\n");
	}
	i--;
	printf("ooo--***");output_01(i);	printf("\n");
	printf("ooo**--*");output_01(i);	printf("\n");
	printf("o--**oo*");output_01(i);	printf("\n");
	printf("o*o*--o*");output_01(i);	printf("\n");
	printf("--o*o*o*");output_01(i);	printf("\n");
}

int main()
{
	int n;
	cin>>n;
	step(n);
	return 0;
}
