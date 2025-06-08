//
// Created by VuHai on 8/6/25.
//

#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

int dynamic_programming(int n, vector<int> &dp) {
    if (n < 2) return n;
    if (dp[n]) return dp[n];
    dp[n] = dynamic_programming(n - 1, dp) + dynamic_programming(n - 2, dp);
    return dp[n];
}

int stair_case(int n) {
    vector<int> dp = vector<int>(n + 1, 0);
    dp[1] = 1;
    return dynamic_programming(n, dp);
}

int main() {
    int n = 7;
    cout << stair_case(n) << endl;
}