//
// Created by VHHV on 27/4/25.
//

#include <iostream>
#include <ostream>
#include <vector>
#define MAX 1005
#define INF 1000000000
using namespace std;

//ALGORITHM IMPLEMENTATION
struct Edge {
    int start;
    int end;
    int cost;
};
struct BellmanFordData {
    int start;
    vector<int> dist;
    vector<int> path;
    bool is_valid;
};
BellmanFordData bellmanFord(int start, vector<Edge> edges, int v) {
    //Loop through V-1 time all the Edges and update the dist and path
    vector<int> dist(MAX, INF);
    vector<int> path(MAX, -1);
    dist[start] = 0;
    for (int i = 0; i < v; i++) {
        for (Edge edge : edges) {
            if (dist[edge.start] != INF && dist[edge.start] + edge.cost < dist[edge.end]) {
                dist[edge.end] = dist[edge.start] + edge.cost;
                path[edge.end] = edge.start;
            }
        }
    }
    BellmanFordData bellmanFordData = {
        start,
        dist,
        path,
        true
    };
    //Check again for negative loop
    for (Edge edge : edges) {
        if (dist[edge.start] != -1 && (dist[edge.start] + edge.cost < dist[edge.end])) {
            bellmanFordData.is_valid = false;
            break;
        }
    }
    return bellmanFordData;
}
void test_bellman_ford() {
    int v = 6;
    vector<Edge> edges = {
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
    BellmanFordData bellmanFordData = bellmanFord(start, edges, v);
    cout << bellmanFordData.is_valid << endl;
}
//ALGORITHM IMPLEMENTATION

int main() {
    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<Edge> edges = {};
        for (int j = 0; j < m; j++) {
            int x, y, t;
            cin >> x >> y >> t;
            edges.push_back({x, y, t});
        }
        BellmanFordData bellmanFordData = bellmanFord(0, edges, n);
        if (bellmanFordData.is_valid) {
            cout << "not possible" << endl;
        } else {
            cout << "possible" << endl;
        }
    }
}