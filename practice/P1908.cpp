#include<bits/stdc++.h>
using namespace std;
#define int long long
int merge(int *a, int llen, int rlen)
{
    vector<int> temp;
    int l = 0,r = llen,cnt = llen,ans = 0;//l r pointer 
    while(l < llen && r < llen+rlen)
    {
        if(a[l] > a[r])
        {
            temp.push_back(a[r]);
            r++;
            ans+=cnt;
        }
        else
        {
            temp.push_back(a[l]);
            l++;
            cnt--;
        }
    }
    for(;l < llen;l++)temp.push_back(a[l]);
    for(;r < llen+rlen;r++)temp.push_back(a[r]);
    for (int i = 0; i < llen + rlen; i++)
    a[i] = temp[i];
    return ans;
}

int merge_sort(int *a,int len)
{
    if(len <= 1) return 0;

    int ans = 0, mid = len / 2;
    ans += merge_sort(a,mid);
    ans += merge_sort(a+mid,len-mid);

    ans += merge(a,mid,len-mid);



    return ans;
}

signed main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << merge_sort(a,n);
    /*for (int i = 0; i < n; i++)
    {
        cout << ' ' << a[i];
    }*/
    
}