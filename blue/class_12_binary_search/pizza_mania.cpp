//
// Created by VuHai on 10/5/25.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
1
5 -9
-7 3 -2 8 7
 */

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        unordered_map<int, int> map;
        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        for (int j = 0; j < n; j++) {
            cin >> v[j];
            map[v[j]]++;
        }
        int count = 0;
        // cout << "i " << i << endl;
        // for (auto it = map.begin(); it != map.end(); it++) {
        //     cout << " []" << it->first << " " << it->second << endl;
        // }
        // for (const auto& pair : map) {
        //     int current = pair.first;
        //     int target = m - pair.first;
        //     cout << " {}" << current << " " << target << endl;
        //     if (current == target) {
        //         if (map[current] >= 2) {
        //             count++;
        //             map[current] -= 2;
        //         }
        //     } else {
        //         if (map[current] >= 1 && map[target] >= 1) {
        //             cout << "BEFORE " << map[current] << ' ' << map[current] << endl;
        //             cout << current << ' ' << target << endl;
        //             count++;
        //             map[current] -= 1;
        //             map[target] -= 1;
        //             cout << "AFTER " << map[current] << ' ' << map[current] << endl;
        //         }
        //     }
        // }
        for (auto it = map.begin(); it != map.end(); it++) {
            int current = it->first;
            int target = m - current;

            if (current == target) {
                // If current == target, we need at least 2 occurrences of current
                if (it->second >= 2) {
                    count++;
                    it->second -= 2;  // Decrement the count for the current value
                }
            } else {
                // If current != target, make sure both current and target are present
                if (map.find(target) != map.end() && it->second > 0 && map[target] > 0) {
                    count++;
                    it->second--;  // Decrement the count for current
                    map[target]--;  // Decrement the count for target
                }
            }
        }
        cout << count << endl;
    }
}