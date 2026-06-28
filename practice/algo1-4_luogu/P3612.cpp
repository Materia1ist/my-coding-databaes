#include<bits/stdc++.h>

using namespace std;

string s;
int len,n;
int main()
{
    cin>>s;
    len=s.length();
    for(int i=0;i<len;i++){
        s[len+i]=s[len-i-1];
    }
    len*=2;
    cin>>n;
    n--;
    n%=len;
    printf("%c\n",s[n]);
    //printf("%s\n",s.c_str());// test
    
}