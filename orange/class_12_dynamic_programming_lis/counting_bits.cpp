//
// Created by VHHV on 18/6/25.
//

#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

int rev_count(vector<int> &dp, int n) {
    if (dp[n] != -1) {
        return dp[n];
    } else {
        int check_last_bit = n & 1;
        int next = n / 2;
        dp[n] = check_last_bit == 1 ? rev_count(dp, next) + 1 : rev_count(dp, next);
        return dp[n];
    }
}

vector<int> countBits(int n) {
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        rev_count(dp, i);
    }
    return dp;
}

int main() {
    int n = 12;
    vector<int> dp = countBits(n);
    cout << dp[n] << endl;
}
