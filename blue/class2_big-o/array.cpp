//
// Created by VHHV on 14/3/25.
//

#include <iostream>
#include <cstring>

using namespace std;

void run(int n, int k, int arr[]) {
    int count = 0;
    int map[100002];
    memset(map, 0, sizeof(map));
    int start = 0;
    int end = 0;
    int min_start = -1;
    int min_end = 1000000;
    for (int i = 0; i < n; i++) {
        if (map[arr[i]] == 0) {
            count++;
            map[arr[i]]++;
            end++;
            if (count == k) {
                //Move up the start to as far as it can go
                for (int j = start; j <= end; j++) {
                    if (map[arr[j]] > 1) {
                        map[arr[j]]--;
                        start++;
                    } else {
                        break;
                    }
                }
                if (start > min_start && end < min_end) {
                    min_start = start;
                    min_end = end;
                    for (int j = start; j <= end; j++) {
                        map[arr[j]]--;
                        if (map[arr[j]] == 0) {
                            count--;
                            start = j+1;
                            break;
                        }
                    }
                }
            }
        } else {
            map[arr[i]]++;
            end++;
        }

    }
    if (min_start == -1 || min_end == 1000000) {
        cout << "-1 -1";
    } else {
        cout << min_start + 1 << " " << min_end;
    }
}

void test1() {
    int n = 4;
    int k = 2;
    int arr[] = {1, 2, 2, 3};
    run(n, k, arr);
    cout << endl;
}

void test2() {
    int n = 8;
    int k = 3;
    int arr[] = {1, 1, 2, 2, 3, 3, 4, 5};
    run(n, k, arr);
    cout << endl;
}

void test3() {
    int n = 7;
    int k = 4;
    int arr[] = {4, 7, 7, 4, 7, 4, 7};
    run(n, k, arr);
    cout << endl;
}

void test4() {
    int n = 8;
    int k = 3;
    int arr[] = {1, 1, 1, 1, 1, 1, 4, 5};
    run(n, k, arr);
    cout << endl;
}

void test5() {
    int n = 50;
    int k = 7;
    int arr[] = {2, 5, 6, 5, 2, 1, 7, 9, 7, 2, 5, 5, 2, 4, 7, 6, 2, 2, 8, 7, 7, 9, 8, 1, 9, 6, 10, 8, 8, 6, 10, 3, 3, 9, 1, 10, 5, 8, 1, 10, 7, 8, 4, 8, 6, 5, 1, 10, 2, 5};
    run(n, k, arr);
    cout << endl;
}

void test6() {
    int n = 100000;
    int k = 50000;
    int arr[100000];
    memset(arr, 0, sizeof(arr));
    for (int i = 50000; i < n; i++) {
        arr[i] = i - 50000;
    }
    run(n, k, arr);
    cout << endl;
}


int main() {
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();

    int n;
    cin >> n;
    int k;
    cin >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    run(n, k, arr);
}


// class Data {
// public:
//     int count;
//     int start;
//
//     Data(int c = 0, int s = 0) : count(c), start(s) {}
// };
//
// void run(int n, int k, int arr[]) {
//
//     Data map[10001];
//     vector<int> vec;
//
//     for (int i = 0; i < n; i++) {
//        if (map[arr[i]].count == 0) {
//             map[arr[i]].start = i;
//             vec.push_back(arr[i]);
//        }
//         map[arr[i]].count++;
//     }
//
//     int min = 100000;
//     int start_min = 0;
//     int end_min = 0;
//     if (static_cast<int>(vec.size()) >= k) {
//         for (int i = 0; i <= static_cast<int>(vec.size()) - k; i++) {
//             int sum = 0;
//             for (int j = 0; j < k; j++) {
//                 if (j == 0 || j == k - 1) {
//                     sum++;
//                 } else {
//                     sum += map[vec.at(i+j)].count;
//                 }
//             }
//             if (sum < min) {
//                 min = sum;
//                 start_min = map[vec.at(i)].start + map[vec.at(i)].count - 1;
//                 end_min = map[vec.at(i+k-1)].start;
//                 break;
//             }
//         }
//         cout << start_min + 1 << " " << end_min + 1 << endl;
//     } else {
//         cout << "-1 -1";
//     }
//     return;
// }