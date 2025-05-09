//
// Created by VuHai on 8/5/25.
//

#include <iostream>
#include <map>
#define MAX 1000000000
using namespace std;



int main() {
    int x0, y0, x1, y1, n;
    cin >> x0 >> y0 >> x1 >> y1 >> n;
    vector<vector<int>> graph = vector<vector<int>>(1000000000, vector<int>(1000000000, 0));
    map<pair<int, int>, vector<pair<int, int>>> map;
    for (int i = 0; i < n; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        for (int j = a; j <= b; j++) {
            graph[j][i] = 1;
            if (i + 1 <= MAX) {
                if (graph[j][i+1] == 1) {
                    if (map[pair<int, int>(i, j)].size() == 0) {}
                }
            }
            if (i > 0) {
                if (graph[j][i-1] == 1) {

                }
            }
        }
    }
    //Make graph

    for (int i = 0; i < n; i++) {
        // segments.
    }
}