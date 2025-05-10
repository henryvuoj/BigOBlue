//
// Created by VuHai on 10/5/25.
//

#include <iomanip>
#include <iostream>
#include <queue>
using namespace std;

bool compare_float(double a, double b) {
    if (static_cast<long>(a) == static_cast<long>(b)) {
        return true;
    }
    return false;
}

double calculate_transfer(double larger, double smaller, int percentage) {
    double diff = (larger - smaller) / (1.0 + ((double) percentage / 100));
    return larger - diff;
    // larger - x = smaller + x * percentage
    // x (1 + percentage) = larger - smaller
    // x = (larger - smaller) / (1 + percentage)
}

int main() {
    // double padding = 1000000.0;
    int n, k;
    cin >> n >> k;
    priority_queue<double> max_heap;
    priority_queue<double, vector<double>, greater<>> min_heap;
    for (int i = 0; i < n; i++) {
        int energy;
        cin >> energy;
        // double energy_cast = ((double) energy) * padding;
        // max_heap.push(energy_cast);
        // min_heap.push(energy_cast);

        max_heap.push((double) energy);
        min_heap.push((double) energy);
    }
    double max_energy = max_heap.top();
    double min_energy = min_heap.top();
    while (!compare_float(max_energy,min_energy)) {
        max_heap.pop();
        min_heap.pop();
        max_heap.push(calculate_transfer(max_energy, min_energy, 100 - k));
        min_heap.push(calculate_transfer(max_energy, min_energy, 100 - k));
        max_energy = max_heap.top();
        min_energy = min_heap.top();
    }
    cout << fixed << setprecision(9) << max_energy << std::endl;
    // cout << to_string(max_energy);
    return 0;
}
/*
3 50
4 2 1

larger - percentage * (x

2 90
1 11

1 99
1000 1000
 */