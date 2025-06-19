//
// Created by VHHV on 19/6/25.
//

#include <iostream>
#include <ostream>
using namespace std;

#include<vector>
#include<algorithm>

class CubeValue {
    public:
        int x;
        int y;
        int h;
};

vector<CubeValue> getSortedCubeValues(vector<vector<int>> cubes) {
    vector<CubeValue> sortedCubeValues;
    for (vector<int> cube : cubes) {
        sortedCubeValues.push_back({cube[0], cube[1], cube[2]});
        sortedCubeValues.push_back({cube[0], cube[2], cube[1]});
        sortedCubeValues.push_back({cube[1], cube[2], cube[0]});
        sortedCubeValues.push_back({cube[1], cube[0], cube[2]});
        sortedCubeValues.push_back({cube[2], cube[0], cube[1]});
        sortedCubeValues.push_back({cube[2], cube[1], cube[0]});
    }
    sort(sortedCubeValues.begin(), sortedCubeValues.end(), [](const CubeValue &a, const CubeValue &b) {
        return a.x == b.x ? a.y < b.y: a.x < b.x; ;
    });
    return sortedCubeValues;
}

int getMaxCubeStack(vector<vector<int>> cubes) {
    vector<CubeValue> sortedCubeValues = getSortedCubeValues(cubes);
    vector<int> dp(sortedCubeValues.size());
    for (int i = 0; i < sortedCubeValues.size(); i++) {
        dp[i] = sortedCubeValues[i].h;
    }
    for (int i = 1; i < dp.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (sortedCubeValues[i].x > sortedCubeValues[j].x && sortedCubeValues[i].y > sortedCubeValues[j].y) {
                dp[i] = max(dp[i], dp[j] + sortedCubeValues[i].h);
            }
        }
    }
    int maxVal = 0;
    for (int i = 0; i < dp.size(); i++) {
        maxVal = max(maxVal, dp[i]);
    }
    return maxVal;
}

int main() {
    // //21
    // vector<vector<int>> cubes = {
    //     {6,8,10},
    //     {5,5,5}
    // };
    //
    // //40
    // vector<vector<int>> cubes1 = {
    //     {10,20,30}
    // };
    //
    // //342
    // vector<vector<int>> cubes2 = {
    //     {31, 41, 59},
    //     {26, 53, 58},
    //     {97, 93, 23},
    //     {84, 62, 64},
    //     {33, 83, 27}
    // };
    //
    // //717
    // vector<vector<int>> cubes3 = {
    //     {67, 13, 41},
    //     {18, 18, 32},
    //     {59, 31, 92},
    //     {64, 69, 86},
    //     {8, 6, 78},
    //     {1, 75, 36},
    //     {23, 28, 29},
    //     {10, 58, 17},
    //     {59, 99, 98},
    //     {21, 59, 82},
    //     {22, 17, 47},
    //     {1, 42, 70},
    //     {43, 14, 57},
    //     {42, 50, 61},
    //     {1, 64, 29},
    //     {99, 69, 23},
    //     {92, 18, 30},
    //     {20, 63, 3},
    //     {91, 28, 31}
    // };

    // cout << getMaxCubeStack(cubes) << endl;
    // cout << getMaxCubeStack(cubes1) << endl;
    // cout << getMaxCubeStack(cubes2) << endl;
    // cout << getMaxCubeStack(cubes3) << endl;

    int count = 1;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) return 0;
        vector<vector<int>> cubes(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> cubes[i][j];
            }
        }
        cout << "Case " << count << ": maximum height = " << getMaxCubeStack(cubes) << endl;
        count++;
    }
}