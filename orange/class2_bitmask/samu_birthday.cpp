//
// Created by VuHai on 11/5/25.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/*
1
3 9
000100001
000010001
100001001


1
3 3
110
011
101


1
3 3
110
011
101


1
4 4
1100
0001
1010
0100


1
5 4
1001
0101
1110
1110
0010



1
2 2
10
01



 */

long long convert_to_binary(string s) {
    long long result = 0;
    int size = s.length();
    for (int k = 0; k < size; k++) {
        if (s[k] == '1') {
            result |= (1 << k);
        }
    }
    return result;
}

int count_one_bits(long long binary) {
    int count = 0;
    while (binary > 0) {
        if (binary & 1) ++count;
        binary >>= 1;
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, K;
        cin >> N >> K;
        cin.ignore();
        vector<long long> friends(N, 0);
        for (int j = 0; j < N; j++) {
            string s;
            getline(cin, s);
            friends[j] = convert_to_binary(s);
        }
        int ans = N;
        long long max_j = 1 << K;
        for (long long j = 1; j < max_j; j++) {
            bool flag = true;
            for (long long frd : friends) {
                long long test = frd & j;
                if (test == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag == true) {
                ans = min(count_one_bits(j), ans);
            }
        }

        cout << ans << endl;

        // map<int, int> priority_idx;
        // for (int j = 0; j < N; j++) {
        //     string s;
        //     getline(cin, s);
        //     for (int k = 0; k < K; k++) {
        //         if (s[k] == '1') {
        //             int ik = K - 1 - k;
        //             friends[j] |= (1 << ik);
        //             priority_idx[ik]++;
        //         }
        //     }
        //     res |= friends[j];
        // }
        // vector<int> sorted_priority_idx;
        // for (pair<int, int> p : priority_idx) {
        //     sorted_priority_idx.push_back(p.first);
        // }
        // sort(sorted_priority_idx.begin(), sorted_priority_idx.end());
        // for (int k : sorted_priority_idx) {
        //     long long check_kth_bit = res & (~(1<<k));
        //     bool check = true;
        //     for (int j = 0; j < N; j++) {
        //         if ((check_kth_bit & friends[j]) == 0) {
        //             check = false;
        //             break;
        //         }
        //     }
        //     if (check) {
        //         res = check_kth_bit;
        //     }
        // }
        // int count = 0;
        // for (int k = 0; k < K; k++) {
        //     if ((res >> k) & 1) {
        //         count++;
        //     }
        // }
        // cout << count << endl;
    }
    return 0;
}