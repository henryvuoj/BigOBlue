//
// Created by VHHV on 27/4/25.
//

#include <iostream>
#include <vector>
#include <queue>

#define MAX 105
using namespace std;
const int INF = 1e9 + 7;

//ALGORITHM IMPLEMENTATION
vector<vector<pair<int, int>>> graph;
vector<int> dist(MAX, INF);

void Dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();

        int u = top.first;
        int w = top.second;

        for (pair<int, int> &neighbor : graph[u]) {
            if (w + neighbor.second < dist[neighbor.first]) {
                dist[neighbor.first] = w + neighbor.second;
                pq.push(make_pair(neighbor.first, dist[neighbor.first]));
            }
        }
    }
}
//ALGORITHM IMPLEMENTATION

int main() {
    int n;
    cin >> n;
    int e;
    cin >> e;
    int t;
    cin >> t;
    int m;
    cin >> m;
    graph = vector<vector<pair<int, int>>>(MAX, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int start;
        cin >> start;
        int end;
        cin >> end;
        int weight;
        cin >> weight;
        //reverse dijkstra
        graph[end].push_back(make_pair(start, weight));
    }
    Dijkstra(e);
    int count = 0;
    for(int i = 0; i < dist.size(); i++) {
      if(dist[i] <= t) {
        count++;
      }
    }
    cout << count;
    return 0;
}