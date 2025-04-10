//
// Created by VuHai on 7/4/25.
//

#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

const int WEIGHT = 6;

void handle_query(int n, int m, vector<vector<int>> graph, int s) {
    vector<bool> visited(n+1, false);
    vector<int> path(n+1, -1);
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        vector<int> adj_nodes = graph[node];
        for (int adj_node : adj_nodes) {
            if (!visited[adj_node]) {
                visited[adj_node] = true;
                path[adj_node] = node;
                q.push(adj_node);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i != s) {
            int sum = 0;
            int cur_node = i;
            while (cur_node != s) {
                if (path[cur_node] != -1) {
                    cur_node = path[cur_node];
                    sum += WEIGHT;
                } else {
                    sum = -1;
                    break;
                }
            }
            cout << sum << " ";
        }
    }
    cout << endl;
}

void run_test(string input) {
    stringstream ss(input);
    int value;
    int q = -1;
    int n = -1;
    int m = -1;
    int count_m = -1;
    vector<vector<int>> graph;
    int current_edge_key = -1;
    int s = -1;
    while (ss >> value) {
        if (q == -1) {
            q = value;
            continue;
        }
        if (n == -1) {
            n = value;
            graph.resize(n+1);
            continue;
        }
        if (m == -1) {
            m = value;
            count_m = value;
            continue;
        }
        if (count_m > 0) {
            if (current_edge_key == -1) {
                current_edge_key = value;
                continue;
            }
            graph[current_edge_key].push_back(value);
            current_edge_key = -1;
            count_m--;
            continue;
        } else {
            s = value;

            //Run logic
            handle_query(n, m, graph, s);

            //Reset
            n = -1;
            m = -1;
            count_m = -1;
            graph.clear();
            current_edge_key = -1;
            s = -1;
            continue;
        }
    }
}

void test1() {
    string input = R"(
        2
        4 2
        1 2
        1 3
        1
        3 1
        2 3
        2
    )";
    run_test(input);
}

void test2() {
    string input = R"(
1
50 49
1 44
1 28
1 42
1 45
1 23
1 24
1 19
1 27
1 12
1 22
1 48
1 41
1 46
1 11
1 38
1 8
1 9
1 13
1 25
1 49
1 20
1 29
1 15
1 17
1 35
1 43
1 50
1 2
1 7
1 34
1 32
1 40
1 47
1 5
1 39
1 21
1 3
1 18
1 37
1 10
1 30
1 6
1 14
1 33
1 36
1 16
1 31
1 26
1 4
22
    )";
    run_test(input);
}


int main() {
    //test1()
    test2();

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
    //     }
    //     int s;
    //     cin >> s;
    //     handle_query(n, m, graph, s);
    // }
    return 0;
}