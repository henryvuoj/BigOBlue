//
// Created by VuHai on 17/5/25.
//

#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <ostream>
#define INF 100000000000
using namespace std;

long long dist(pair<long long, long long> p1, pair<long long, long long> p2) {
    return (p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second);
}

long long closest_pair(vector<pair<long long, long long>> points, long long left, long long right) {
    long long mid = left + (right - left) / 2;
    long long min_left = INF;
    long long min_right = INF;
    if (mid - left > 2) {
        min_left = min(min_left, closest_pair(points, left, mid));
    } else if (mid - left == 2) {
        min_left = dist(points[left], points[left + 1]);
    }
    if (right - mid > 3) {
        min_right = min(min_right, closest_pair(points, mid + 1, right));
    } else if (right - mid == 3){
        min_right = dist(points[mid + 1], points[mid + 2]);
    }
    long long min_dist = min(min_left, min_right);
    vector<pair<long long, long long>> min_points;
    for (long long i = left; i <= right; i++) {
        min_points.push_back(points[i]);
    }
    sort(min_points.begin(), min_points.end(), [](pair<long long, long long> &p1, pair<long long, long long> &p2) {
        return p1.second < p2.second;
    });
    for (long long i = 0; i < min_points.size() - 1; i++) {
        long long max_square = min_points[i].second + (long long) sqrt(min_dist);
        for (long long j = i + 1; j < min_points.size(); j++) {
            if (min_points[j].second > max_square) {
                break;
            }
            min_dist = min(min_dist, dist(min_points[i], min_points[j]));
        }
    }
    return min_dist;
}

int main() {
    while (true) {
        long long N;
        cin >> N;
        if (N == 0) return 0;
        vector<pair<long long, long long>> points = vector<pair<long long, long long>>(N);
        for (long long i = 0; i < N; i++) {
            long long x, y;
            cin >> x >> y;
            points[i].first = x;
            points[i].second = y;
        }
        double result = sqrt(closest_pair(points, 0, points.size() - 1));
        if (result >= 10000.0) {
            cout << "INFINITY" << endl;
        } else {
            cout << fixed << setprecision(4) << result << endl;
        }
    }
}
