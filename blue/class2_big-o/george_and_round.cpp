//
// Created by VuHai on 15/3/25.
//
#include <iostream>

using namespace std;

void run(int n, int m, int arr_a[], int arr_b[]) {
    int idx_a = 0;
    int idx_b = 0;
    int count = 0;
    while (idx_a < n) {
        if (idx_b < m) {
            if (arr_b[idx_b] >= arr_a[idx_a]) {
                idx_a++;
            }
            idx_b++;
        } else {
            idx_a++;
            count++;
        }
    }
    cout << count;
    return;
}

void test1() {
    int m = 3;
    int n = 5;
    int arr_a[] = {1, 2, 3};
    int arr_b[] = {1, 2, 2, 3, 3};
    run(m, n, arr_a, arr_b);
    cout << endl;
}

void test2() {
    int m = 3;
    int n = 5;
    int arr_a[] = {1, 2, 3};
    int arr_b[] = {1, 1, 1, 1, 1};
    run(m, n, arr_a, arr_b);
    cout << endl;
}

void test3() {
    int m = 3;
    int n = 1;
    int arr_a[] = {2, 3, 4};
    int arr_b[] = {1};
    run(m, n, arr_a, arr_b);
    cout << endl;
}

int main() {
    // test1();
    // test2();
    // test3();

    int n;
    cin >> n;
    int m;
    cin >> m;
    int arr_a[n];
    int arr_b[m];
    for (int i = 0; i < n; i++) {
        cin >> arr_a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> arr_b[i];
    }
    run(n, m, arr_a, arr_b);
}