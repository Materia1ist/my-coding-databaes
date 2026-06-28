#include<bits/stdc++.h>
#define MAXSIZE 100005
using namespace std;
int n;
int a[MAXSIZE],backet[MAXSIZE],other[MAXSIZE];

bool putInBacket()
{
    for(int i = 1; i <= n; i++){
        backet[a[i]]++;
    }
    int ans=0;
    for(int i = 1; i <= MAXSIZE; i++){
        if(backet[i])ans++;
    }
    return ans%2;
}

int main(){
    cin>>n;
    for(int i = 1; i <= n; i++)cin>>a[i];
    if(putInBacket()){
        printf("-1");
    }else{
        for(int i = 1; i <= MAXSIZE; i++){
            if(backet[i]){
                backet[i]--;
                printf("%d ",i);
            }
        }
        for(int i = 1; i <= MAXSIZE; i++){
            if(backet[i]){
                while(backet[i]--)printf("%d ",i);
            }
        }
    }
    
}