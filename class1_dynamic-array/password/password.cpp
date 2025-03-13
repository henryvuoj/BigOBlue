//
// Created by VHHV on 13/3/25.
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int cal_step(int steps, int n, int k) {
    int lag_amount = steps / k;
    if (steps % k == 0) {
        if (lag_amount > 0) {
            lag_amount--;
        }
        return steps + lag_amount * 5;
    } else {
        return steps + (lag_amount) * 5;
    }

}

int run(int n, int k, string arr[]) {
    int map[101];
    memset(map, 0, sizeof(map));
    int key_length = arr[n].size();
    for (int i = 0; i < n; i++) {
        map[arr[i].size()]++;
    }
    int min = 0;
    for (int i = 1; i < key_length; i++) {
        min += map[i];
    }
    int max = min + map[key_length];
    min++;
    cout << cal_step(min, n, k) << " " << cal_step(max, n, k);
    return 0;
}

int test1() {
    int n = 5;
    int k = 2;
    string arr[] = {"cba", "abc", "bb1", "abC", "ABC", "abc"};
    run(n, k, arr);
}

int test2() {
    int n = 4;
    int k = 100;
    string arr[] = {"11", "22", "1", "2", "22"};
    run(n, k, arr);
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    string arr[n + 1];
    for (int i = 0; i < n + 1; i++) {
        cin >> arr[i];
    }
    run(n, k, arr);
    // test1();
    // cout << endl;
    // test2();
}