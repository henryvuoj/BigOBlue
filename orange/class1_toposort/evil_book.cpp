//
// Created by VHHV on 9/5/25.
//

#include <iostream>
#include <queue>
#include <set>

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

int bfs_find_furthest(vector<vector<int>> &graph, vector<int> affected, int start) {
    vector<bool> visited(graph.size(), false);
    queue<pair<int, int>> queue;
    pair<int, int> temp_node = start == -1 ? make_pair(affected[0], 0) : make_pair(start, 0);
    visited[temp_node.first] = true;
    queue.push(temp_node);
    pair<int, int> max_node = temp_node;
    while (!queue.empty()) {
        pair<int, int> node = queue.front(); queue.pop();
        for (int adj_node : graph[node.first]) {
            if (!visited[adj_node]) {
                pair<int, int> adj_node_pair = make_pair(adj_node, node.second + 1);
                queue.push(adj_node_pair);
                visited[adj_node] = true;
                if (adj_node_pair.second > max_node.second) {
                    max_node = adj_node_pair;
                }
            }
        }
    }
    return max_node.first;
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
    int first_furthest = bfs_find_furthest(graph, affected, -1);
    int second_furthest = bfs_find_furthest(graph, affected, first_furthest);
    vector<int> first_result = bfs(graph, first_furthest, d);
    vector<int> second_result = bfs(graph, second_furthest, d);
    set<int> result;
    for (int i : first_result) {
        for (int j : second_result) {
            if (i == j) {
                result.insert(i);
            }
        }
    }
    cout << result.size() << endl;
}

// #define INF 1000000
//
//
// vector<vector<int>> floyed_warshall(int size, vector<pair<int, int>> edges) {
//     vector<vector<int>> data = vector<vector<int>>(size, vector<int>(size, INF));
//     for (pair<int, int> edge : edges) {
//         data[edge.first][edge.second] = 1;
//         data[edge.second][edge.first] = 1;
//     }
//     for (int k = 0; k < size; k++) {
//         for (int i = 0; i < size; i++) {
//             if (data[i][k] == INF) continue;
//             for (int j = 0; j < size; j++) {
//                 if (data[k][j] != INF && data[i][k] + data[k][j] < data[i][j]) {
//                     data[i][j] = data[i][k] + data[k][j];
//                 }
//             }
//         }
//     }
//     return data;
// }
//
// /*
// 10 1 0
// 3
// 10 1
// 9 4
// 4 5
// 6 4
// 2 4
// 7 5
// 8 3
// 5 3
// 1 3
//  */
// int main() {
//     int n, m, d;
//     cin >> n >> m >> d;
//     vector<int> affected = vector<int>(m);
//     for (int i = 0; i < m; i++) {
//         int node;
//         cin >> node;
//         node--;
//         affected[i] = node;
//     }
//     vector<pair<int, int>> edges = vector<pair<int, int>>(n - 1);
//     for (int i = 0; i < n - 1; i++) {
//         int u, v;
//         cin >> u >> v;
//         u--; v--;
//         edges[i] = make_pair(u, v);
//     }
//     vector<vector<int>> data = floyed_warshall(n, edges);
//     int count = 0;
//     for (int i = 0; i < n; i++) {
//         bool check = true;
//         for (int affect : affected) {
//             if (data[i][affect] > d) {
//                 check = false;
//             }
//         }
//         if (check) count++;
//     }
//     cout << count;
//     return 0;
// }