//
// Created by VHHV on 27/4/25.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//ALGORITHM IMPLEMENTATION
struct NodeCost {
    int id;
    int cost;

    bool operator<(const NodeCost &other) const {
        return cost < other.cost;
    }
    bool operator>(const NodeCost &other) const {
        return cost > other.cost;
    }
};
struct DijkstraData {
    int start;
    vector<int> dist;
    vector<int> path;
};
//dist and path auto has value -1 at start
DijkstraData dijkstra(int start, vector<vector<NodeCost>> &graph) {
    vector<int> dist(graph.size(), -1);
    vector<int> path(graph.size(), -1);
    priority_queue<NodeCost, vector<NodeCost>, greater<NodeCost>> pq;
    if (graph.size() != 0) {
        pq.push({start, 0});
        dist[start] = 0;
    }
    while (!pq.empty()) {
        NodeCost node = pq.top(); pq.pop();
        for (NodeCost adj_node : graph[node.id]) {
            if (dist[adj_node.id] == -1 || dist[adj_node.id] > adj_node.cost + node.cost) {
                pq.push({adj_node.id, adj_node.cost + node.cost});
                path[adj_node.id] = node.id;
                dist[adj_node.id] = adj_node.cost + node.cost;
            }
        }
    }
    return {start, dist, path};
}
int get_shortest_weight(int dest, DijkstraData &data) {
    if (dest >= data.dist.size()) {
        return -1;
    }
    return data.dist[dest];
}
vector<int> get_shortest_path(int dest, DijkstraData &data) {
    vector<int> paths = {};
    if (dest >= data.dist.size()) {
        return paths;
    }
    int next = dest;
    int count = 0;
    while (count < 6) {
        count++;
        paths.push_back(next);
        next = data.path[next];
        if (next == -1) {
            break;
        }
    }
    return paths;
}
int test_dijkstra() {
    vector<vector<NodeCost>> graph = {
        { {1, 1} },                     // 0 -> (1,1)
        { {2, 5}, {3, 2}, {5, 7} },      // 1 -> (2,5), (3,2), (5,7)
        { {5, 1} },                     // 2 -> (5,1)
        { {0, 2}, {2, 1}, {4, 4} },      // 3 -> (0,2), (2,1), (4,4)
        { {3, 3} },                     // 4 -> (3,3)
        { {4, 1} }                      // 5 -> (4,1)
    };
    int dest = 3;
    DijkstraData data = dijkstra(0, graph);
    cout << get_shortest_weight(dest, data) << endl;
    vector<int> shortest_path = get_shortest_path(dest, data);
    for (int i = 0; i < shortest_path.size(); i++) {
        cout << shortest_path[i] << " ";
    }
}
//ALGORITHM IMPLEMENTATION

int main() {
    int n;
    cin >> n;
    vector<vector<NodeCost>> graph(n);
    for (int i = 0; i < n; i++) {
        int start;
        cin >> start;
        int end;
        cin >> end;
        int weight;
        cin >> weight;
        graph[start].push_back({end, weight});
    }
    int start;
    cin >> start;
    DijkstraData data = dijkstra(start, graph);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int dest;
        cin >> dest;
        int res = get_shortest_weight(dest, data);
        if (res == -1) {
            cout << "NO PATH" << endl;
        } else {
            cout << res << endl;
        }
    }
}