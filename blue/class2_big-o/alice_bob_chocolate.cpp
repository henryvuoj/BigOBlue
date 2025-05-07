//
// Created by VuHai on 15/3/25.
//

#include <iostream>
#include <cstring>

using namespace std;

void run(int n, int arr[]) {
    if (n == 1) {
        cout << "1 0";
        return;
    }
    int l = 0;
    int r = n - 1;
    int l_time = arr[l];
    int r_time = arr[r];
    while (l < r) {
        if (l_time < r_time) {
            if (l == r - 1) {
                r_time -= arr[r];
                l_time -= arr[l];
                break;
            } else {
                r_time -= l_time;
                l++;
                l_time = arr[l];
            }
        } else if (l_time > r_time) {
            if (l == r - 1) {
                r_time -= arr[r];
                l_time -= arr[l];
                break;
            } else {
                l_time -= r_time;
                r--;
                r_time = arr[r];
            }
        } else {
            l++;
            r--;
            r_time = arr[r];
            l_time = arr[l];
        }
    }
    if (r < l) {
        cout << l << " " << n - r - 1<< endl;
    } else if (r == l) {
        cout << l + 1 << " " << n - r - 1<< endl;
    } else {
        cout << l + 1 << " " << n - r;
    }
}

int test1() {
    int n = 5;
    int arr[5] = {2,9,8,2,7};
    run(n, arr);
    cout << endl;
}

int test2() {
    int n = 3;
    int arr[3] = {1, 1, 1};
    run(n, arr);
    cout << endl;
}

int test3() {
    int n = 1;
    int arr[1] = {1};
    run(n, arr);
    cout << endl;
}

int test4() {
    int n = 2;
    int arr[2] = {1,1};
    run(n, arr);
    cout << endl;
}

int test5() {
    int n = 2;
    int arr[2] = {8,2};
    run(n, arr);
    cout << endl;
}


int main() {
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    run(n, arr);
}