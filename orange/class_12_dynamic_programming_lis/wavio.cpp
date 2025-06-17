//
// Created by VHHV on 17/6/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
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

vector<int> lcs_bs(vector<int> seq, vector<int>& lis) {
    vector<int> result;
    result.push_back(seq[0]);
    for (int i = 1; i < seq.size(); i++) {
        int pos = lower_bound(result.begin(), result.end(), seq[i]) - result.begin();
        if (pos == result.size()) {
            result.push_back(seq[i]);
        } else {
            result[pos] = seq[i];
        }
        lis[i] = pos + 1;
    }
    return result;
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
    vector<int> ascendingLength, descendingLength;
    ascendingLength.resize(seq.size());
    descendingLength.resize(seq.size());
    lcs_bs(seq, ascendingLength);
    reverse(seq.begin(), seq.end());
    lcs_bs(seq, descendingLength);
    int maxVal = 1;
    for (int i = 0; i < seq.size(); i++) {
        int minP = min(ascendingLength[i],descendingLength[seq.size() - 1 - i]);
        int L = (minP - 1) * 2 + 1;
        maxVal = max(maxVal, L);
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
    //
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