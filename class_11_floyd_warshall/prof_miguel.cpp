//
// Created by VHHV on 5/5/25.
//

#include <iostream>
#include <map>
#include <vector>
#define INF 10000000

using namespace std;

//ALGORITHM IMPLEMENTATIONS
void floyd_warshall(vector<vector<int>> &graph) {
    int n = graph.size();
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (graph[i][k] == INF) continue;
            for (int j = 0; j < n; ++j) {
                if (graph[k][j] != INF && (graph[i][j] > graph[i][k] + graph[k][j])) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}
//ALGORITHM IMPLEMENTATIONS
template <typename MapType, typename KeyType>
bool map_contains(const MapType& m, const KeyType& key) {
    return m.find(key) != m.end();
}

int main() {
    while (true) {
        int N;
        cin >> N;
        if (N == 0) return 0;
        map<char, int> mp;
        int idx = 0;
        vector<vector<int>> young_edges;
        vector<vector<int>> old_edges;
        for (int i = 0; i < N; ++i) {
            char age_type, direction_type, from, to;
            cin >> age_type >> direction_type >> from >> to;
            int weight;
            cin >> weight;
            if (!map_contains(mp, from)) {
                mp[from] = idx;
                idx++;
            }
            if (!map_contains(mp, to)) {
                mp[to] = idx;
                idx++;
            }
            if (age_type == 'Y') {
                young_edges.push_back({mp[from], mp[to], weight});
                if (direction_type == 'B') {
                    young_edges.push_back({mp[to], mp[from], weight});
                }
            } else {
                old_edges.push_back({mp[from], mp[to], weight});
                if (direction_type == 'B') {
                    old_edges.push_back({mp[to], mp[from], weight});
                }
            }
        }
        char from_string;
        cin >> from_string;
        char to_string;
        cin >> to_string;
        int from = map_contains(mp, from_string) ? mp[from_string] : -1;
        int to = map_contains(mp, to_string) ? mp[to_string] : -1;
        if (from == -1 || to == -1) {
            cout << "You will never meet." << endl;
            continue;
        }
        int size = mp.size();
        vector<vector<int>> young_graph = vector<vector<int>>(size, vector<int>(size, INF));
        vector<vector<int>> old_graph = vector<vector<int>>(size, vector<int>(size, INF));
        for (int i = 0; i < size; ++i) {
            young_graph[i][i] = 0;
            old_graph[i][i] = 0;
        }
        for (int i = 0; i < young_edges.size(); ++i) {
            int u = young_edges[i][0];
            int v = young_edges[i][1];
            int w = young_edges[i][2];
            if (young_graph[u][v] == INF) {
                young_graph[u][v] = w;
            } else {
                young_graph[u][v] = min(young_graph[u][v], w);
            }
        }
        for (int i = 0; i < old_edges.size(); ++i) {
            int u = old_edges[i][0];
            int v = old_edges[i][1];
            int w = old_edges[i][2];
            if (old_graph[u][v] == INF) {
                old_graph[u][v] = w;
            } else {
                old_graph[u][v] = min(old_graph[u][v], w);
            }
        }
        floyd_warshall(young_graph);
        floyd_warshall(old_graph);

        int min = INF;
        int target = -1;
        for (int k = 0; k < size; ++k) {
            if (young_graph[from][k] != INF && old_graph[to][k] != INF &&
                min > young_graph[from][k] + old_graph[to][k]) {
                min = young_graph[from][k] + old_graph[to][k];
                target = k;
            }
        }
        if (min == INF) {
            cout << "You will never meet." << endl;
        } else {
            char target_char = '?';
            for (const auto& [key, value] : mp) {
                if (value == target) {
                    target_char = key;
                    break;
                }
            }
            cout << min << " " << target_char << endl;
        }
    }
}
