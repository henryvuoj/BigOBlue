//
// Created by VuHai on 15/3/25.
//

#include <iostream>
#include <cstring>

using namespace std;

void run(int n, int arr[]) {
    int first = 0;
    int second = 0;
    int up_range = arr[first] > arr[second] ? arr[first] : arr[second];
    int down_range = arr[first] < arr[second] ? arr[first] : arr[second];
    int max = -1;
    while (first < n && second < n) {
        if (up_range == down_range) {
            if (arr[second] - up_range == 1) {
                up_range = arr[second];
                second++;
            } else if (arr[second] - up_range == -1) {
                down_range = arr[second];
                second++;
            } else if (arr[second] == up_range) {
                second++;
            } else {
                if (second - first > max) {
                    max = second - first;
                }
                first++;
                second = first;
            }
        } else {
            if (arr[second] <= up_range && arr[second] >= down_range) {
                second++;
            } else {
                if (second - first > max) {
                    max = second - first;
                }
                first++;
                second = first;
                up_range = arr[second];
                down_range = arr[second];
            }
        }
    }
    if (second - first > max) {
        max = second - first;
    }
    cout << max;
}

void test1() {
    int n = 5;
    int arr[5] = {1,2,3,3,2};
    run(n, arr);
    cout << endl;
}

void test2() {
    int n = 11;
    int arr[11] = {5, 4, 5, 5, 6, 7, 8, 8, 8, 7, 6};
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