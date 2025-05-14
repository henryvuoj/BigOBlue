//
// Created by VHHV on 14/5/25.
//
#include <iostream>

using namespace std;

bool should_swap(string &s, int left, int right) {
    for (int i = left; i < right; i++) {
        if (s[i] == s[right]) {
            return false;
        }
    }
    return true;
}

void permutation_duplicate(string &s, int left, int right) {
    if (left >= right) {
        cout << s << endl;
        return;
    }
    for (int i = left; i < right; i++) {
        if (should_swap(s, left, i)) {
            swap(s[left], s[i]);
            permutation_duplicate(s, left+1, right);
            swap(s[left], s[i]);
        }

    }
}
/*
1

4 2
 */
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        string s;
        for (int j = n - 1; j >= 0; j--) {
            if (j < k) {
                s.push_back('1');
            } else {
                s.push_back('0');
            }
        }
        permutation_duplicate(s, 0, s.size());
    }
    return 0;
}