#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

void radixSort(vector<int>& arr) {
    int maxNum = *max_element(arr.begin(), arr.end());

    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        vector<list<int>> buckets(10);

        for (int num : arr) {
            int index = num / exp;
            buckets[index % 10].push_back(num);
        }

        int i = 0;
        for (auto& bucket : buckets) {
            for (int num : bucket) {
                arr[i++] = num;
            }
        }
    }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    radixSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
