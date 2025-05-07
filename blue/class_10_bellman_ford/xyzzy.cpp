//
// Created by VHHV on 2/5/25.
//

#include <iostream>
#include <ostream>
#include <vector>
#include <queue>
#define INF -10000000
#define MAX 101

using namespace std;

bool bfsReachable(int start, int end, vector<vector<int>> edges) {
    //Convert to adjacent list
    vector<vector<int>> graph(MAX+1, vector<int>());
    vector<bool> visited(MAX+1, false);
    for (vector<int> edge : edges) {
        graph[edge[0]].push_back(edge[1]);
    }
    /*
     * BFS
     * - Put all next adj list of current checking node to queue.
     * - Pop queue to take current checking node and repeat step 1
     */
    queue<int> queue;
    queue.push(start);
    visited[start] = true;
    while (queue.size() > 0) {
        int node = queue.front(); queue.pop();
        vector<int> adj_nodes = graph[node];
        for (int adj_node : adj_nodes) {
            if (adj_node == end) {
                return true;
            }
            if (!visited[adj_node]) {
                visited[adj_node] = true;
                queue.push(adj_node);
            }
        }
    }
    return false;
}

bool bellmanFord(int start, int end, vector<vector<int>> edges, int vertices) {
    vector<int> dist = vector<int>(MAX, INF);
    vector<int> path = vector<int>(MAX, -1);
    dist[start] = 100;
    for (int i = 0; i < vertices; i++) {
        for (vector<int> edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (dist[u] > 0 && dist[v] < dist[u] + w) {
                dist[v] = dist[u] + w;
                path[v] = u;
            }
        }
    }
    for (int i = 0; i < vertices; i++) {
        for (vector<int> edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (dist[u] > 0 && dist[v] < dist[u] + w && bfsReachable(v, end, edges)) {
                return true;
            }
        }
    }

    return dist[end] > 0;
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == -1) return 0;
        vector<vector<int>> edges = {};
        int start;
        int end;
        for (int i = 0; i < n; i++) {
            int energy, out_door;
            cin >> energy >> out_door;
            if (energy == 0 && out_door != 0) {
                start = i;
            } else if (energy == 0 && out_door == 0) {
                end = i;
            }
            for (int j = 0; j < out_door; j++) {
                int out;
                cin >> out;
                out--;
                edges.push_back({i, out, energy});
            }
        }
        if (bellmanFord(start, end, edges, n)) {
            cout << "winnable" << endl;
        } else {
            cout << "hopeless" << endl;
        }
    }
}