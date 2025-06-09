//
// Created by VuHai on 8/6/25.
//

#include <iostream>
#include <set>
using namespace std;

int rev(set<int> &dp, int &sum, int idx, int K, int N) {
    if (idx >= N) return 0;

}

int main() {
    int N, K;
    cin >> N >> K;
    set<int> dp;
    int sum = 0;
    return rev(dp, sum, 1, N, K);
}