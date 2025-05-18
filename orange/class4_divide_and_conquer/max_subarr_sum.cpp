//
// Created by VuHai on 17/5/25.
//

#include <vector>
#include <iostream>
#include <ostream>
#include <algorithm>
#define INF -10000000

using namespace std;

int max_mid_subarr_sum(vector<int> arr, int left, int mid, int right) {
    int sum = 0;
    int left_sum = INF;
    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        left_sum = max(left_sum, sum);
    }
    sum = 0;
    int right_sum = INF;
    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        right_sum = max(right_sum, sum);
    }
    return left_sum + right_sum;
}

int max_subarr_sum(vector<int> arr, int left, int right) {
    if (left >= right) {
        return arr[left];
    }
    int mid = (right + left) / 2;
    int max_sum_left = max_subarr_sum(arr, left, mid);
    int max_sum_right = max_subarr_sum(arr, mid + 1, right);
    int max_sum_mid = max_mid_subarr_sum(arr, left, mid, right);
    return max(max(max_sum_left, max_sum_right), max_sum_mid);
}

int main() {
    vector<int> arr = {-3,-8,7,-2,-3,5,-4,6,-9,2};
    cout << max_subarr_sum(arr, 0, arr.size() - 1) << endl;
}
