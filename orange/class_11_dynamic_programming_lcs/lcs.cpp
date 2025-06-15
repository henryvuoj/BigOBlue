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



int main() {
    vector<char> arr1 = {'A', 'T', 'C', 'J', 'D', 'Z', 'E', 'F', 'G', 'Y'};
    vector<char> arr2 = {'B', 'A', 'D', 'C', 'J', 'E', 'F', 'G', 'Y', 'T'};

    // vector<char> arr1 = {'E','D'};
    // vector<char> arr2 = {'E', 'C', 'D', 'G'};

    vector<char> start;
    vector<char> result_lcs_recursive_print_result = lcs_recursive_print_result(arr1, arr2, 0, 0, start);
    cout << lcs_recursive(arr1, arr2, 0, 0, 0) << std::endl;
}