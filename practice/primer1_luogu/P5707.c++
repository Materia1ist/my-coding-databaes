//上学迟到
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int s,v,t,tm,th;//t为总分钟数，tm表示分钟，th表示小时
	cin>>s>>v;
	t=8*60-ceil(s*1.0/v)-10;//0点到出发时刻的分钟数
	if(ceil(s*1.0/v)+10>8*60)//提前时间早于0点的情况
	{
		t+=24*60;
	}
	tm=int(t%60);
	th=int(t/60);
	cout<<setw(2)<<setfill('0')<<th<<":"<<setw(2)<<setfill('0')<<tm;//取两位前面补零XX：XX
	return 0;
}