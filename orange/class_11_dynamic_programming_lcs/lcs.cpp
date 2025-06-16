//
// Created by VuHai on 15/6/25.
//

#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

int lcs_recursive(vector<char> arr1, vector<char> arr2, int i1, int i2, int count) {
    if (i1 >= arr1.size() || i2 >= arr2.size()) {
        return count;
    } else {
        if (arr1[i1] == arr2[i2]) {
            return lcs_recursive(arr1, arr2, i1+1, i2+1, count + 1);
        } else {
            return max(
                lcs_recursive(arr1, arr2, i1+1, i2, count),
                lcs_recursive(arr1, arr2, i1, i2+1, count));
        }
    }
}

vector<char> lcs_recursive_print_result(vector<char> arr1, vector<char> arr2, int i1, int i2, vector<char> result) {
    if (i1 >= arr1.size() || i2 >= arr2.size()) {
        return result;
    } else {
        if (arr1[i1] == arr2[i2]) {
            vector<char> child_result = result;
            child_result.push_back(arr1[i1]);
            return lcs_recursive_print_result(arr1, arr2, i1+1, i2+1, child_result);
        } else {
            vector<char> left_child_result = lcs_recursive_print_result(arr1, arr2, i1+1, i2, result);
            vector<char> right_child_result = lcs_recursive_print_result(arr1, arr2, i1, i2+1, result);
            return left_child_result.size() > right_child_result.size() ? left_child_result : right_child_result;
        }
    }
}

vector<vector<int>> lcs_dynamic_tabulation(vector<char> arr1, vector<char> arr2) {
    vector<vector<int>> dp(arr1.size()+1, vector<int>(arr2.size()+1, 0));
    for (int i = 1; i <= arr1.size(); i++) {
        for (int j = 1; j <= arr2.size(); j++) {
            if (arr1[i - 1] == arr2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp;
}

vector<char> lcs_dynamic_tabulation_print_result(vector<char> arr1, vector<char> arr2) {
    vector<char> chars;
    vector<vector<int>> dp = lcs_dynamic_tabulation(arr1, arr2);
    int i = arr1.size(), j = arr2.size();
    while (i > 0 && j > 0) {
        if (arr1[i-1] == arr2[j-1]) {
            chars.push_back(arr1[i-1]);
            i--;
            j--;
        } else {
            int left = dp[i][j - 1];
            int right = dp[i - 1][j];
            if (i <= 1 || right <= left) {
                j--;
                continue;
            }
            if (j <= 1 || right >= left) {
                i--;
                continue;
            }
        }
    }
    return chars;
}

string diff(vector<char> arr1, vector<char> arr2) {
    vector<vector<int>> dp = lcs_dynamic_tabulation(arr1, arr2);
    int i = arr1.size(), j = arr2.size();
    string result = "";
    while (i > 0 && j > 0) {
        if (arr1[i-1] == arr2[j-1]) {
            result = std::string(" ") + arr1[i-1] + result;
            i--;
            j--;
        } else {
            int left = dp[i][j - 1];
            int right = dp[i - 1][j];
            if (i <= 1 || right <= left) {
                result = std::string(" -") + arr2[j-1] + result;
                j--;
                continue;
            }
            if (j <= 1 || right >= left) {
                result = std::string(" +") + arr1[i-1] + result;
                i--;
                continue;
            }
        }
    }
    return result;
}

int main() {
    vector<char> arr1 = {'A', 'T', 'C', 'J', 'D', 'Z', 'E', 'F', 'G', 'Y'};
    vector<char> arr2 = {'B', 'A', 'D', 'C', 'J', 'E', 'F', 'G', 'Y', 'T'};

    // vector<char> arr1 = {'E','D'};
    // vector<char> arr2 = {'E', 'C', 'D', 'G'};

    // vector<char> start;
    // vector<char> result_lcs_recursive_print_result = lcs_recursive_print_result(arr1, arr2, 0, 0, start);
    // cout << lcs_recursive(arr1, arr2, 0, 0, 0) << std::endl;


    // vector<char> result_lcs_tabulation_print_result = lcs_dynamic_tabulation_print_result(arr1, arr2);
    // cout << lcs_dynamic_tabulation(arr1, arr2)[arr1.size()][arr2.size()] << std::endl;

    cout << diff(arr1, arr2) << endl;
}