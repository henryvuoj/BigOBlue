//
// Created by VuHai on 8/6/25.
//

#include <iostream>
#include <map>
using namespace std;

long int dynamic_rev(long int a, map<long int, long int> &dp) {
    if (a < 2) return a;
    if (dp.count(a)) return dp[a];
    dp[a] = max(a, dynamic_rev(a/2, dp) + dynamic_rev(a/3, dp) + dynamic_rev(a/4, dp));
    return dp[a];
}

long int exchange(long int a) {
    map<long int, long int> dp = map<long int, long int>();
    return dynamic_rev(a, dp);
}

int main() {
    long int n;
    while (cin >> n) {
        cout << exchange(n) << endl;
    }
}