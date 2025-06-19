//
// Created by VHHV on 19/6/25.
//

#include <iostream>
#include <ostream>
using namespace std;

#include <vector>



void pascal_triangle(int n, int row, vector<vector<int>> &triangle) {
    vector<int> row_triangle;
    row_triangle.push_back(1);
    for (int i = 1; i < row - 1; i++) {
        int i1 = triangle[row - 2][i];
        int i2 = triangle[row - 2][i - 1];
        row_triangle.push_back(i1 + i2);
    }
    row_triangle.push_back(1);
    triangle.push_back(row_triangle);
}

vector<vector<int>> generate2(int numRows) {
    vector<vector<int>> triangle;
    triangle.push_back(vector<int>(1, 1));
    for (int i = 2; i <= numRows; i++) {
        pascal_triangle(numRows, i, triangle);
    }
    return triangle;
}


void pascal_triangle_dp(pair<int, int> loc, vector<vector<int>> &triangle) {
    int row = loc.second;
    int current = loc.first;
    if (triangle[row].size() > current) {
        return;
    }
    int parent_row = row - 1;
    int left = loc.first - 1;
    int right = loc.first;
    int left_value = 0;
    int right_value = 0;
    if (left >= 0 && left <= parent_row) {
        if (left >= triangle[parent_row].size()) {
            pascal_triangle_dp(make_pair(left, parent_row), triangle);
        }
        left_value = triangle[parent_row][left];
    }
    if (right >= 0 && right <= parent_row) {
        if (right >= triangle[parent_row].size()) {
            pascal_triangle_dp(make_pair(right, parent_row), triangle);
        }
        right_value = triangle[parent_row][right];
    }
    triangle[row].push_back(left_value + right_value);
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle = vector<vector<int>>(numRows, vector<int>());
    triangle[0].push_back(1);
    for (int i = 0; i < numRows; i++) {
        pascal_triangle_dp(make_pair(i, numRows - 1), triangle);
    }
    return triangle;
}

int main() {
    int n = 5;
    vector<vector<int>> triangle = generate(n);
    cout << "done" << endl;
}