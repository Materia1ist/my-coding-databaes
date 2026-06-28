#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    queue<int> q,ans;
    for(int i = 1; i <= n;i++)
    {
        q.push(i);
    }
    int i = 1;
    while (!q.empty())
    {
        
        if(i == m)
        {
            ans.push(q.front());
            q.pop();
            i = 0;
        }
        else{
            q.push(q.front());
            q.pop();
        }
        i++;
    }
    while (!ans.empty())
    {
        printf("%d ",ans.front());
        ans.pop();
    }
}