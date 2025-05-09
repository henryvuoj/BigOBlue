//
// Created by VHHV on 9/5/25.
//
#include <vector>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

enum STATE {
    UNVISITED,
    DOING,
    VISITED
};

bool _toposort_dfs(vector<vector<int>> &graph, vector<int> &visisted, vector<int> &result, int node) {
    if (visisted[node] == VISITED) {
        return true;
    }
    if (visisted[node] == DOING) {
        return false;
    }
    vector<int> adj_nodes = graph[node];
    if (adj_nodes.empty()) {
        result.push_back(node);
        visisted[node] = VISITED;
        return true;
    }
    for (int adj_node : adj_nodes) {
        if(!_toposort_dfs(graph, visisted, result, adj_node)) {
            return false;
        };
    }
    result.push_back(node);
    visisted[node] = VISITED;
    return true;
}

vector<int> toposort_dfs(vector<vector<int>> &graph) {
    vector<int> visisted = vector<int>(graph.size(), UNVISITED);
    vector<int> result;
    for (int i = 0; i < graph.size(); ++i) {
        if(!_toposort_dfs(graph, visisted, result, i)) {
            return vector<int>();
        }
    }
    return result;
}

vector<int> toposort_kahn(vector<vector<int>> &graph) {
    vector<int> vertice_weights = vector<int>(graph.size(), 0);
    for (int i = 0; i < graph.size(); ++i) {
        for (int j = 0; j < graph[i].size(); ++j) {
            vertice_weights[graph[i][j]]++;
        }
    }
    priority_queue<int, vector<int>, greater<>> pq;
    // priority_queue<int> pq;
    for (int i = 0; i < vertice_weights.size(); ++i) {
        if (vertice_weights[i] == 0) {
            pq.push(i);
        }
    }
    vector<int> result;
    while (!pq.empty()) {
        int node = pq.top(); pq.pop();
        result.push_back(node);
        for (int adj_node : graph[node]) {
            vertice_weights[adj_node]--;
            if (vertice_weights[adj_node] == 0) {
                pq.push(adj_node);
            }
        }
    }
    return result;
}

/*
3
vodka
wine
beer
2
wine vodka
beer wine

5
wine
beer
rum
apple-juice
cachaca
6
beer cachaca
apple-juice beer
apple-juice rum
beer rum
beer wine
wine cachaca

10
cachaca
rum
apple-juice
tequila
whiskey
wine
vodka
beer
martini
gin
11
beer whiskey
apple-juice gin
rum cachaca
vodka tequila
apple-juice martini
rum gin
wine whiskey
apple-juice beer
beer rum
wine vodka
beer tequila

Case #1: Dilbert should drink beverages in this order: beer wine vodka.

Case #2: Dilbert should drink beverages in this order: apple-juice beer wine rum cachaca.

Case #3: Dilbert should drink beverages in this order: apple-juice wine vodka beer rum cachaca tequila whiskey martini gin.
 */
int main() {
    int count = 0;
    int N;
    while (cin >> N) {
        count++;
        cin.ignore();
        map<string, int> forward_map;
        map<int, string> reverse_map;
        for (int i = 0; i < N; i++) {
            string s;
            getline(cin, s);
            forward_map[s] = i;
            reverse_map[i] = s;
        }

        int M;
        cin >> M;
        cin.ignore();

        vector<vector<int>> graph(N);
        for (int i = 0; i < M; i++) {
            string B1, B2;
            cin >> B1 >> B2;
            cin.ignore();
            graph[forward_map[B1]].push_back(forward_map[B2]);
        }

        vector<int> result = toposort_kahn(graph);
        if (result.size() == N) {
            cout << "Case #" << count << ": Dilbert should drink beverages in this order:";
            for (int i = 0; i < result.size(); i++) {
                cout << " " << reverse_map[result[i]];
            }
            cout << "." << endl << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }

        // optional: consume blank line between test cases
        string blank;
        getline(cin, blank);
    }
}
