#include <iostream>

const int MAX_N = 1000005;
int arr[MAX_N];
long long sum = 0;

int findMin(int left, int right) {
    int minVal = arr[left];
    for (int i = left + 1; i <= right; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

void dp(int l, int r) {
    if (l > r) return;
    if (l == r) {
        sum += arr[l];
        return;
    }

    int minVal = findMin(l, r);
    sum += minVal;

    for (int i = l; i <= r; ++i) {
        arr[i] -= minVal;
    }

    int nextl = l, nextr;
     for (int i = l; i <= r; ++i) {
        if (arr[i] != 0) {
            nextl = i;

            while (i <= r+1 && arr[i] != 0) {
                ++i;
            }

            nextr = i - 1;
            dp(nextl,nextr);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }

    dp(1, N);
    printf("%lld", sum);

    return 0;
}


/*#include<bits/stdc++.h>
using namespace std;
int arr[100005];
long long sum=0;
int findMin(int left, int right) 
{
   int minVal = arr[left];
    for (int i = left + 1; i <= right; ++i) 
    {
        if (arr[i] < minVal) 
        {
            minVal = arr[i];
        }
    }

    return minVal;
}

void dp(int l,int r)
{
    if(l>r)return;
    if(l==r)
    {
        sum+=arr[l];return;
    }

    int min=findMin(l,r);

    sum+=min;
    for(int i = l; i <= r; ++i)
    {
        arr[i]-=min;
    }

    int nextl=l,nextr;
    for(int i = l; i <= r+1; ++i)
    {
        if(arr[i]==0||i==r+1)
        {
            nextr=i-1;
            dp(nextl,nextr);
            while(arr[i] == 0)
            {
                i++;
            }
            nextl=i;
        }
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)  scanf("%d",&arr[i]);
    dp(1,N);
    printf("%lld",sum);
}*/



