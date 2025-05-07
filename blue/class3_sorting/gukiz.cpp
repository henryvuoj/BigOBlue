//
// Created by VHHV on 20/3/25.
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

void run(int n, int arr[]) {
    int sorted_arr[n];
    memcpy(sorted_arr, arr, n * sizeof(int));
    sort(sorted_arr, sorted_arr+n, greater<int>());
    int map[2002];
    memset(map, 0, sizeof(map));
    int last_value = -1;
    for (int i = 0; i < n; i++) {
        if (sorted_arr[i] != last_value) {
            map[sorted_arr[i]] = i + 1;
            last_value = sorted_arr[i];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << map[arr[i]] << " ";
    }
}

void test1() {
    int n = 3;
    int arr[3] = {1, 3, 3};
    run(n, arr);
    cout << endl;
}

void test2() {
    int n = 1;
    int arr[1] = {1};
    run(n, arr);
    cout << endl;
}

void test3() {
    int n = 5;
    int arr[5] = {3, 5, 3, 4, 5};
    run(n, arr);
    cout << endl;
}

int main() {
    // test1();
    // test2();
    // test3();

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    run(n, arr);
}