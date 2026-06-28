#include<bits/stdc++.h>
using namespace std;
struct stu{
    int id,chi,mat,eng,sum;
};
bool cmp(stu a,stu b){
    if(a.sum>b.sum)return true;
    if(a.sum<b.sum)return false;
    else{
        if(a.chi>b.chi)return true;
        if(a.chi<b.chi)return false;
        else{
            if(a.id<b.id)return true;
            if(a.id>b.id)return false;
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    stu s[n+5];
    for(int i=0;i<n;i++){
        s[i].id=i+1;
        scanf("%d%d%d",&s[i].chi,&s[i].mat,&s[i].eng);
        s[i].sum=s[i].chi+s[i].eng+s[i].mat;
    }
    sort(s,s+n,cmp);
    for(int i=0;i<5;i++){
        printf("%d %d\n",s[i].id,s[i].sum);
    }
    return 0;
}