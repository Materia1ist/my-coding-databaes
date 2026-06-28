#include<bits/stdc++.h>
using namespace std;
#define int long long
struct dus
{
   vector<int> pa;
   void init(int size) {pa.resize(size + 1,0); for(int i = 1; i <= size; i++) pa[i] = i;}
   int find(int a){return pa[a] == a ? a : pa[a] = find(pa[a]);}       
   void uni(int a, int b){pa[find(a)] = find(b);}
};

int n,m;
struct edge
{
	int u,v,w; 
};
bool cmp(edge a,edge b)
{
	return a.w < b.w;
}
vector<edge> e;
vector<bool> inset;



signed main()
{
	cin >> n >> m;
	inset.resize(n);
	for(int i = 1,u,v,w; i <= m; i++)
	{
		cin >> u >> v >> w;
		e.push_back({u,v,w});
	}
	sort(e.begin(),e.end(),cmp);
    dus s;
    s.init(n);
	int i = 0, cnt = 0, f = 0;
	while(i < e.size())
	{
        int u = e[i].u, v = e[i].v, w = e[i].w;
		if(s.find(u) != s.find(v))
        {
            cnt++;
            f += w;
            s.uni(u, v);
        }
        i++;
	}
	if(cnt != n-1)
	{
		cout << "orz";
		return 0;
	}
	cout << f;
}