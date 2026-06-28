#include<bits/stdc++.h>
using namespace std;
int n;
int mem[305][305],mp[305][305];
void bfs()
{
    queue<pair<int,int> > q;
    int x,y;
    for (int i = 1; i <= n; i++)
    {
        q.push({1,i});
        q.push({n,i});
        q.push({i,1});
        q.push({i,n});
    }
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        mem[x][y] = 1;
        if(mp[x][y] == 2)
        {
            mp[x][y] = 0;
            if(mem[x+1][y] == 0)q.push(make_pair(x+1,y));
            if(mem[x-1][y] == 0)q.push(make_pair(x-1,y));
            if(mem[x][y+1] == 0)q.push(make_pair(x,y+1));
            if(mem[x][y-1] == 0)q.push(make_pair(x,y-1));
        }
    }
}

int main()
{
    cin>>n;
    memset(mp,-1,sizeof(mp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin>>mp[i][j];
            if(mp[i][j] == 0)mp[i][j] = 2;
        }
    }
    bfs();
    cout<<'\n';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout<<mp[i][j]<<' ';
        }
        cout<<'\n';
    }
}