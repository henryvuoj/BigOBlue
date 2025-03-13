//
// Created by VHHV on 13/3/25.
//

#include <iostream>
#include <vector>

using namespace std;

int run(int arr1[], int arr2[], int n1, int n2, int k, int m) {
    int max = k > m ? k : m;
    int int1;
    int int2;
    for (int i = 0; i < max; i++) {
        if (i < k || m - i - 1 >= 0) {
            if (i < k) {
                int1 = arr1[i];
            }
            if (m > i && n2 - i - 1 >= 0) {
                int2 = arr2[n2 - i - 1];
            }
            if (int2 <= int1) {
                cout << "NO";
                return 0;
            }
        } else {
            cout << "YES";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}

int test1() {
    int arr1[3] = {1, 2, 3};
    int arr2[3] = {3, 4, 5};
    int n1 = 3;
    int n2 = 3;
    int k = 2;
    int m = 1;
    run(arr1, arr2, n1, n2, k , m);
}

int test2() {
    int arr1[3] = {1, 2, 3};
    int arr2[3] = {3, 4, 5};
    int n1 = 3;
    int n2 = 3;
    int k = 3;
    int m = 3;
    run(arr1, arr2, n1, n2, k , m);
}

int test3() {
    int arr1[5] = {1,1,1,1,1};
    int arr2[2] = {2,2};
    int n1 = 5;
    int n2 = 2;
    int k = 3;
    int m = 1;
    run(arr1, arr2, n1, n2, k , m);
}

int test4() {
    int arr1[4] = {3, 4, 5, 6};
    int arr2[4] = {3, 4, 5, 6};
    int n1 = 4;
    int n2 = 4;
    int k = 2;
    int m = 2;
    run(arr1, arr2, n1, n2, k , m);
}

int test5() {
    int n1 = 10;
    int n2 = 14;
    int arr1[10] = {4, 4, 8, 20, 25, 32, 35, 39, 42, 51};
    int arr2[14] = {12 ,13 ,23 ,26 ,29 ,29 ,35 ,35 ,36 ,42 ,46 ,48 ,50, 52};
    int k = 10;
    int m = 1;
    run(arr1, arr2, n1, n2, k , m);
}

int main() {
    int na;
    cin >> na;
    int nb;
    cin >> nb;
    int k;
    cin >> k;
    int m;
    cin >> m;
    int arr1[na];
    int arr2[nb];
    for (int i = 0; i < na; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < nb; i++) {
        cin >> arr2[i];
    }
    run(arr1, arr2, na, nb, k , m);


    // test1();
    // cout << endl;
    // test2();
    // cout << endl;
    // test3();
    // cout << endl;
    // test4();
    // cout << endl;
    // test5();
}