#include<bits/stdc++.h>
using namespace std;

int sum=0;

//调整，构建大/小堆
/// @brief 建大堆
/// @param arr 数组下标
/// @param n 下标的最小值
/// @param root 待处理的根的下标
void AdjustDown(int* arr, int n, int root)
{
	//双亲的下标
	int parent = root;
	//较大孩子的下标，默认为左孩子
	int child = parent * 2;
	//如果孩子的下标不越界，进入循环
	while (child <= n)
	{
		//如果右孩子存在（下标没越界），并且右孩子大于左孩子，更新child
		if (child + 1 <= n && arr[child + 1] > arr[child])
		{
			child = child + 1;
		}
		//如果较大的孩子大于双亲，交换
		if (arr[child] > arr[parent])
		{
			swap(arr[child],arr[parent]);
			//改变parent的下标如果满足条件继续向下调整
			parent = child;
			child = parent * 2;
		}
		//如果较大的孩子不大于双亲，root节点的大堆构建完毕
		else
		{
			break;
		}
	}
}


/// @brief 升序堆排序（左小右大）
/// @param arr 数组下标
/// @param n 数组有效长度：sizeof(arr)-1
void HeapSortUp(int*arr,int n)
{
    int i=0;
    for(i=n/2;i>=1;i--)//大致排序，提取最大值
    {
        AdjustDown(arr,n,i);
    } 
    int end=n;
    while (end>0)//详细排序，完善升序
    {
        swap(arr[1],arr[end]);
        AdjustDown(arr,end-1,1);//为什么end-1？
        --end;
    }
}

void FindNumber(int*a,int n)//参照指针自右向左运动，L,R指针寻找数；
{
    int f,l,r;
    bool flag;
    for (int f = n; f >=3; f--)//参照指针f
    {
        for (r=f-1,l=1 ; 2<=r; r--)//右指针r
        {
            for (l=1; l<r ; l++)//左指针l
            {
                if((a[r]+a[l]==a[f])&&(a[r]!=a[l]))
                {sum++;flag=1;break;}
            }
            if(flag==1)
            {flag=0;break;}
        }
    }
}
int main ()
{
    int n;
    scanf("%d",&n);
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    HeapSortUp(a,n);
    FindNumber(a,n);
    printf("%d",sum);
}