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
3 6
100001
010001
001001


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

3332


1
2 2
10
01



 */



int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, K;
        cin >> N >> K;
        cin.ignore();
        vector<long long> friends(N, 0);

        set<int> fav_idx;
        for (int j = 0; j < N; j++) {
            string s;
            getline(cin, s);
            for (int k = 0; k < K; k++) {
                if (s[k] == '1') {
                    int ik = K - 1 - k;
                    friends[j] |= (1 << ik);
                    fav_idx.insert(k);
                }
            }
        }
        int ans = K;
        for (int j = 0; j <= (1 << K) - 1; j++) {
            bool flag = true;
            for (long long frd : friends) {
                long long test = frd & j;
                if ((frd & j) == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag == true) {
                int count = 0;
                int j_count = j;
                while (j_count > 0) {
                    count += (j_count & 1);
                    j_count >>= 1;
                }
                ans = min(ans, count);
                break;
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