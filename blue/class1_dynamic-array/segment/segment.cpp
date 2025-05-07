//
// Created by VHHV on 13/3/25.
//

#include <limits.h>
#include <iostream>
#include <vector>

using namespace std;

int run(int n, int arr[][2]) {
    int min = INT_MAX;
    int max = INT_MIN;
    int idx = -1;
    for (int i = 0; i < n; i++) {
        if (min > arr[i][0]) {
            min = arr[i][0];
            idx = -1;
        }
        if (max < arr[i][1]) {
            max = arr[i][1];
            idx = -1;
        }
        if (arr[i][0] == min && arr[i][1] == max) {
            idx = i;
        }
    }
    if (idx == -1) {
        cout << -1;
    } else {
        cout << idx + 1;
    }
    return 0;
}

int test1() {
    int n = 3;
    int arrs[][2] = { {3, 3}, {4, 4}, {5, 5} };
    run(n, arrs);
}

int test2() {
    int n = 6;
    int arrs[][2] = { {1, 5}, {2, 3}, {1, 10}, {7, 10}, {7, 7}, {10, 10} };
    run(n, arrs);
}

int main() {
    int n;
    cin >> n;
    int arrs[n][2];
    for (int i = 0; i < n; i++) {
        cin >> arrs[i][0];
        cin >> arrs[i][1];
    }
    run(n, arrs);

    // test1();
    // cout << endl;
    // test2();
}