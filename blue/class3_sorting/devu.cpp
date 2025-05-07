//
// Created by VuHai on 19/3/25.
//

#include <iostream>
#include <algorithm>

using namespace std;

void run(int n, int x, int arr[]) {
    sort(arr, arr + n);
    __int128 count = 0;
    for (int i = 0; i < n; i++) {
        count += (__int128)arr[i] * x;
        if (x > 1) {
            x--;
        }
    }
    string result;
    while (count > 0) {
        result += '0' + (count % 10);
        count /= 10;
    }
    reverse(result.begin(), result.end());
    cout << result;
}

void test1() {
    int n = 2;
    int x = 3;
    int arr[2] = {4, 1};
    run(n, x, arr);
    cout << endl;
}

int test2() {
    int n = 4;
    int x = 2;
    int arr[4] = {5, 1, 2, 1};
    run(n, x, arr);
    cout << endl;
}

int test3() {
    int n = 3;
    int x = 3;
    int arr[3] = {1, 1, 1};
    run(n, x, arr);
    cout << endl;
}

int main() {
    // test1();
    // test2();
    // test3();
    int n;
    cin >> n;
    int x;
    cin >> x;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    run(n, x, arr);
}