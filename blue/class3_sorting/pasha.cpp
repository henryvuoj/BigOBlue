//
// Created by VHHV on 20/3/25.
//

#include <iostream>
#include <algorithm>

using namespace std;

void run(int n, int w, int arr[]) {
    sort(arr, arr + n);
    int amount = w;
    int girl = -1;
    int count_friend = 0;
    int left = 0;

    for (int i = 0; i < n * 2; i++) {
        if (girl == -1) {
            girl = arr[i];
        }

        int is_girl = i < n;
        if (amount > arr[i]) {
            if (is_girl < n) {
                //serving girl
                count_friend++;
                amount -= arr[i];
            } else {
                if (left != 0) {

                } else {
                    if (arr[i] > girl * 2) {
                        left = arr[i] - girl * 2;
                    }
                }
            }
        } else {
            break;
        }
    }
    cout << w - amount;
}

int main() {

}