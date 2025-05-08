//
// Created by VHHV on 8/5/25.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//KAHN
vector<int> toposort_kahn(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> vertice_weights = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            vertice_weights[graph[i][j]]++;
        }
    }
    queue<int> queue;
    for (int i = 0; i < n; i++) {
        if (vertice_weights[i] == 0) {
            queue.push(i);
        }
    }
    vector<int> result;
    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();
        result.push_back(node);
        for (int i = 0; i < graph[node].size(); i++) {
            int adj = graph[node][i];
            vertice_weights[adj]--;
            if (vertice_weights[adj] == 0) {
                queue.push(adj);
            }
        }
    }
    return result;
}
//KAHN

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<string> names(n);
    int min_length = 1000;
    for (int i = 0; i < n; i++) {
        getline(cin, names[i]);
        int length = names[i].length();
        min_length = min(min_length, length);
    }
    vector<vector<int>> graph = vector<vector<int>>(26, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        string first = names[i];
        string second = names[i+1];
        int length = min(first.length(), second.length());
        int check = false;
        for (int j = 0; j < length; j++) {
            if (first[j] != second[j]) {
                graph[first[j] - 'a'].push_back(second[j] - 'a');
                check = true;
                break;
            }
        }
        if (!check && first.length() > length) {
            cout << "Impossible";
            return 0;
        }
    }
    vector<int> result = toposort_kahn(graph);
    if (result.size() != 26) {
        cout << "Impossible";
    } else {
        for (int i = 0; i < result.size(); i++) {
            cout << static_cast<char>(result[i]+'a');
        }
    }
    return 0;
}