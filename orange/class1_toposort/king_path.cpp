//
// Created by VuHai on 8/5/25.
//

#include <iostream>
#include <map>
#include <queue>
#include <set>

#define MAX 1000000000
#define INF 1000000000
using namespace std;

void add_undirected_edge(map<pair<int, int>, set<pair<int, int>>> &graph_map, map<int, set<int>> &graph, pair<int, int> source, pair<int, int> target) {
    if (graph[target.first].find(target.second) != graph[target.first].end()) {
        graph_map[target].insert(source);
        graph_map[source].insert(target);
    }
}

void make_graph(map<pair<int, int>, set<pair<int, int>>> &graph_map, map<int, set<int>> &graph, int u, int v) {
    pair<int, int> source = make_pair(u, v);
    if (v + 1 < MAX) {
        add_undirected_edge(graph_map, graph, source, make_pair(u, v+1));
    }
    if (v > 0) {
        add_undirected_edge(graph_map, graph, source, make_pair(u, v-1));
    }
    if (u + 1 < MAX) {
        add_undirected_edge(graph_map, graph, source, make_pair(u+1, v));
        if (v + 1 < MAX && graph[u+1].find(v+1) != graph[u+1].end()) {
            add_undirected_edge(graph_map, graph, source, make_pair(u+1, v+1));
        }
        if (v > 0 && graph[u+1].find(v-1) != graph[u+1].end()) {
            add_undirected_edge(graph_map, graph, source, make_pair(u+1, v-1));
        }
    }
    if (u > 0) {
        add_undirected_edge(graph_map, graph, source, make_pair(u-1, v));
        if (v + 1 < MAX && graph[u-1].find(v+1) != graph[u-1].end()) {
            add_undirected_edge(graph_map, graph, source, make_pair(u-1, v+1));
        }
        if (v > 0 && graph[u-1].find(v-1) != graph[u-1].end()) {
            add_undirected_edge(graph_map, graph, source, make_pair(u-1, v-1));
        }
    }
}

int Dijkstra(map<pair<int, int>, set<pair<int, int>>> &graph_map, pair<int, int> source, pair<int, int> target) {
    map<pair<int, int>, int> dist_map;
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<>
    > pq;
    if (graph_map.find(source) == graph_map.end()) {
        return -1;
    }
    dist_map[source] = 0;
    pq.push(make_pair(0, source));
    while (!pq.empty()) {
        pair<int, pair<int, int>> node = pq.top(); pq.pop();
        set<pair<int, int>> adj_nodes = graph_map[node.second];
        for (pair<int, int> adj_node : adj_nodes) {
            if (dist_map.find(adj_node) == dist_map.end()) {
                dist_map[adj_node] = node.first + 1;
                pq.push(make_pair(dist_map[adj_node], adj_node));
            } else {
                if (node.first + 1 < dist_map[adj_node]) {
                    dist_map[adj_node] = node.first + 1;
                    pq.push(make_pair(dist_map[adj_node], adj_node));
                }
            }
        }
    }
    if (dist_map.find(target) == dist_map.end()) {
        return -1;
    } else {
        return dist_map[target];
    }
}

/*
5 7 6 11
3
5 3 8
6 7 11
5 2 5
*/
int main() {
    int x0, y0, x1, y1, n;
    cin >> x0 >> y0 >> x1 >> y1 >> n;

    map<int, set<int>> graph;
    map<pair<int, int>, set<pair<int, int>>> graph_map;

    for (int i = 0; i < n; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        for (int j = a; j <= b; j++) {
            graph[r].insert(j);
            make_graph(graph_map, graph, r, j);
        }
    }

    cout << Dijkstra(graph_map, make_pair(x0, y0), make_pair(x1, y1));
}
