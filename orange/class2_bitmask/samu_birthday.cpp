//
// Created by VuHai on 11/5/25.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

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
        map<int, int> priority_idx;
        for (int j = 0; j < N; j++) {
            string s;
            getline(cin, s);
            for (int k = 0; k < K; k++) {
                if (s[k] == '1') {
                    int ik = K - 1 - k;
                    friends[j] |= (1 << ik);
                    priority_idx[ik]++;
                }
            }
            res |= friends[j];
        }
        vector<int> sorted_priority_idx;
        for (pair<int, int> p : priority_idx) {
            sorted_priority_idx.push_back(p.first);
        }
        sort(sorted_priority_idx.begin(), sorted_priority_idx.end());
        for (int k : sorted_priority_idx) {
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