//
// Created by VuHai on 22/6/25.
//
#include <iostream>
#include <map>
#include <ostream>

using namespace std;

vector<int> knapsack_core(int max_weight, vector<pair<int, int>> items) {
    vector<int> dp(max_weight+1, 0);
    for (int w = 1; w <= max_weight; w++) {
        int maxVal = 0;
        for (pair<int, int> item : items) {
            if (item.second <= w) {
                maxVal = max(maxVal, item.first + dp[w - item.second]);
            }
        }
        dp[w] = maxVal;
    }
    return dp;
}

int knapsack_max(int max_weight, vector<pair<int, int>> items) {
    vector<int> dp = knapsack_core(max_weight, items);
    return dp[max_weight];
}

int main() {
    int max_weight = 10;
    vector<pair<int, int>> items = {
        {1,1},
        {2,1},
        {2,2},
        {10,4}
    };
    cout << knapsack_max(max_weight, items);
}