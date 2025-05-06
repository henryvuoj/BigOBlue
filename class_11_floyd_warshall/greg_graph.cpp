/*
4
0 57148 51001 13357
71125 0 98369 67226
49388 90852 0 66291
39573 38165 97007 0
2 3 1 4

 */
//
// Created by VHHV on 6/5/25.
//

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define INF 100000000
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    vector<int> steps = vector<int>(n);
    vector<int> current_vertices = {};
    int sum = 0;
    for (int is = 0; is < n; is++) {
        int id;
        cin >> id;
        id--;
        steps[is] = id;
    }
    for (int is = n - 1; is >= 0; is--) {
        int k = steps[is];
        current_vertices.push_back(k);

        for (int i : current_vertices) {
            for (int j : current_vertices) {
                graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
        //     }
        // }
        for (int i : current_vertices) {
            for (int j : current_vertices) {
                sum += graph[i][j];
            }
        }
        steps[is] = sum;
        sum = 0;
    }
    for (int i = 0; i < n; i++) {
        cout << steps[i] << " ";
    }
}

// #include <iostream>
// #define MAX 505
// using namespace std;
//
// int n;
// int dist[MAX][MAX];
// long long res[MAX];
// int middleV[MAX];
//
// int main() {
//
//     int u, v;
//     cin >> n;
//
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n; j++) {
//             cin >> dist[i][j];
//         }
//     }
//
//     for (int i = 0; i < n; i++) {
//         cin >> middleV[i];
//     }
//
//     for (int index = n - 1; index >= 0; index--) {
//         int k = middleV[index];
//
//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= n; j++) {
//                 dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
//             }
//         }
//
//         for (int i = index; i < n; i++) {
//             u = middleV[i];
//             for (int j = index; j < n; j++) {
//                 v = middleV[j];
//                 res[index] += dist[u][v];
//             }
//         }
//     }
//
//     for (int i = 0; i < n; i++) {
//         cout << res[i] << " ";
//     }
//
//     return 0;
// }