//
// Created by VuHai on 10/5/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//1,2,3,5
int binary_search(vector<int> arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + ((right - left) / 2);
        if (target == arr[mid]) {
            if (mid == 0) {
                return 0;
            } else {
                if (arr[mid] != arr[mid-1]) {
                   return mid;
                } else {
                    right = mid;
                }
            }
        } else if (target < arr[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}
/*
4 1
2
3
5
1
5
 */
int main() {
    int count = 1;
    while (true) {
        int N, Q;
        cin >> N >> Q;
        if (N == 0 && Q == 0) return 0;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        vector<string> results;
        for (int i = 0; i < Q; i++) {
            int q;
            cin >> q;
            int res = binary_search(arr, q);
            if (res == -1) {
                results.push_back(to_string(q) + " not found");
            } else {
                results.push_back(to_string(q) + " found at " + to_string(res + 1));
            }
        }
        cout << "CASE# " << count << ": " << endl;
        for (int i = 0; i < results.size(); i++) {
            cout << results[i] << endl;
        }
        count++;
    }
}