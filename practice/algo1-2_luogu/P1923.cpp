#define Max 5000005
#include<bits/stdc++.h>
using namespace std;


/*
void Heapify(int n,int i,int a[]){
    int laugest=i,l=(i*2)+1,r=(i*2)+2;
    if(l<n&&a[l]>a[laugest])laugest=l;
    if(r<n&&a[r]>a[laugest])laugest=r;
    if(laugest!=i){
        swap(a[laugest],a[i]);
        Heapify(n,laugest,a);
    }
}
void HeapSort(int a[],int n){
   for(int i=(n/2)-1;i+1;i--){
        Heapify(n,i,a);
   }
   for(int i=n-1;i+1;i--){
        swap(a[i],a[0]);
        Heapify(i,0,a);
   }
}
*/
void QuicksortPlus(int a[],int l,int r,int k){
    int i=l-1;

    for(int j=l;j<r;j++){
        if(a[j]<a[r])swap(a[++i],a[j]);
    }
    swap(a[r],a[++i]);
    if(i==k){
        cout<<a[k];
        return;
    }
    if(i>k)QuicksortPlus(a,l,i-1,k);
    if(i<k)QuicksortPlus(a,i+1,r,k);
}

int main(){
    int n,k; 
    cin>>n>>k;
    int a[n+5];
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    QuicksortPlus(a,0,n-1,k);
//test    for(int i=0;i<n;i++)printf("%5d",a[i]);

    return 0;
}