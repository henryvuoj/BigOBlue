//
// Created by VHHV on 7/5/25.
//

#include <iostream>
#include <ostream>
#include <vector>
#include <queue>
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
        visited[node] = true;
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
//Has visited + queue to put all vertice_weight = 0 into
vector<int> toposort_kahn(vector<vector<int>> &graph) {
    vector<int> result;
    vector<bool> visited(graph.size(), false);
    vector<int> vertice_weight(graph.size());
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
        visited[node] = true;
        result.push_back(node);
        for (int v : graph[node]) {
            vertice_weight[v]--;
            if (vertice_weight[v] == 0) {
                queue.push(v);
            }
        }
    }
    for (int i = 0; i < graph.size(); ++i) {
        if (visited[i] == false) {
            return {};
        }
    }
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

int main() {
    // test_toposort_dfs();
    // test_toposort_dfs_with_cycle();
    test_toposort_kahn();
}