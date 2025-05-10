//
// Created by VuHai on 10/5/25.
//

#include <iostream>
#include <vector>
using namespace std;

long long calculate_amount_wood(vector<int> &trees, int height) {
    long long amount = 0;
    for (int tree : trees) {
        if (tree > height) {
            amount += (long long) (tree-height);
        }
    }
    return amount;
}

/*
4 7
20 15 10 17

4 24
11 2 13 13 */
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> trees(N);
    int max = 0;
    for (int i = 0; i < N; i++) {
        cin >> trees[i];
        if (trees[i] > max) {
            max = trees[i];
        }
    }

    int left = 0, right = max;
    while (left <= right) {
        int mid = left + ((right - left)/2);
        long long amount = calculate_amount_wood(trees, mid);
        if (amount > (long long) M) {
            left = mid + 1;
        } else if (amount < M) {
            right = mid - 1;
        } else {
            cout << to_string(mid);
            return 0;
        }
    }
    cout << to_string(right);
    return 0;
}