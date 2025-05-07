//
// Created by VuHai on 15/3/25.
//
#include <iostream>

using namespace std;

void run(int n, int t, int arr[]) {
    int first = 0;
    int second = 0;
    int time = t;
    int count = 0;
    int max = 0;
    while (first < n) {
        if (first == second) {
            if (time > arr[first]) {
                time -= arr[first];
                count++;
                if (count > max) {
                    max = count;
                }
            } else {
                second++;
            }
            first++;
        } else {
            if (time >= arr[first]) {
                time -= arr[first];
                count++;
                first++;
                if (count > max) {
                    max = count;
                }
            } else {
                if (count > max) {
                    max = count;
                }
                time += arr[second];
                if (count > 0) {
                    count--;
                }
                second++;
            }
        }
    }
    cout << max;
    return;
}

void test1() {
    int n = 4;
    int t = 5;
    int arr[] = {3, 1, 2, 1};
    run(n, t, arr);
    cout << endl;
}
void test2() {
    int n = 3;
    int t = 3;
    int arr[] = {2,2,3};
    run(n, t, arr);
    cout << endl;
}

int main() {
    // test1();
    // test2();

    int n;
    cin >> n;
    int t;
    cin >> t;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    run(n, t, arr);
}