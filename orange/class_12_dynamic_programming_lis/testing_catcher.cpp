//
// Created by VuHai on 16/6/25.
//

#include <iostream>
#include <vector>

using namespace std;

int lis(vector<int> v) {
    vector<int> dp(v.size());
    dp[0] = 1;
    for (int i = 1; i < v.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[v.size() - 1];
}

int lds(vector<int> v) {
    vector<int> dp(v.size());
    dp[0] = 1;
    for (int i = 1; i < v.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] >= v[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    if (dp[v.size() - 1] == 0) {
        return -1;
    }
    return dp[v.size() - 1];
}

int binary_search(vector<int> v, vector<int> result, int target) {
    int left = 0;
    int right = result.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (v[result[mid]] < target) {
            left = mid + 1;
        } else {
            return result[mid];
        }
    }
    return -1;
}

int lds_binary_search(vector<int> v) {
    vector<int> result;
    result.push_back(0);
    for (int i = 1; i < v.size(); i++) {
        int pos = binary_search(v, result, v[i]);
        if (pos == -1) {
            result.push_back(i);
        } else {
            result[pos] = i;
        }
    }
    return result.size();
}

int main() {
    // vector<int> arr = {389, 207, 155, 300, 299, 170, 158, 65};
    // vector<int> arr = {23, 34, 21};
    // vector<int> arr = {23, 34, 56};
    // cout << lds(arr) << endl;
    vector<int> arr = {33, 33, 33, 34, 34, 34};
    cout << lds_binary_search(arr) << endl;

    // int count = 1;
    // while (true) {
    //     vector<int> v;
    //     int i;
    //     cin>>i;
    //     if (i == -1) {
    //         break;
    //     } else {
    //         v.push_back(i);
    //     }
    //     while (cin>>i) {
    //         if (i == -1) {
    //             break;
    //         } else {
    //             v.push_back(i);
    //         }
    //     }
    //     int res = lds_binary_search(vector<int>(v));
    //     res = res == 0 ? -1 : res;
    //     // int res = lds(vector<int>(v));
    //     cout<<"Test #"<<count<<":"<<endl;
    //     cout<<"  maximum possible interceptions: "<<res<<endl;
    //     cout<<endl;
    //     count++;
    // }

}