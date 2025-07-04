//
// Created by VuHai on 15/6/25.
//

#include <iostream>
#include <ostream>

#include "vector"
using namespace std;

int lis_dynamic(vector<int> list) {
    vector<int> dp(list.size());
    vector<int> path(list.size());
    dp[0] = 1;
    for (int i = 1; i < list.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (list[i] > list[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    return dp[list.size()-1];
}

string lis_dynamic_print_result(vector<int> list) {
    vector<int> dp(list.size());
    vector<int> path(list.size(), -1);
    dp[0] = 1;
    for (int i = 1; i < list.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (list[i] > list[j]) {
                if (dp[j]+1 > dp[i]) {
                    dp[i] = dp[j]+1;
                    path[i] = j;
                }
            }
        }
    }
    string result = "";
    int i = list.size() - 1;
    while (i > 0) {
        int new_i = path[i];
        result = to_string(list[new_i]) + string(" ")  + result;
        i = new_i;
    }
    return result;
}

int binary_search(vector<int> list, vector<int> result, int target) {
    int left = 0;
    int right = result.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (list[result[mid]] < target) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int lis_dynamic_binary_search(vector<int> list) {
    vector<int> result;
    result.push_back(0);
    for (int i = 1; i < list.size(); i++) {
        int pos = binary_search(list, result, list[i]);
        if (pos == -1) {
            result.push_back(i);
        } else {
            result[pos] = i;
        }
    }
    return result.size();
}

int main() {
    vector<int> list = {2, 5, 12, 3, 10, 6, 8, 14, 4, 11, 7, 15};
    // cout << lis_dynamic(list) << endl;
    // cout << lis_dynamic_print_result(list) << endl;
    cout << lis_dynamic_binary_search(list) << endl;
}