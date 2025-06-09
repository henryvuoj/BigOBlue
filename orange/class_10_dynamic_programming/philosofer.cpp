//
// Created by VHHV on 9/6/25.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void find_max_node(vector<vector<int>> &chamber, pair<int, int> current, int w) {
    if (current.second == 0) {
        chamber[current.first][current.second] += std::max(
            chamber[current.first + 1][current.second],
            chamber[current.first + 1][current.second + 1]
        );
    } else if (current.second == w - 1) {
        chamber[current.first][current.second] += std::max(
            chamber[current.first + 1][current.second - 1],
            chamber[current.first + 1][current.second]
        );
    } else {
        chamber[current.first][current.second] += std::max({
            chamber[current.first + 1][current.second - 1],
            chamber[current.first + 1][current.second],
            chamber[current.first + 1][current.second + 1]
        });
    }
}

int find_max_route(vector<vector<int>> &chamber, int h, int w) {
    for (int hi = h - 2; hi >= 0; hi--) {
        for (int wi = 0; wi < w; wi++) {
            find_max_node(chamber, make_pair(hi, wi), w);
        }
    }
    int maxVal = -1;
    for (int wi = 0; wi < w; wi++) {
        maxVal = std::max(chamber[0][wi],maxVal);
    }
    return maxVal;
}

/*


//74
1
4 6
10 10 2 0 20 4
1 0 0 30 2 5
0 10 4 0 2 0
1 0 2 20 0 4


//66
1
4 5
12 44 8 1 2
1 4 5 2 3
2 5 8 7 6
2 5 8 9 6


//32
1
6 5
3 1 7 4 2
2 1 3 1 1
1 2 2 1 8
2 2 1 5 3
2 1 4 4 4
5 2 7 5 1


STILL NOT PASS ALL TEST CASE EVENTHOUGH IT SEMES WORKING TO ME
 */

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int h, w;
        cin >> h >> w;
        vector<vector<int>> chamber = vector<vector<int>>(h, vector<int>(w, 0));
        for (int hi = 0; hi < h; hi++) {
            for (int wi = 0; wi < w; wi++) {
                cin >> chamber[hi][wi];
            }
        }
        cout << find_max_route(chamber, h, w) << endl;
    }
}