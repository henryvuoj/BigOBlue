//
// Created by VuHai on 4/5/25.
//
#define INF 9999999
#define EMP -1
#include <iostream>
#include <vector>

using namespace std;

//Floyd-Warshall Implementation
struct FloydWarshallData {
    vector<vector<int>> dist;
    vector<vector<int>> path;
    bool is_valid;
};

FloydWarshallData floyd_warshall(vector<vector<int>> graph) {
    int n = graph.size();
    vector<vector<int>> path = vector<vector<int>>(n, vector<int>(n, EMP));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
           if (i != j && graph[i][j] != INF) {
               path[i][j] = i;
           }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (graph[i][k] == INF) continue;
            for (int j = 0; j < n; j++) {
                if (graph[k][j] != INF && (graph[i][k] + graph[k][j] < graph[i][j]) ) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
    return {
        graph,
        path,
        true
    };
}
//Floyd-Warshall Implementation

int main() {
    int T;
    cin >> T;
    cin.ignore(); // consume newline after T

    for (int t = 0; t < T; t++) {
        vector<vector<int>> graph;
        string line_string;

        // Read first line to detect matrix size
        getline(cin, line_string);
        int n = line_string.length();

        vector<int> row;
        for (char c : line_string) {
            row.push_back(c == 'Y' ? 1 : INF);
        }
        graph.push_back(row);

        // Read the remaining n-1 lines
        for (int i = 1; i < n; i++) {
            getline(cin, line_string);
            vector<int> row;
            for (char c : line_string) {
                row.push_back(c == 'Y' ? 1 : INF);
            }
            graph.push_back(row);
        }

        FloydWarshallData data = floyd_warshall(graph);
        if (data.is_valid) {
            int id_max = -1;
            int value_max = -1;
            for (int i = 0; i < data.dist.size(); i++) {
                int count = 0;
                for (int j = 0; j < data.dist.size(); j++) {
                    if (data.dist[i][j] == 2 && i != j) {
                        count++;
                    }
                }
                if (count > value_max) {
                    value_max = count;
                    id_max = i;
                }
            }
            cout << id_max << " " << value_max << endl;
        }
    }
}


