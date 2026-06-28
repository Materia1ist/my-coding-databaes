#include <bits/stdc++.h>

using namespace std;

bool is_flash(const string &str)
{
    string lower_str = str;
    transform(lower_str.begin(), lower_str.end(), lower_str.begin(), ::tolower);
    return lower_str.find("rioi") != string::npos;
}

int main()
{
    string s, t;
    getline(cin, s);
    getline(cin, t);
    bool s_flash = is_flash(s);
    bool t_flash = is_flash(t);
    if (s_flash && t_flash)
    {
        cout << "Either is ok!" << endl;
    }
    else if (s_flash)
    {
        cout << s << " for sure!" << endl;
    }
    else if (t_flash)
    {
        cout << t << " for sure!" << endl;
    }
    else
    {
        cout << "Try again!" << endl;
    }

    return 0;
}
