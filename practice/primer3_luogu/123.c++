#include<iostream>//标准输入输出头
using namespace std;
int main()
{
	int n,x,k;//定义一下
	cin>>n;
	for(int i=1;i<=100;i++)
	/*循环，因为要找x最大
	的情况所以从1开始往后找*/
	{
		for(int j=200;j>=1;j--)
		/*要找k最小的情况，所以
		从200开始往前面找*/
		{
			if(i*7+j*21==n/52)
              //判断一下是否能正好攒够钱
			{
				x=i;//把i的值给x
				k=j;//把j的值给k
				/*由于后一组x和k的值会覆盖上一组，
				所以最后输出的一定是
                 x最大，k最小的情况*/
			}
		}
	}
	cout<<x<<endl;//输出
	cout<<k<<endl;
	return 0;//好习惯别忘了
}