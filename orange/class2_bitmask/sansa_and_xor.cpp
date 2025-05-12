//
// Created by VuHai on 11/5/25.
//

#include <iostream>

using namespace std;

// void _permutation(vector<int> v, vector<vector<int>> &permutations) {
//     vector<int> permute;
//     for (int i = 0; i < v.size(); i++) {
//         permute.push_back(v[i]);
//     }
//     permutations.push_back(permute);
//     if (v.size() != 1) {
//         for (int i = 0; i < v.size(); i++) {
//             vector<int> child_v;
//             for (int j = 0; j < v.size(); j++) {
//                 if (j != i) {child_v.push_back(v[j]);}
//             }
//             _permutation(child_v, permutations);
//         }
//     }
// }
// void test_permutation(vector<int> v) {
//     vector<vector<int>> permutations;
//     _permutation(v, permutations);
//     cout << endl;
// }

int _permutation(vector<int> v, int result) {
    if (v.size() != 1) {
        for (int i = 0; i < v.size(); i++) {
            vector<int> child_v;
            for (int j = 0; j < v.size(); j++) {
                if (j != i) {child_v.push_back(v[j]);}
            }
            result ^= _permutation(child_v, result);
        }
    }
    for (int i = 0; i < v.size(); i++) {
        result ^= v[i];
    }
    return result;
}
void xor_sub_arr(vector<int> v) {
    int result = _permutation(v, 0);
    cout << result << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int j = 0; j < n; j++) {
            cin >> v[j];
        }
        xor_sub_arr(v);
    }
}