//
// Created by VHHV on 19/3/25.
//

#include <iostream>
#include <algorithm>

using namespace std;


void run(int n, int a, int b, int arr[]) {
    sort(arr, arr + n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        count++;
        if (count == b) {
            if (i != n - 1) {
                int diff = arr[i+1] - arr[i];
                if (diff > 0) {
                    cout << diff;
                    return;
                } else {
                    cout << 0;
                    return;
                }
            } else {
                cout << 0;
                return;
            }
        }
    }
    cout << 0;
    return;
}

void test1() {
    int n = 5;
    int a = 2;
    int b = 3;
    int arr[5] = {6, 2, 3, 100, 1};
    run(n, a, b, arr);
    cout << endl;
}

void test2() {
    int n = 7;
    int a = 3;
    int b = 4;
    int arr[7] = {1,1,9,1,1,1,1};
    run(n, a, b, arr);
    cout << endl;
}

int main() {
    // test1();
    // test2();
    int n;
    cin >> n;
    int a;
    cin >> a;
    int b;
    cin >> b;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    run(n, a, b, arr);
}