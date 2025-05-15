//
// Created by VHHV on 14/5/25.
//

#include <iostream>
#include <map>
#include <ostream>
#include <set>
#include <vector>
#define TARGET 8
using namespace std;

bool check_step(int n, vector<vector<int>> vec, vector<vector<int>> &map_check, pair<int, int> step) {
    if (step.first < 0 || step.second < 0 || step.first >= n || step.second >= n) {
        return false;
    }
    if (vec[step.first][step.second] == 1 && map_check[step.first][step.second] == 0) {
        return true;
    }
    return false;
}

vector<pair<int, int>> get_possible_next_steps(int n, vector<vector<int>> vec, vector<vector<int>> &map_check, pair<int, int> current) {
    vector<pair<int, int>> possible_next_steps;
    pair<int, int> step;
    step = make_pair(current.first + 1, current.second);
    if (check_step(n, vec, map_check, step)) {
        possible_next_steps.push_back(step);
    }
    step = make_pair(current.first - 1, current.second);
    if (check_step(n, vec, map_check, step)) {
        possible_next_steps.push_back(step);
    }
    step = make_pair(current.first, current.second + 1);
    if (check_step(n, vec, map_check, step)) {
        possible_next_steps.push_back(step);
    }
    step = make_pair(current.first, current.second - 1);
    if (check_step(n, vec, map_check, step)) {
        possible_next_steps.push_back(step);
    }
    return possible_next_steps;
}

void backtrack(int n, vector<vector<int>> vec, vector<vector<int>> &map_check, set<vector<vector<int>>> &result, pair<int, int> current, int count) {
    if (count >= TARGET) {
        result.insert(map_check);
    } else {
        vector<pair<int, int>> possible_next_steps = get_possible_next_steps(n, vec, map_check, current);
        for (pair<int, int> next_step : possible_next_steps) {
            map_check[next_step.first][next_step.second] = 1;
            backtrack(n, vec, map_check, result, next_step, count + 1);
            map_check[next_step.first][next_step.second] = 0;
        }
    }
}

int find_all_paths(int n, vector<vector<int>> vec) {
    set<vector<vector<int>>> result;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vec[i][j] == 1) {
                vector<vector<int>> map_check = vector<vector<int>>(n, vector<int>(n, 0));
                map_check[i][j] = 1;
                backtrack(
                    n,
                    vec,
                    map_check,
                    result,
                    make_pair(i, j),
                    1);
                map_check[i][j] = 0;
            }
        }
    }
    return result.size();
}

void test() {
    int T = 1;
    int N = 3;
    vector<vector<int>> vec1 = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };
    vector<vector<int>> vec2 = {
        {1,1,1},
        {1,1,1},
        {1,1,1}
    };
    // int res1 = find_all_paths(N, vec1);
    int res2 = find_all_paths(N, vec2);
    cout << endl;
}
/*
2
3
XXX
X.X
XXX
3
XXX
XXX
XXX

1
3
XXX
XXX
XXX
 */
int main() {
    // test();

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cin.ignore();
        vector<vector<int>> vec(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++) {
            string s;
            getline(cin, s);
            for (int j = 0; j < N; j++) {
                if (s[j] == 'X') {
                    vec[i][j] = 1;
                }
            }
        }
        cout << find_all_paths(N, vec) << endl;
    }
    return 0;
}