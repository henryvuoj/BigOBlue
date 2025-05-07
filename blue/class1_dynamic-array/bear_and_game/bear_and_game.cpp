//
// Created by VHHV on 12/3/25.
//

#include <iostream>
#include <vector>

using namespace std;


int run(int n, int arr[]) {
    int last_min = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] - last_min > 15) {
            return last_min + 15;
        } else {
            last_min = arr[i];
        }
    }
    return 90 > last_min + 15 ? last_min + 15 : 90;
}

int test1() {
    int n = 3;
    int arr[] = {7, 20, 88};
    cout << run(n, arr) << endl;
}

int test2() {
    int n = 9;
    int arr[] = {16, 20, 30, 40, 50, 60, 70, 80, 90};
    cout << run(n, arr) << endl;
}

int test3() {
    int n = 9;
    int arr[] = {15, 20, 30, 40, 50, 60, 70, 80, 90};
    cout << run(n, arr) << endl;
}

int test4() {
    int n = 5;
    int arr[] = {14, 29, 44, 59, 73};
    cout << run(n, arr) << endl;
}

int main() {
    // int n;
    // cin >> n;
    //
    // int arr[n];
    // for (int i = 0; i < n; i++) {
    //     cin >> arr[i];
    // }
    //
    // cout << run(n, arr) << endl;
    test1();
    test2();
    test3();
    test4();
}