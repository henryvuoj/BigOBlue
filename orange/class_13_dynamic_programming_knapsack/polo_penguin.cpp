//
// Created by VHHV on 24/6/25.
//

#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

int max_point(int N, vector<int> C, vector<int> P, vector<int> T) {
    vector<int> points = vector<int>(C.size(), 0);
    for (int i = 0; i < C.size(); i++) {
        points[i] = C[i] * P[i];
    }
    vector<vector<int>> dp (N+1, vector<int>(C.size()+1, 0));

    for (int i = 1; i <= C.size(); i++) {
        for (int t = 1; t <= N; t++) {
            //take c[i] or not take c[i]
            int not_take_value = dp[t][i-1];
            if (T[i-1] <= t) {
                int take_value = points[i-1] + dp[t-T[i-1]][i-1];
                dp[t][i] = max(not_take_value, take_value);
            } else {
                dp[t][i] = not_take_value;
            }
        }
    }
    return dp[N][C.size()];
}

/*
    0   1   2   3   4   5   6   7
0   0   0   0   0   0   0   0   0
1   0
2   0
3   0

 */

int main() {
    // int N = 7;
    // vector<int> C =  {1,2,3};
    // vector<int> P = {2,3,3};
    // vector<int> T = {3,5,3};
    // cout << max_point(N, C, P, T) << endl;

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int W, N;
        cin >> W >> N;
        vector<int> C(W), P(W), T(W);
        for (int j = 0; j < W; j++) {
            cin >> C[j];
            cin >> P[j];
            cin >> T[j];
        }
        cout << max_point(N, C, P, T) << endl;
    }
    return 0;
}