#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int mem[5005]; 
struct p{//point 
	bool f[5005];
    int in=0,out=0;
}poi[5005];

int dfs(int pos){
	if(mem[pos])return mem[pos];
	mem[pos]=1;
	for(int i=1;i<=n;i++){
		if(poi[pos].f[i])mem[pos]=max(mem[pos],dfs(i)+1);
        poi[a].out++;
        poi[b].in++;
	}
    for(int i=1;i<=n;i++){
        
    }
	return mem[pos];
}

void input(){
    scanf("%d%d",&n,&m);
    int a,b;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        poi[a].f[b]=1;
    }
}

int main (){
	input();
    int Max=-1;
    for(int i=1;i<=n;i++)
        Max=max(dfs(i),Max);
    cout<<Max;
    return 0;
}