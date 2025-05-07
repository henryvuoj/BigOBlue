//
// Created by VHHV on 7/5/25.
//

#include <iostream>
#include <ostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//TOPOSORT DFS
void _toposort_dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &result, int node) {
    if (visited[node]) {
        return;
    }
    vector<int> adj_nodes = graph[node];
    if (adj_nodes.empty()) {
        visited[node] = true;
        result.push_back(node);
        return;
    }
    for (int adj_node : adj_nodes) {
        _toposort_dfs(graph, visited, result, adj_node);
    }
    visited[node] = true;
    result.push_back(node);
}
vector<int> toposort_dfs(vector<vector<int>> &graph) {
    vector<int> result;
    vector<bool> visited(graph.size(), false);
    for (int i = 0; i < graph.size(); ++i) {
        _toposort_dfs(graph, visited, result, i);
    }
    return result;
}
void test_toposort_dfs() {
    vector<vector<int>> graph = {
        {1},
        {2,5,6},
        {},
        {5, 7},
        {1, 7},
        {},
        {},
        {6}
    };
    //Result is 2,5,6,1,0,7,3,4
    vector<int> result = toposort_dfs(graph);
    cout << "result" << endl;
}
//TOPOSORT DFS

//TOPOSORT DFS WITH CYCLE
enum State {
    FALSE,
    DOING,
    TRUE
};
bool _toposort_dfs_with_cycle(vector<vector<int>> &graph, vector<int> &visited, vector<int> &result, int node) {
    if (visited[node] == TRUE) {
        return true;
    }
    if (visited[node] == DOING) {
        return false;
    }
    visited[node] = DOING;
    vector<int> adj_nodes = graph[node];
    if (adj_nodes.empty()) {
        visited[node] = TRUE;
        result.push_back(node);
        return true;
    }
    for (int adj_node : adj_nodes) {
        if (!_toposort_dfs_with_cycle(graph, visited, result, adj_node)) {
            return false;
        }
    }
    visited[node] = TRUE;
    result.push_back(node);
    return true;
}
vector<int> toposort_dfs_with_cycle(vector<vector<int>> &graph) {
    vector<int> result;
    vector<int> visited(graph.size(), FALSE);
    for (int i = 0; i < graph.size(); ++i) {
        if(!_toposort_dfs_with_cycle(graph, visited, result, i)) {
            return {};
        }
    }
    return result;
}
void test_toposort_dfs_with_cycle() {
    // vector<vector<int>> graph = {
    //     {1},
    //     {2,5,6},
    //     {},
    //     {5, 7},
    //     {1, 7},
    //     {},
    //     {},
    //     {6}
    // };
    //Result is 2,5,6,1,0,7,3,4

    vector<vector<int>> graph = {
        {1},
        {2,5,6},
        {},
        {5, 7},
        {1, 7},
        {},
        {4},
        {6}
    };
    //Result is 2,5,7,4,6,1,0,3
    vector<int> result = toposort_dfs_with_cycle(graph);
    cout << "result" << endl;
}
//TOPOSORT DFS WITH CYCLE

//TOPOSORT KAHN
//Has queue to put all vertice_weight = 0 into
vector<int> toposort_kahn(vector<vector<int>> &graph) {
    vector<int> result;
    vector<int> vertice_weight(graph.size(), 0);
    queue<int> queue;
    for (int i = 0; i < graph.size(); ++i) {
        for (int j = 0; j < graph[i].size(); ++j) {
            vertice_weight[graph[i][j]]++;
        }
    }
    for (int i = 0; i < graph.size(); ++i) {
        if (vertice_weight[i] == 0) {
            queue.push(i);
        }
    }
    while (!queue.empty()) {
        int node = queue.front(); queue.pop();
        result.push_back(node);
        for (int v : graph[node]) {
            vertice_weight[v]--;
            if (vertice_weight[v] == 0) {
                queue.push(v);
            }
        }
    }
    reverse(result.begin(), result.end());
    return result;
}
void test_toposort_kahn() {
    vector<vector<int>> graph = {
        {1},
        {2,5,6},
        {},
        {5, 7},
        {1, 7},
        {},
        {},
        {6}
    };
    //Result is 2,5,6,1,0,7,3,4
    vector<int> result = toposort_kahn(graph);
    cout << "result" << endl;
}
//TOPOSORT KAHN

//TOPOSORT KAHN
//Has queue to put all vertice_weight = 0 into
vector<int> toposort_kahn_pq(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> result;
    vector<int> vertice_weight(n, 0);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < graph[i].size(); ++j) {
            vertice_weight[graph[i][j]]++;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (vertice_weight[i] == 0) {
            pq.push(i);
        }
    }
    while (!pq.empty()) {
        int node = pq.top(); pq.pop();
        result.push_back(node);
        for (int v : graph[node]) {
            vertice_weight[v]--;
            if (vertice_weight[v] == 0) {
                pq.push(v);
            }
        }
    }
    return result;
}
void test_toposort_kahn_pq() {
    vector<vector<int>> graph = {
        {1},
        {2,5,6},
        {},
        {5, 7},
        {1, 7},
        {},
        {},
        {6}
    };
    //Result is 2,5,6,1,0,7,3,4
    vector<int> result = toposort_kahn_pq(graph);
    cout << "result" << endl;
}
//TOPOSORT KAHN

/* Loop 7,9,6,12
14 20
7 13
4 5
8 2
10 13
7 9
5 11
5 2
4 9
14 13
8 6
6 12
11 2
10 4
12 7
11 3
12 2
9 6
11 12
12 3
11 13
 */

int main() {
    // test_toposort_dfs();
    // test_toposort_dfs_with_cycle();
    // test_toposort_kahn();
    // test_toposort_kahn_pq();

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph = vector<vector<int>>(n, vector<int>());
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
    }
    // vector<int> result = toposort_dfs_with_cycle(graph);
    // vector<int> result = toposort_kahn(graph);
    vector<int> result = toposort_kahn_pq(graph);
    if (result.size() != n) {
        cout << "Sandro fails.";
    } else {
        for (int res : result) {
            cout << res + 1 << " ";
        }
    }
}