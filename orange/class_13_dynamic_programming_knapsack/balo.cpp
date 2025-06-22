//
// Created by VuHai on 22/6/25.
//

#include <iostream>
#include <map>
#include <ostream>

using namespace std;

int knapsack(int max_weight, vector<pair<int, int>> items) {
    vector<vector<int>> dp(items.size()+1, vector<int>(max_weight+1, 0));

    for (int i = 1; i <= items.size(); i++) {
        for (int w = 1; w <= max_weight; w++) {
            int item_value = items[i-1].first;
            int item_weight = items[i-1].second;

            int optimized_value = dp[i-1][w];
            if (item_weight <= w) {
                optimized_value = max(
                    optimized_value,
                    item_value + dp[i-1][w-item_weight]
                );
            }
            dp[i][w] = optimized_value;
        }
    }
    return dp[items.size()][max_weight];
}

int main() {
    int max_weight = 10;
    vector<pair<int, int>> items = {
        {1,1},
        {2,1},
        {2,2},
        {10,4}
    };
    int max_value = knapsack(max_weight, items);
    cout << max_value << endl;
}