//
// Created by VHHV on 27/4/25.
//

#include <iostream>
#include <vector>
#include <queue>
#define MAX 10005
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
    vector<int> dist(MAX, -1);
    vector<int> path(MAX, -1);
    priority_queue<NodeCost, vector<NodeCost>, greater<NodeCost>> pq;
    pq.push({start, 0});
    dist[start] = 0;
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
    int sets;
    cin >> sets;
    for (int set_i = 0; set_i < sets; set_i++) {
        int n, m, k, s, t;
        cin >> n >> m >> k >> s >> t;
        vector<vector<NodeCost>> graph(MAX);
        vector<vector<NodeCost>> graph_reverse(MAX);
        for (int i = 0; i < m; i++) {
            int d, c, l;
            cin >> d >> c >> l;
            d--; c--;
            graph[d].push_back({c, l});
            graph_reverse[c].push_back({d, l});
        }
        s--; t--;
        DijkstraData data_from_s = dijkstra(s, graph);
        DijkstraData data_from_t = dijkstra(t, graph);
        DijkstraData data_to_s = dijkstra(s, graph_reverse);
        DijkstraData data_to_t = dijkstra(t, graph_reverse);
        int min = get_shortest_weight(t, data_from_s);
        // if (get_shortest_weight(s, data_from_t) == -1) {
        //     min = get_shortest_weight(t, data_from_s);
        // } else if (get_shortest_weight(t, data_from_s) == -1) {
        //     min = get_shortest_weight(s, data_from_t);
        // } else {
        //     min = std::min(get_shortest_weight(t, data_from_s), get_shortest_weight(s, data_from_t));
        // }
        for (int i = 0; i < k; i++) {
            int u, v, q;
            cin >> u >> v >> q;
            u--; v--;
            //Check if s -> u -> v -> t
            if (get_shortest_weight(u, data_from_s) != -1 && get_shortest_weight(v, data_to_t) != -1) {
                int new_weight = get_shortest_weight(u, data_from_s) + get_shortest_weight(v, data_to_t) + q;
                min = min != -1 ? std::min(min, new_weight) : new_weight;
            }
            //Check if s -> v > u -> t
            if (get_shortest_weight(v, data_from_s) != -1 && get_shortest_weight(u, data_to_t) != -1) {
                int new_weight = get_shortest_weight(v, data_from_s) + get_shortest_weight(u, data_to_t) + q;
                min = min != -1 ? std::min(min, new_weight) : new_weight;
            }
            // //Check if t -> u -> v -> s
            // if (get_shortest_weight(u, data_from_t) != -1 && get_shortest_weight(v, data_to_s) != -1) {
            //     min = std::min(min, get_shortest_weight(u, data_from_t) + get_shortest_weight(v, data_to_s) + q);
            // }
            // //Check if t -> v -> u -> s
            // if (get_shortest_weight(v, data_from_t) != -1 && get_shortest_weight(u, data_to_s) != -1) {
            //     min = std::min(min, get_shortest_weight(v, data_from_t) + get_shortest_weight(u, data_to_s) + q);
            // }

        }
        cout << min << endl;
    }

    return 0;
}