//
// Created by VHHV on 13/5/25.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool should_swap(string &s, int start, int end) {
    for (int i = start; i < end; i++) {
        if (s[i] == s[end]) {
            return false;
        }
    }
    return true;
}

void backtrack(string &s, int l, int r) {
    if (l >= r) {
        cout << s << endl;
        return;
    }
    for (int i = l; i < r; i++) {
        if (should_swap(s, l, i)) {
            swap(s[l], s[i]);
            backtrack(s, l + 1, r);
            swap(s[l], s[i]);
        }
    }
}

int main() {
    string s = "AABB";
    backtrack(s, 0, s.length());
}