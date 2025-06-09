//
// Created by VHHV on 9/6/25.
//

#include <iostream>
#include <vector>

using namespace std;

// void calculate(vector<long int> &dp, vector<long int> cubes, long int from, long int to) {
//     for (long int cube : cubes) {
//         if (cube <= to) {
//             long int idx = max(from, cube);
//             for (long int i = idx; i <= to; i++) {
//                 dp[i] += dp[i - cube];
//             }
//         }
//     }
// }
//
// long int main() {
//     vector<long int> dp = vector<long int>(10001);
//     dp[0] = 1;
//     long int cube_size = 21;
//     vector<long int> cubes = vector<long int>(cube_size);
//     for (long int i = 1; i <= cube_size; i++) {
//         cubes[i-1] = i * i * i;
//     }
//     long int max = 0;
//     long int n;
//     while (cin >> n) {
//         if (n > max) {
//             calculate(dp, cubes, max+1, n);
//             max = n;
//         }
//         cout << dp[n] << endl;
//     }
// }


long int calculate(vector<long int> coins, long int n) {
    long int size = n / coins[0];
    vector<long int> dp = vector<long int>(size + 1, 0);
    dp[0] = 1;
    for (long int coin : coins) {
        for (long int target = coin; target <= n; target++) {
            dp[target] += dp[target-coin];
        }
    }
    return dp[n];
}


int main() {
    long int cube_size = 21;
    vector<long int> cubes = vector<long int>(cube_size);
    for (long int i = 1; i <= cube_size; i++) {
        cubes[i-1] = i * i * i;
    }
    long int n;
    while (cin >> n) {
        cout << calculate(cubes, n) << endl;
    }
}
