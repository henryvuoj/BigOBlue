//
// Created by VHHV on 19/3/25.
//

#include <iostream>
#include <algorithm>

using namespace std;

void run(int n, int arr[]) {
    if (n == 1) {
        cout << "yes" << endl;
        cout << 1 << " " << 1;
        return;
    }

    int start_decs = -1;
    int min_decs_value = -1;
    int max_decs_value = -1;
    int end_decs = -1;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            if (start_decs == -1) {
                start_decs = i - 1;
                if (i > 1) {
                    min_decs_value = arr[i - 2];
                }
                max_decs_value = arr[i - 1];
            } else {
                if (end_decs != -1) {
                    cout << "no";
                    return;
                }
            }
            if (arr[i] < min_decs_value) {
                cout << "no";
                return;
            }
        } else {
            if (start_decs != -1 && end_decs == -1) {
                end_decs = i - 1;
            }
            if (end_decs != -1) {
                if (arr[i] < max_decs_value) {
                    cout << "no";
                    return;
                }
            }
        }
    }
    if (start_decs == -1 && end_decs == -1) {
        cout << "yes" << endl;
        cout << 1 << " " << 1;
        return;
    }
    if (start_decs == -1) {
        start_decs = 0;
    }
    if (end_decs == -1) {
        end_decs = n - 1;
    }
    cout << "yes" << endl;
    cout << start_decs + 1 << " " << end_decs + 1;
}

void test0() {
    int n = 4;
    int arr[4] = {1, 2, 3, 4};
    //if start == -1 && end == -1
    run(n, arr);
    cout << endl;
}

void test1() {
    int n = 4;
    int arr[4] = {4, 3, 2, 1};
    //if start == 0 && end == -1
    run(n, arr);
    cout << endl;
}

void test2() {
    int n = 4;
    int arr[4] = {1, 2, 6, 5};
    //if start == 2 && end == -1
    run(n, arr);
    cout << endl;
}

void test3() {
    int n = 4;
    int arr[4] = {5, 1, 2, 3};
    //if start = 0 && end = 2
    run(n, arr);
    cout << endl;
}

void test4() {
    int n = 4;
    int arr[4] = {1, 4, 3, 6};
    //if start = 1 && end = 2
    run(n, arr);
    cout << endl;
}

void test5() {
    int n = 4;
    int arr[4] = {3, 1, 6, 4};
    run(n, arr);
    cout << endl;
}

void test6() {
    int n = 4;
    int arr[4] = {2, 1, 3, 4};
    run(n, arr);
    cout << endl;
}

void test7() {
    int n = 2;
    int arr[2] = {58, 4};
    run(n, arr);
    cout << endl;
}

void test8() {
    int n = 6;
    int arr[6] = {169793171, 335736854, 449917902, 513287332, 811627074, 938727967};
    run(n, arr);
    cout << endl;
}



int main() {
    // test0();
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    // test7();
    // test8();

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    run(n, arr);
}