//
// Created by VHHV on 13/5/25.
//

#include <iostream>
#include <vector>

using namespace std;

void combination(vector<int> &v, vector<int> &initial, int left, int k) {
    if (k == 0) {
        for (int i = 0; i < v.size(); i++) {
            cout << to_string(v[i]) << " ";
        }
        cout << endl;
        return;
    }
    for (int i = left; i < initial.size(); i++) {
        v.push_back(initial[i]);
        combination(v, initial, i + 1, k - 1);
        v.pop_back();
    }
}
/*
7 1 2 3 4 5 6 7
8 1 2 3 5 8 13 21 34
0
 */
int main() {
    while (true) {
        int k;
        cin >> k;
        if (k == 0) return 0;
        vector<int> initial(k);
        for (int i = 0; i < k; i++) {
            cin >> initial[i];
        }
        vector<int> v;
        combination(v, initial, 0, 6);
        cout << endl;
    }
}