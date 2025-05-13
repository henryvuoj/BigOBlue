//
// Created by VHHV on 13/5/25.
//

#include <vector>
#include <iostream>

using namespace std;

bool check_can_place(int n, vector<vector<int>> &chessboard, int row, int col) {
    //check vertical
    for (int i = row; i >= 0; i--) {
        if (chessboard[i][col] == 1) return false;
    }
    //check horizontal upleft
    for (int i = row, j = col; i>=0 && j>=0; i--, j--) {
        if (chessboard[i][j] == 1) return false;
    }
    //check horizontal upright
    for (int i = row, j = col; i>=0 && j<n; i--, j++) {
        if (chessboard[i][j] == 1) return false;
    }
    return true;
}

void print_placements(int n, vector<vector<int>> &chessboard) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (chessboard[i][j] == 1) {
                cout << "(" << i << " " << j << ") ";
            }
        }
        cout << endl;
    }
    cout  << "---------" << endl;
}

bool backtrack(int n, vector<vector<int>> &chessboard, int row) {
    if (row == n) {
        print_placements(n, chessboard);
        return true;
    }
    for (int i = 0; i < n; i++) {
        if (check_can_place(n, chessboard, row, i)) {
            chessboard[row][i] = 1;
            backtrack(n, chessboard, row+1);
            chessboard[row][i] = 0;
        }
    }
    return false;
}

int main() {
    int n = 8;
    vector<vector<int>> chessboard(n, vector<int>(n, 0));
    backtrack(n, chessboard, 0);
}