//
// Created by VHHV on 13/5/25.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combination(vector<int> &v, int n, int left, int k) {
    if (k == 0) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = left; i <= n; i++) {
        v.push_back(i);
        combination(v, n, i + 1, k - 1);
        v.pop_back();
    }
}

int main() {
    int n = 6;
    int k = 4;
    vector<int> v;
    combination(v, n, 1, k);
    return 0;

    // sort(v.begin(), v.end());
    // do {
    //     for (int i = 0; i < v.size(); i++) {
    //         cout << v[i] << " ";
    //     }
    //     cout << endl;
    // } while (next_permutation(v.begin(), v.end()));
}