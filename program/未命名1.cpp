#include<bits/stdc++.h>
using namespace std;

int f[10][10],N[11][11];//N[]вщx╨Аy
bool mem[10][10];//0обё╛1ср 
/**/
void test_output_mem()
{
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=10;j++)
		{
			printf("%3d",mem[i][j]);
		}
		cout<<endl;
	}

}

void test_output_f()
{
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=10;j++)
		{
			printf("%3d",f[i][j]);
		}	
		cout<<endl;
	}

}
void test_output_N()
{
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=10;j++)
		{
			printf("%3d",N[i][j]);
		}
		cout<<endl;
	}
	
}

void input(int edge)
{
	for(int i=1;i<=10;i++)
	{
		N[edge+1][i]=-1;N[i][edge+1]=-1;
	}
	int x=1,y=1,num=1;
	while(x!=0&&y!=0&&num!=0)
	{
		scanf("%d%d%d",&x,&y,&num);
		if(x==0&&y==0&&num==0)
			break;
		else
			N[x][y]=num;
	}
	test_output_N();
	return ;
}

int recursion(int n)
{
	for(int i=n;i;i--)
	{
		for(int j=n;j;j--)
		{
			if(f[i+1][j]>f[i][j+1])//f[i+1][j]об;f[i][j+1]ср 
			{
				f[i][j]=f[i+1][j]+N[i][j];
				mem[i][j]=0;
			}
			else
			{
				f[i][j]=f[i][j+1]+N[i][j];
				mem[i][j]=1;
			}
		}
	}
//	test_output_f();
	return f[1][1];
}
void clear_path(int edge,int x,int y)
{
	N[x][y]=0;
	if(x==edge&&y==edge)
		return;
	if(mem[x][y])
		clear_path(edge,x,y+1);
	else
		clear_path(edge,x+1,y);
	return;
}
int main()
{
	int n,max1,max2,max_tot;
	cin>>n;
	input(n);
	max1=recursion(n);
	//cout<<endl;
	for(int i=1;i<=n;i++)
	{
		mem[i][n]=0;mem[n][i]=1;
	}
	test_output_mem();
	clear_path(n,1,1);
	
	test_output_N();
	
	memset(f,0,sizeof(f));
	max2=recursion(n);
	max_tot=max1+max2;
	cout<<max_tot;
}

