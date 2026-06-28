//陶陶摘苹果
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int _1,_2,_3,_4,_5,_6,_7,_8,_9,_10,h;//10个苹果高度，h人高
    cin>>_1>>_2>>_3>>_4>>_5>>_6>>_7>>_8>>_9>>_10>>h;
    h=h+30;
    //判断能否够到
    int n=0;
    if(_1<=h){n++;}
    if(_2<=h){n++;}
    if(_3<=h){n++;}
    if(_4<=h){n++;}
    if(_5<=h){n++;}
    if(_6<=h){n++;}
    if(_7<=h){n++;}
    if(_8<=h){n++;}
    if(_9<=h){n++;}
    if(_10<=h){n++;}
    cout<<n;
    return 0;
}