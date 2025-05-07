//
// Created by VHHV on 7/5/25.
//

#include <iostream>
#include <ostream>
#include <vector>
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
void _toposort_dfs_with_cycle(vector<vector<int>> &graph, vector<int> &visited, vector<int> &result, int node) {
    if (visited[node] != FALSE) {
        return;
    }
    visited[node] = DOING;
    vector<int> adj_nodes = graph[node];
    if (adj_nodes.empty()) {
        visited[node] = true;
        result.push_back(node);
        return;
    }
    for (int adj_node : adj_nodes) {
        _toposort_dfs_with_cycle(graph, visited, result, adj_node);
    }
    visited[node] = TRUE;
    result.push_back(node);
}
vector<int> toposort_dfs_with_cycle(vector<vector<int>> &graph) {
    vector<int> result;
    vector<int> visited(graph.size(), FALSE);
    for (int i = 0; i < graph.size(); ++i) {
        _toposort_dfs_with_cycle(graph, visited, result, i);
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

int main() {
    // test_toposort_dfs();
    test_toposort_dfs_with_cycle();
}