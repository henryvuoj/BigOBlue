//
// Created by VHHV on 13/5/25.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


void backtrack(string &s, int l, int r) {
    if (l == r) {
        cout << s << endl;
    }
    for (int i = l; i <= r; i++) {
        swap(s[l], s[i]);
        backtrack(s, l + 1, r);
        swap(s[l], s[i]);
    }
}

int main() {
    string s = "AABB";
    // backtrack(s, 0, s.length() - 1);
    sort(s.begin(), s.end());
    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
    return 0;
}