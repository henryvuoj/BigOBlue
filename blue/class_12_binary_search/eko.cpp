// //
// // Created by VuHai on 10/5/25.
// //
//
// #include <iostream>
// #include <vector>
// using namespace std;
//
// long long calculate_amount_wood(vector<int> &trees, int height) {
//     long long amount = 0;
//     for (int tree : trees) {
//         if (tree > height) {
//             amount += (long long) (tree-height);
//         }
//     }
//     return amount;
// }
//
// /*
// 4 7
// 20 15 10 17
//
// 4 24
// 11 2 13 13 */
// int main() {
//     int N, M;
//     cin >> N >> M;
//     vector<int> trees(N);
//     int max = 0;
//     for (int i = 0; i < N; i++) {
//         cin >> trees[i];
//         if (trees[i] > max) {
//             max = trees[i];
//         }
//     }
//
//     int left = 0, right = max;
//     while (left <= right) {
//         int mid = left + ((right - left)/2);
//         long long amount = calculate_amount_wood(trees, mid);
//         if (amount > (long long) M) {
//             left = mid + 1;
//         } else if (amount < M) {
//             right = mid - 1;
//         } else {
//             cout << to_string(mid);
//             return 0;
//         }
//     }
//     cout << to_string(right);
//     return 0;
// }

#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 10000
#define MAX_A 1000
int n, k, A[MAX];
double sumEnergy, sumTransfer, _left, _right, mid;

int main() {
    scanf("%d %d", &n, &k);
    sumEnergy = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        sumEnergy += A[i];
    }

    _left = 0;
    _right = MAX_A;
    while (_right - _left > 1e-7) {
        mid =(_left + _right) / 2;
        sumTransfer = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] > mid)
                sumTransfer += A[i] - mid;
        }
        if (mid * n < sumEnergy - sumTransfer*k/100) {
            _left = mid;
        }
        else {
            _right = mid;
        }
    }
    printf("%.9f", _left);
    return 0;
}