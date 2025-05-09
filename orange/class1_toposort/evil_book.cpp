//
// Created by VHHV on 9/5/25.
//

#include <iostream>
#include <queue>

using namespace std;

vector<int> bfs(vector<vector<int>> &graph, int start, int depth) {
    vector<bool> visited(graph.size(), false);
    queue<pair<int, int>> queue;
    visited[start] = true;
    queue.push(make_pair(start, 0));
    vector<int> result;
    while (!queue.empty()) {
        pair<int, int> node = queue.front(); queue.pop();
        visited[node.first] = true;
        result.push_back(node.first);
        if (node.second < depth) {
            for (int adj_node : graph[node.first]) {
                if (!visited[adj_node] && node.second + 1 <= depth) {
                    queue.push(make_pair(adj_node, node.second + 1));
                }
            }
        }
    }
    return result;
}

/*
6 2 3
1 2
1 5
2 3
3 4
4 5
5 6
 */
int main() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> affected = vector<int>(m);
    for (int i = 0; i < m; i++) {
        int node;
        cin >> node;
        node--;
        affected[i] = node;
    }
    vector<vector<int>> graph = vector<vector<int>>(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<vector<int>> affected_traces = vector<vector<int>>(m, vector<int>());
    for (int i = 0; i < m; i++) {
        affected_traces[i] = bfs(graph, affected[i], d);
    }
    vector<int> counts = vector<int>(n, 0);
    for (vector<int> affected_trace : affected_traces) {
        for (int node : affected_trace) {
            counts[node]++;
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (counts[i] == m) {
           count++;
        }
    }
    cout << count;
}