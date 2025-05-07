//
// Created by VuHai on 7/4/25.
//

#include <iostream>
#include <queue>
#include <inttypes.h>  // Required for PRId64
using namespace std;

int main() {
    priority_queue<int64_t, vector<int64_t>, greater<int64_t>> pq;
    while (true) {
        int64_t n;
        cin >> n;
        if (n == 0) return 0;
        for (int i = 0; i < n; i++) {
            int64_t x;
            cin >> x;
            pq.push(x);
        }
        int64_t sum = 0;
        for (int i = 0; i < n - 1; i++) {
            int64_t x1 = pq.top(); pq.pop();
            int64_t x2 = pq.top(); pq.pop();
            sum += x1 + x2;
            pq.push(x1 + x2);
        }
        printf("%" PRId64 "\n", sum);
        pq.pop();
    }
}