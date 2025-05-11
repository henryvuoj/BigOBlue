//
// Created by VuHai on 11/5/25.
//

#include <iostream>
#include <vector>
using namespace std;

/*
1
3 6
100001
010001
001001


 */

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, K;
        cin >> N >> K;
        long long res = 0;
        cin.ignore();
        vector<long long> friends(N, 0);
        for (int j = 0; j < N; j++) {
            string s;
            getline(cin, s);
            for (int k = 0; k < K; k++) {
                if (s[k] == '1') {
                    friends[j] |= (1 << (K - 1 - k));
                }
            }
            res |= friends[j];
        }
        for (int k = 0; k < K; k++) {
            long long res_kth_bit = (res >> k) & 1;
            if (res_kth_bit == 1) {
                long long check_kth_bit = res & (~(1<<k));
                bool check = true;
                for (int j = 0; j < N; j++) {
                    if ((check_kth_bit & friends[j]) == 0) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    res = check_kth_bit;
                }
            }
        }
        int count = 0;
        for (int k = 0; k < K; k++) {
            if ((res >> k) & 1) {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}