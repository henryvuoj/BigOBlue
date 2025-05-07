//
// Created by VuHai on 15/3/25.
//

#include <iostream>
#include <cstring>

using namespace std;

void run(int n, int arr[]) {
    if (n == 1) {
        cout << 1;
        return;
    }
    int alive = 1;
    int killer_idx = n - 1;
    int claw = killer_idx - arr[killer_idx];
    int idx = killer_idx - 1;
    while (idx >= 0) {
        if (idx < claw) {
            alive++;
            claw = idx - arr[idx];
        } else {
            int current_claw = idx - arr[idx];
            if (current_claw < claw) {
                claw = current_claw;
            }
        }
        idx--;
    }
    cout << alive;
}

void test1() {
    int n = 4;
    int arr[4] = {0,1,0,10};
    run(n, arr);
    cout << endl;
}

void test2() {
    int n = 2;
    int arr[2] = {0,0};
    run(n, arr);
    cout << endl;
}

void test3() {
    int n = 10;
    int arr[10] = {1, 1, 3, 0, 0, 0, 2, 1, 0, 3};
    run(n, arr);
    cout << endl;
}

int main() {
    // test1();
    // test2();
    // test3();

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    run(n, arr);
}


// void run(int n, int arr[]) {
//     if (n == 1) {
//         cout << 1;
//         return;
//     }
//     int map[10001];
//     memset(map, 0, sizeof(map));
//     int alive = 0;
//     int killer_idx = n - 1;
//     int current_claw = killer_idx - arr[killer_idx];
//     while (killer_idx >= 0) {
//         if (map[killer_idx] >= 0) {
//             alive++;
//         }
//         for (int i = current_claw < 0 ? 0 : current_claw; i < killer_idx; i++) {
//             if (map[i] >= 0) {
//                 map[i] = -1;
//             }
//         }
//         killer_idx--;
//         if (killer_idx >= 0) {
//             current_claw = killer_idx - arr[killer_idx];
//         }
//     }
//     cout << alive;
// }
