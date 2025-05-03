//
// Created by VHHV on 2/5/25.
//

#include <iostream>
#include <ostream>
#include <vector>

#define INF -1000
#define MAX 101

using namespace std;

struct BellmanFordData {
    vector<int> dist;
    vector<int> path;
};

BellmanFordData bellmanFord(int start, vector<vector<int>> edges, int vertices) {
    vector<int> dist = vector<int>(MAX, INF);
    vector<int> path = vector<int>(MAX, -1);
    dist[start] = 0;
    for (int i = 0; i < vertices; i++) {
        for (vector<int> edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (dist[v] == INF || dist[v] < dist[u] + w) {
                dist[v] = dist[u] + w;
                path[v] = u;
            }
        }
    }
    BellmanFordData bf = {
        dist,
        path
    };
    return bf;
}
void test_bellman_ford_without_negative_loop() {
    //No loop
    int v = 6;
    vector<vector<int>> edges = {
        {0, 1, 1},
        {1, 2, 5},
        {1, 3, -2},
        {1, 5, 7},
        {2, 5, -1},
        {3, 0, 2},
        {3, 2, -1},
        {3, 4, 4},
        {4, 3, 3},
        {5, 4, 1}
    };
    int start = 0;
    BellmanFordData bellman_ford_data = bellmanFord(start, edges, v);
    cout << "DONE" << endl;
}
void test_bellman_ford_with_negative_loop() {
    //No loop
    int v = 6;
    vector<vector<int>> edges = {
        {0, 1, 1},
        {1, 2, 5},
        {1, 3, -12},
        {1, 5, 7},
        {2, 5, -1},
        {3, 0, 2},
        {3, 2, -1},
        {3, 4, 4},
        {4, 3, 3},
        {5, 4, 1}
    };
    int start = 0;
    BellmanFordData bellman_ford_data = bellmanFord(start, edges, v);
    cout << "DONE" << endl;
}
void test_bellman_ford() {
    test_bellman_ford_with_negative_loop();
    test_bellman_ford_without_negative_loop();
}



int main() {
    while (true) {
        int n;
        cin >> n;
        vector<vector<int>> edges = {};
        int idx = 0;
        while (true) {
            int energy, out_door;
            cin >> energy >> out_door;
            for (int i = 0; i < out_door; i++) {
                int out;
                cin >> out;
                edges.push_back({idx, out, energy});
            }
            idx++;
        }
    }
}