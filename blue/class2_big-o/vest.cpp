//
// Created by VuHai on 15/3/25.
//

#include <iostream>
#include <vector>

using namespace std;

void run(int n, int m, int x, int y, int arr_a[], int arr_b[]) {
    int idx_a = 0;
    int idx_b = 0;
    int count = 0;
    vector<int> res_a;
    vector<int> res_b;
    while (idx_a < n && idx_b < m) {
        if (arr_b[idx_b] < arr_a[idx_a] - x) {
            idx_b++;
        } else if (arr_b[idx_b] > arr_a[idx_a] + y) {
            idx_a++;
        } else {
            res_a.push_back(idx_a + 1);
            res_b.push_back(idx_b + 1);
            count++;
            idx_a++;
            idx_b++;
        }
    }
    cout << count << endl;
    for (int i = 0; i < res_a.size(); i++) {
        cout << res_a[i] << " " << res_b[i] << endl;
    }
}

void test1() {
    int n = 5;
    int m = 3;
    int x = 0;
    int y = 0;
    int arr_a[] = {1, 2, 3, 3, 4};
    int arr_b[] = {1, 3, 5};
    run(n, m, x, y, arr_a, arr_b);
}

void test2() {
    int n = 3;
    int m = 3;
    int x = 2;
    int y = 2;
    int arr_a[] = {1, 5, 9};
    int arr_b[] = {3, 5, 7};
    run(n, m, x, y, arr_a, arr_b);
}

int main() {
    // test1();
    // test2();

    int n;
    cin >> n;
    int m;
    cin >> m;
    int x;
    cin >> x;
    int y;
    cin >> y;
    int arr_a[n];
    int arr_b[m];
    for (int i = 0; i < n; i++) {
        cin >> arr_a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> arr_b[i];
    }
    run(n, m, x, y, arr_a, arr_b);
}