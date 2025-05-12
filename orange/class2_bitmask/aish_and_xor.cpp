//
// Created by VuHai on 12/5/25.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector <int> bits(N, 0);
    for (int i = 0; i < N; i++) {
        int bit;
        cin >> bit;
        if (i != 0) {
            bits[i] = bits[i-1] + bit;
        } else {
            bits[i] = bit;
        }
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        L--;R--;
        int sumLR;
        if (L == 0) {
            sumLR = bits[R];
        } else {
            sumLR = bits[R] - bits[L-1];
        }
        int zero_bits = R - L + 1 - sumLR;
        cout << to_string(sumLR % 2) << ' ' << to_string(zero_bits) << endl;
    }
}
