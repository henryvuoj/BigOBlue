//
// Created by VuHai on 16/6/25.
//

#include <iostream>
#include <vector>

using namespace std;

int lis(vector<int> v) {
    vector<int> dp(v.size());
    dp[0] = 1;
    for (int i = 1; i < v.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[v.size() - 1];
}

int lds(vector<int> v) {
    vector<int> dp(v.size());
    dp[0] = 1;
    for (int i = 1; i < v.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] > v[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    if (dp[v.size() - 1] == 0) {
        return -1;
    }
    return dp[v.size() - 1];
}


int lds_binary_search(vector<int> v) {
    vector<int> result(v.size());
    result.push_back(0);
    for (int i = 1; i < v.size(); i++) {

    }
}

int main() {
    // vector<int> arr = {389, 207, 155, 300, 299, 170, 158, 65};
    // vector<int> arr = {23, 34, 21};
    // vector<int> arr = {23, 34, 56};
    // cout << lds(arr) << endl;


}