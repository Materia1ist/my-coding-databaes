#include <bits/stdc++.h>
using namespace std;
//string s1,s2;
int n,m;
bool flag_m=0;
string s;
string erase(string str_begin,char c)
{
    int len=str_begin.length();
    string str_end;
    for(int i=0;i<len;i++)
    {
        if(str_begin[i]!=c){str_end+=str_begin[i];}
    }
    return str_end;
}
void quit1()
{
    int len=s.length();
    for(int i=0,sum=0;i<=len&&!flag_m;i++)
    {
        len=s.length();
        for(int j=i;j<len&&sum<=m&&!flag_m;j++)
        {
            if(s[j]>s[j+1]){s[j]='*';sum++;}
            if(sum>=m)flag_m=1;
        }
        s=erase(s,'*');
    }
}
void quit2()
{
    int f=s.length();
    while (n-m<f)
    {
        s[f-1]='*';
        s=erase(s,'*');
        f=s.length();
    }
    s=erase(s,'*');
}
int main()
{
    cin>>s;
    n=s.length();
    scanf("%d",&m);
    quit1();
    s=erase(s,'*');
    quit2();
    cout<<s;
    //s=erase(s);//test
    //cout<<s;//test
}