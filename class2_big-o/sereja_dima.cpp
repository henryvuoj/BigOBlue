//
// Created by VuHai on 15/3/25.
//

#include <iostream>

using namespace std;

void run(int n, int arr[]) {
    int l = 0;
    int r = n - 1;
    int s1 = 0;
    int s2 = 0;
    bool is_s1_turn = true;
    while (l <= r) {
        if (is_s1_turn) {
            if (arr[l] > arr[r]) {
                s1 += arr[l];
                l++;
            } else {
                s1 += arr[r];
                r--;
            }
        } else {
            if (arr[l] > arr[r]) {
                s2 += arr[l];
                l++;
            } else {
                s2 += arr[r];
                r--;
            }
        }
        is_s1_turn = !is_s1_turn;
    }
    cout << s1 << " " << s2;
}

void test1() {
    int n = 4;
    int arr[4] = {4, 1, 2, 10};
    run(n, arr);
    cout << endl;
}

void test2() {
    int n = 7;
    int arr[7] = {1,2,3,4,5,6,7};
    run(n, arr);
    cout << endl;
}

int main() {
    // test1();
    // test2();
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    run(n, arr);
}