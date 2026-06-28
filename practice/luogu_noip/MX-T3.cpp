#include <bits/stdc++.h>
using namespace std;

// 构建最长前缀后缀（LPS）数组
vector<int> computeLPS(string pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);  // lps[i] 表示 pattern[0..i] 的最长前缀后缀长度

    int len = 0;  // 已匹配的前缀后缀长度
    int i = 1;

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// KMP算法进行字符串匹配
int kmpSearch(string text, string pattern) {
    vector<int> lps = computeLPS(pattern);
    vector<int> matches;

    int n = text.size();
    int m = pattern.size();
    int i = 0;  // 指向text的索引
    int j = 0;  // 指向pattern的索引

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {  // 找到匹配
            matches.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    // 确保返回的匹配位置之间不重叠
    vector<int> nonOverlappingMatches;
    int prevMatchEnd = -1;
    for (int match : matches) {
        if (match > prevMatchEnd) {
            nonOverlappingMatches.push_back(match);
            prevMatchEnd = match + m - 1;
        }
    }

    return nonOverlappingMatches.size();
}

int main() {
    int n;
    string s;
    cin>>n>>s;
    int q;
    cin>>q;
    while(q--){
        int r,k,ans;
        cin>>r>>k;
        
       for(int i = r/2;i;i--)
       {
            string s1 = s.substr(0,i),s2 = s.substr(r-i,i);
            
       }
    }
    /*string text = "cccccccccccccccccccc";
    string pattern = "ccc";
    
    vector<int> matches = kmpSearch(text, pattern);
    
    if (matches.size() == 0) {
        cout << "Pattern not found in text." << endl;
    } else {
        cout << "Pattern found at positions:";
        for (int i = 0; i < matches.size(); ++i) {
            cout << " " << matches[i];
        }
        cout << endl;
    }

    return 0;*/
}
