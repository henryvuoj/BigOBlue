//
// Created by VuHai on 8/6/25.
//

#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

int coin_change(vector<int> coins, int n) {
    int size = n / coins[0];
    vector<int> dp = vector<int>(size + 1, 0);
    dp[0] = 1;
    for (int coin : coins) {
        for (int target = coin; target <= n; target++) {
            dp[target] += dp[target-coin];
        }
    }
    return dp[n];
}

int coin_change_print_result(vector<int> coins, int n) {
    int size = n / coins[0];
    vector<int> dp = vector<int>(size + 1, 0);
    dp[0] = 1;
    for (int coin : coins) {
        for (int target = coin; target <= n; target++) {
            dp[target] += dp[target-coin];
        }
    }
    return dp[n];
}

int main() {
    int n = 10;
    vector<int> coins = {1, 2, 5, 10};
    cout << coin_change(coins, n) << endl;
}