#include <bits/stdc++.h>
#define ll long long
#define MAX ~(1 << 31)
using namespace std;

int n;
ll a[10000000];

// heapsort & priority queue
class Heap
{
    ll noob[10000000];
    int size = 0;

public:
    void MaxHeapify(int root)
    {
        int l = root * 2, r = l + 1, largest = -1;
        if (l <= size && noob[l] > noob[root])
            largest = l;
        else
            largest = root;
        if (r <= size && noob[r] > noob[largest])
            largest = r;
        if (largest != root)
        {
            swap(noob[largest], noob[root]);
            MaxHeapify(largest);
        }
        return;
    }
    void BuildHeap()
    {
        for (int i = 1; i <= n; i++)
            noob[i] = a[i];
        size = n;
        for (int i = size / 2; i >= 1; i--)
        {
            MaxHeapify(i);
        }
        return;
    }
    void HeapSort()
    {
        BuildHeap();
        int tem = size;
        for (int i = size; i >= 2; i--)
        {
            swap(noob[i], noob[1]);
            size--;
            MaxHeapify(1);
        }
        size = tem;
        return;
    }
    void HeapInsertKey(ll num)
    {
        noob[++size] = num;
        int key = size;
        while(key != 1 && noob[key/2] < noob[key]){
            swap(noob[key/2],noob[key]);
            key/=2;
        }
    }
    ll HeapMaximum() // get value
    {
        return noob[1];
    }
    ll HeapExtractMax() // took max out of the queue
    {
        ll max = noob[1];
        swap(noob[1], noob[size--]);
        MaxHeapify(1);
        return max;
    }
    void Output()
    {
        for (int i = 1; i <= n; i++)
            printf("%lld\n", noob[i]);
        return;
    }
} ;//heap;

void Output()
{
    for (int i = 1; i <= n; i++)
        printf("%lld\n", a[i]);
}
ll RandomGenerater(ll range1, ll range2)
{
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist(range1, range2); // distribution in range [1, 6]

    return dist(rng);
}
void SetRandom(ll range1, ll range2)
{
    for (int i = 1; i <= n; i++)
        a[i] = RandomGenerater(range1, range2);
}

// insersort
void InsertionSort()
{
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (a[i] < a[j])
            {
                for (int k = i; k > j; k--)
                    swap(a[k], a[k - 1]);
                break;
            }
        }
    }
}

// margesort
void Marge(int l, int m, int r)
{
    ll L[m - l + 4], R[m - l + 4];
    memset(L, 0, sizeof(L));
    memset(R, 0, sizeof(R));
    for (int i = 0; i <= m - l; i++)
        L[i] = a[l + i];
    L[m - l + 1] = MAX;
    for (int i = 0; i <= r - m - 1; i++)
        R[i] = a[m + 1 + i];
    R[r - m] = MAX;
    int p = 0, q = 0; // p->L,q->R
    for (int i = l; i <= r; i++)
    {
        if (L[p] <= R[q])
        {
            a[i] = L[p++];
        }
        else
        {
            a[i] = R[q++];
        }
    }
    //  printf("\n %d %d\n", l, r);

    return;
}
void MargeSort(int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        MargeSort(l, m);
        MargeSort(m + 1, r);
        Marge(l, m, r);
    }
    return;
}

int main()
{
    freopen("sort.out", "w", stdout);
    n = 100;
    SetRandom(1, 1000000000);
//    heap.BuildHeap();
//    heap.Output();
//    cout <<'/'<< heap.HeapExtractMax() << '\n';
//    heap.HeapInsertKey(1145141919);
//    heap.Output();
    // Heap heap;
    // heap.HeapSort();
    // heap.Output();
    // Output();
    // printf("\n");
    //  InsertionSort();
    //  MargeSort(1, n);
    // Output();
}