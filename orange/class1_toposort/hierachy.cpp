//
// Created by VuHai on 7/5/25.
//

#include <iostream>
#include <ostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void _toposort_dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &result, int node) {
    if (!visited[node]) {
        vector<int> adj_nodes = graph[node];
        if (adj_nodes.empty()) {
            visited[node] = true;
            result.push_back(node);
            return;
        }
        visited[node] = true;
        for (int adj_node : adj_nodes) {
            _toposort_dfs(graph, visited, result, adj_node);
        }
        result.push_back(node);
    }
}

vector<int> toposort_dfs(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<bool> visited = vector<bool>(n, false);
    vector<int> result;
    for (int i = 0; i < n; i++) {
        _toposort_dfs(graph, visited, result, i);
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    int K;
    cin >> K;
    vector<vector<int>> graph = vector<vector<int>>(N, vector<int>());
    for (int i = 0; i < K; i++) {
        int W;
        cin >> W;
        for (int j = 0; j < W; j++) {
            int w;
            cin >> w;
            w--;
            graph[i].push_back(w);
        }
    }
    vector<int> result_toposort = toposort_dfs(graph);
    vector<int> result = vector<int>(N, 0);
    for (int i = 0; i < result_toposort.size() - 1; i++) {
        result[result_toposort[i]] = result_toposort[i+1] + 1;
    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}