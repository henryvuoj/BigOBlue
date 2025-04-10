//
// Created by VuHai on 7/4/25.
//

#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

const int WEIGHT = 6;

void handle_query(int m, vector<vector<int>> graph, int q, vector<int> girls) {
    // vector<bool> visited(n+1, false);
    // vector<int> path(n+1, -1);
    // queue<int> q;
    // q.push(s);
    // while (!q.empty()) {
    //     int node = q.front();
    //     q.pop();
    //     vector<int> adj_nodes = graph[node];
    //     for (int adj_node : adj_nodes) {
    //         if (!visited[adj_node]) {
    //             visited[adj_node] = true;
    //             path[adj_node] = node;
    //             q.push(adj_node);
    //         }
    //     }
    // }
    // for (int i = 1; i <= n; i++) {
    //     if (i != s) {
    //         int sum = 0;
    //         int cur_node = i;
    //         while (cur_node != s) {
    //             if (path[cur_node] != -1) {
    //                 cur_node = path[cur_node];
    //                 sum += WEIGHT;
    //             } else {
    //                 sum = -1;
    //                 break;
    //             }
    //         }
    //         cout << sum << " ";
    //     }
    // }
    // cout << endl;
}

void run_test(string input) {
    stringstream ss(input);
    int value;
    int m = -1;
    int count_m = -1;
    vector<vector<int>> graph;
    int current_edge_key = -1;
    int q = -1;
    vector<int> girls;
    while (ss >> value) {
        if (m == -1) {
            m = value;
            count_m = value-1;
            graph.resize(m+1);
            continue;
        }
        if (count_m > 0) {
            if (current_edge_key == -1) {
                current_edge_key = value;
                continue;
            }
            graph[current_edge_key].push_back(value);
            graph[value].push_back(current_edge_key);
            current_edge_key = -1;
            count_m--;
            continue;
        }
        if (q == -1) {
            q = value;
            continue;
        }
        girls.push_back(value);
    }
    handle_query(m, graph, q, girls);
}

void test1() {
    string input = R"(
        6
        1 2
        1 3
        1 4
        2 5
        2 6
        4
        5
        6
        3
        4
    )";
    run_test(input);
}

void test2() {

}


int main() {
    test1();
    // test2();

    // int q;
    // cin >> q;
    // for (int i = 0; i < q; i++) {
    //     int n;
    //     cin >> n;
    //     int m;
    //     cin >> m;
    //     vector<vector<int>> graph(n+1);
    //     cin.ignore();
    //     for (int j = 0; j < m; j++) {
    //         string line;
    //         getline(cin, line);
    //         stringstream ss(line);
    //         int u, v;
    //         ss >> u >> v;
    //         graph[u].push_back(v);
    //         graph[v].push_back(u);
    //     }
    //     int s;
    //     cin >> s;
    //     handle_query(n, m, graph, s);
    // }
    // return 0;
}