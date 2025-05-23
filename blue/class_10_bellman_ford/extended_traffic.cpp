//
// Created by VHHV on 27/4/25.
//

#include <iostream>
#include <ostream>
#include <vector>
#include <climits>

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
};
BellmanFordData bellmanFord(int start, vector<Edge> edges, int v) {
    //Loop through V-1 time all the Edges and update the dist and path
    vector<int> dist(MAX, INF);
    vector<int> path(MAX, -1);
    dist[start] = 0;
    for (int i = 0; i < v - 1; i++) {
        for (Edge edge : edges) {
            if (dist[edge.start] != INF && dist[edge.start] + edge.cost < dist[edge.end]) {
                dist[edge.end] = dist[edge.start] + edge.cost;
                path[edge.end] = edge.start;
            }
        }
    }
    //Check again for negative loop
    //For all negative edge, set -INF
    for (int i = 0; i < v - 1; i++) {
        for (Edge edge : edges) {
            if (dist[edge.start] != INF && dist[edge.start] + edge.cost < dist[edge.end]) {
                dist[edge.end] = -INF;
                path[edge.end] = -1;
            }
        }
    }
    BellmanFordData bellman_ford_data = {
        start,
        dist,
        path
    };
    return bellman_ford_data;
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
    BellmanFordData bellman_ford_data = bellmanFord(start, edges, v);
    cout << "DONE" << endl;
}
//ALGORITHM IMPLEMENTATION

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cout << "Case " << i + 1 << ":" << endl;
        int n;
        cin >> n;
        vector<int> busy = {};
        for (int j = 0; j < n; j++) {
            int nj;
            cin >> nj;
            busy.push_back(nj);
        }
        int m;
        cin >> m;
        vector<Edge> edges = {};
        for (int j = 0; j < m; j++) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            int diff = busy[y] - busy[x];
            edges.push_back({x, y, diff*diff*diff});
        }
        int q;
        cin >> q;
        BellmanFordData bellman_ford_data = bellmanFord(0, edges, n);
        for (int i = 0; i < q; i++) {
            int qi;
            cin >> qi;
            qi--;
            if (bellman_ford_data.dist[qi] < 3 || bellman_ford_data.dist[qi] == INF) {
                cout << "?" << endl;
            } else {
                cout << bellman_ford_data.dist[qi] << endl;
            }
        }
    }
}