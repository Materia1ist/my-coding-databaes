#include<bits/stdc++.h>
using namespace std;

string high_percision_multiplication(string n1,string n2)
{
    ///初始化

    int l1=n1.length(),l2=n2.length();
    int n3[l1+l2];
    memset(n3,0,sizeof(n3));
    string res;
    if(l1<l2){swap(l1,l2);swap(n1,n2);};//交换使n1最长
    reverse(n1.begin(),n1.end());reverse(n2.begin(),n2.end());//翻转字符串达到末尾对齐
    for (int i = 0; i < l1; i++)n1[i]-=48;
    for (int i = 0; i < l2; i++)n2[i]-=48;//方便计算
    
    ///乘法器

    for (int i = 0; i <l1; i++)
    {
        int temp=0;//进位储存
        for (int j = 0; j <l2; j++)
        {
            n3[i+j]+=((n1[i]*n2[j])+temp);
            temp=n3[i+j]/10;
            n3[i+j]%=10;
        }
    }

    ///转为string，运算结果去0，输出
    char k;
    for (int i = l1+l2-1; i>=0 ; i--)
    {
        k=n3[i];
        k+=48;
        res+=k;
    }
    if(res[0]==48)res.erase(res.begin());
    return res;
}
int main()
{
    string n1,n2,nres;
    int n;
    cin>>n1>>n2;
    nres=high_percision_multiplication(n1,n2);
    /*char num='1';
    cout<<num<<endl;
    nres+=num;
    for (int i = 1; i <= n; i++)
    {
        nres=high_percision_multiplication(nres,n1);
    }*///乘方器
    cout<<nres;
}