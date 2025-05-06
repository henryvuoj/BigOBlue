//
// Created by VHHV on 6/5/25.
//

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define INF 1000000
using namespace std;

/*
2
0 5
4 0
1 2

 */
int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    vector<int> steps = vector<int>(n);
    vector<int> current_vertices = {};
    int sum = 0;
    for (int is = 0; is < n; is++) {
        int id;
        cin >> id;
        id--;
        steps[is] = id;
    }
    for (int is = n - 1; is >= 0; is--) {
        int k = steps[is];
        current_vertices.push_back(steps[is]);

        for (int i : current_vertices) {
            if (graph[i][k] == INF) continue;
            for (int j : current_vertices) {
                if (graph[k][j] != INF) {
                    graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
                }
                if (graph[i][j] != INF) {
                    sum += graph[i][j];
                }
            }
        }
        steps[is] = sum;
        sum = 0;
    }
    for (int i = 0; i < n; i++) {
        cout << steps[i] << " ";
    }
}
