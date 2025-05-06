//
// Created by VHHV on 6/5/25.
//


#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define INF 1000000
using namespace std;

void FloyWarshall(vector<vector<pair<int,int>>> &graph) {
    int n = graph.size();
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (graph[i][k].first == INF) continue;
            for (int j = 0; j < n; ++j) {
                if (graph[k][j].first != INF) {
                    int max_feast_cost = (max(graph[i][k].second, graph[k][j].second));
                    if (max_feast_cost != -1 && graph[i][k].first + graph[k][j].first + max_feast_cost < graph[i][j].first + graph[i][j].second) {
                        graph[i][j].first = graph[i][k].first + graph[k][j].first;
                        graph[i][j].second = max_feast_cost;
                    }
                }
            }
        }
    }
}

int main() {
    int count_case = 1;
    while (true) {
        cout << "Case #" << count_case << endl;
        int C, R, Q;
        cin >> C >> R >> Q;
        if (C == 0 && R == 0 && Q == 0) return 0;
        //first is weight, second is feast_cost
        vector<vector<pair<int,int>>> graph = vector<vector<pair<int,int>>>(C, vector<pair<int, int>>(C, {INF, -1}));
        for (int i = 0; i < C; i++) {
            graph[i][i].first = 0;
            cin >> graph[i][i].second;
            for (int j = 0; j < C; j++) {
                if (i != j) {
                    int max_feast_cost = max(graph[i][i].second, graph[j][j].second);
                    graph[i][j].second = max_feast_cost;
                    graph[j][i].second = max_feast_cost;
                }

            }
        }
        for (int i = 0; i < R; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            graph[u][v].first = w;
            graph[v][u].first = w;
        }
        FloyWarshall(graph);
        for (int i = 0; i < Q; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            if (graph[u][v].first == INF) {
                cout << -1 << endl;
            } else {
                cout << graph[u][v].first + graph[u][v].second << endl;
            }
        }
        count_case++;
        cout << endl;
    }
}