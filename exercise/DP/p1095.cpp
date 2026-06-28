#include<bits/stdc++.h>
using namespace std;

bool checker(int S,int T, int s,int t)
{
    if(S <= s && T >= t)
    {
        cout << "Yes" << endl << t;
        return true;
    }
    else return false;
}

int main()
{
    int M,S,T,t = 0,s = 0;
    cin>>M>>S>>T;
    if(M > 10)
    {
        t = M/10;
        s = (M/10)*60;
        M = M%10;
        if(T < t)
        {
            cout << "No" << endl << T * 60;
            return 0;
        }
    }
    if(M > 2 && (t + M/4 + 1 <= T))
    {
        t += (10 - M + 3)/4 + 1;
        s += 60;
        M = M%4;
    }
    if(checker(S,T,s,t) == false) 
    {
        if((T - t) * 17 >= S - s)
        {
            t += (S - s + 16) / 17;
            s = S;
        }
        else
        {
            s += (T - t) * 17;
            t = T;
        }
        if(checker(S,T,s,t) == false)
        {
            cout << "No" << endl << s;
        }
    }
}  