#include <bits/stdc++.h>
using namespace std;
int heap[1000000];
int len = 0;
int minHeapify(int p)
{
    int l = p*2, r = p*2+1,min = r;
    if (r <= len && heap[r] < heap[l])
    {
        min = r;
    }
    else 
    {
        min = l;
    }
    if (min <= len && heap[min] < heap[p])
    {
        swap(heap[min],heap[p]);return min;
    }
    return p;
    
}
void heapInsert(int n)
{
    len++;
    heap[len] = n;
    int i = len/2;
    while(i)
    {
        minHeapify(i);
        i/=2;
    }
}
int heapTop()
{
    if(len == 0) return 0;
    
    return heap[1];
}

int heapDelete()
{
    swap(heap[1],heap[len]);
    len--;
    int p = 1,next = minHeapify(p);
    while(p!=next)
    {
        p = next;
        next = minHeapify(p);
    }
    return heap[len+1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,op;
    cin>>n;
    while (n--)
    {
        //cout<<n<<len<<'(';
        cin>>op;
        if(op == 1)
        {
            int a;
            cin>>a;
            heapInsert(a);
        }
        if(op == 2)
        {
            cout<<heapTop()<<'\n';
        }
        if(op == 3)
        {
            heapDelete();
        }
    }
    
}