#include <iostream>
#include <deque>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int max_removed_cards(int n, const vector<int>& cards) {
    deque<int> dq;
    unordered_map<int, int> last_pos;
    int total_removed = 0;

    for (int i = 0; i < n; ++i) {
        int card = cards[i];
        
        // Case 1: Insert at the left
        dq.push_front(card);
        if (dq.size() > 1 && dq.front() == dq[1]) {
            int start_idx = 0;
            int end_idx = 1;
            while (end_idx < dq.size() && dq[end_idx] != dq.front()) {
                ++end_idx;
            }
            if (end_idx < dq.size()) {
                total_removed = max(total_removed, static_cast<int>(end_idx + 1));  // Including the two matching cards
                dq.erase(dq.begin(), dq.begin() + end_idx + 1);
            } else {
                dq.pop_front();
            }
        }
        
        // Case 2: Insert at the right
        dq.push_back(card);
        if (dq.size() > 1 && dq.back() == dq[dq.size() - 2]) {
            int start_idx = dq.size() - 2;
            int end_idx = dq.size() - 1;
            while (start_idx >= 0 && dq[start_idx] != dq.back()) {
                --start_idx;
            }
            if (start_idx >= 0) {
                total_removed = max(total_removed, static_cast<int>(dq.size() - start_idx));  // Including the two matching cards
                dq.erase(dq.begin() + start_idx, dq.end());
            } else {
                dq.pop_back();
            }
        }
    }

    return total_removed;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        vector<int> cards(n);
        for (int i = 0; i < n; ++i) {
            cin >> cards[i];
        }
        cout << max_removed_cards(n, cards) << '\n';
    }

    return 0;
}
