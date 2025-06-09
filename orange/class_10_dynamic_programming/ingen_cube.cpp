//
// Created by VHHV on 9/6/25.
//

#include <iostream>
#include <vector>

using namespace std;

// void calculate(vector<long long> &dp, vector<long long> cubes, long long from, long long to) {
//     for (long long cube : cubes) {
//         if (cube <= to) {
//             long long idx = max(from, cube);
//             for (long long i = idx; i <= to; i++) {
//                 dp[i] += dp[i - cube];
//             }
//         }
//     }
// }
//
// long long main() {
//     vector<long long> dp = vector<long long>(10001);
//     dp[0] = 1;
//     long long cube_size = 21;
//     vector<long long> cubes = vector<long long>(cube_size);
//     for (long long i = 1; i <= cube_size; i++) {
//         cubes[i-1] = i * i * i;
//     }
//     long long max = 0;
//     long long n;
//     while (cin >> n) {
//         if (n > max) {
//             calculate(dp, cubes, max+1, n);
//             max = n;
//         }
//         cout << dp[n] << endl;
//     }
// }


vector<long long> calculate(vector<long long> coins, long long n) {
    long long size = n / coins[0];
    vector<long long> dp = vector<long long>(size + 1, 0);
    dp[0] = 1;
    for (long long coin : coins) {
        for (long long target = coin; target <= n; target++) {
            dp[target] += dp[target-coin];
        }
    }
    return dp;
}


//WHY THIS IS NOT WORKING
int main() {
    long long cube_size = 21;
    vector<long long> cubes = vector<long long>(cube_size);
    for (long long i = 1; i <= cube_size; i++) {
        cubes[i-1] = i * i * i;
    }
    long long n;
    vector<long long> inputs;
    long long max = 0;
    while (cin >> n) {
        inputs.push_back(n);
        max = max > n ? max : n;
    }
    vector<long long> dp = calculate(cubes, n);
    for (long long input : inputs) {
        cout << dp[input] << endl;
    }
}
