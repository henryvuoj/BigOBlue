//
// Created by VHHV on 17/6/25.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> lcs(vector<int> seq) {
    vector<int> dp(seq.size(), 1);
    for (int i = 1; i < seq.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (seq[j] < seq[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return dp;
}

vector<int> lds(vector<int> seq) {
    vector<int> dp(seq.size(), 1);
    for (int i = 1; i < seq.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (seq[seq.size() - 1 - i] > seq[seq.size() - 1 - j]) {
                dp[seq.size() - 1 - i] = max(dp[seq.size() - 1 - i], dp[seq.size() - 1 - j] + 1);
            }
        }
    }
    return dp;
}

int solution(vector<int> seq) {
    //LCS
    vector<int> dp_lcs = lcs(seq);
    vector<int> dp_lds = lds(seq);
    int maxVal = -1;
    int count_lcs = 0;
    int count_lds = 0;
    for (int i = 1; i < seq.size() - 1; i++) {
        if (dp_lcs[i] == 1) count_lcs++;
        if (dp_lds[i] == 1) count_lds++;
        if (dp_lcs[i] + dp_lds[i] > maxVal) {
            int L = (min(dp_lcs[i],dp_lds[i]) - 1) * 2 + 1;
            maxVal = max(maxVal, L);
        }
    }
    if (count_lcs == seq.size() || count_lds == seq.size()) {
        return 1;
    }
    return maxVal;
}

int main() {
    //9
    // vector<int> seq = {1,2,3,2,1,2,3,4,3,2,1,5,4,1,2,3,2,2,1};

    //9
    // vector<int> seq = {1,2,3,4,5,4,3,2,1,10};

    //9
    // vector<int> seq = {1,2,3,2,1,2,3,4,3,2,1,5,4,1,2,3,2,2,1};

    //1
    // vector<int> seq = {1,2,3,4,5};

    //5
    // vector<int> seq = {78,28,73,88,77,40,31,78,91};

    // cout << solution(seq) << endl;

    int x;
    while (cin >> x) {
        vector<int> seq(x);
        for (int i = 0; i < x; i++) {
            cin >> seq[i];
        }
        cout << solution(seq) << endl;
    }
}