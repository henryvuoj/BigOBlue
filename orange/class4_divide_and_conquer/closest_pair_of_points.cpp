//
// Created by VuHai on 17/5/25.
//

#include <vector>
#include <algorithm>
#include <iostream>
#include <ostream>
#define INF 100000
using namespace std;

int dist(pair<int, int> p1, pair<int, int> p2) {
    return (p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second);
}

int closest_pair(vector<pair<int, int>> points, int left, int right) {
    int mid = left + (right - left) / 2;
    int min_left = INF;
    int min_right = INF;
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
    int min_dist = min(min_left, min_right);
    vector<pair<int, int>> min_points;
    for (int i = left; i < right; i++) {
        min_points.push_back(points[i]);
    }
    sort(min_points.begin(), min_points.end(), [](pair<int, int> &p1, pair<int, int> &p2) {
        return p1.second < p2.second;
    });
    for (int i = 0; i < min_points.size() - 1; i++) {
        int max_square = min_points[i].second + (int) sqrt(min_dist);
        for (int j = i + 1; j < min_points.size(); j++) {
            if (min_points[j].second > max_square) {
                break;
            }
            min_dist = min(min_dist, dist(min_points[i], min_points[j]));
        }
    }
    return min_dist;
}

int main() {
    vector<pair<int, int>> points = {
        {1, 2},
        {-4, -1},
        {-1 , 1},
        {6, 5},
        {2, -4},
        {-2, -3},
        {4, -1},
        {-5, 4},
        {3, 4}
    };
    sort(points.begin(), points.end());
    float result = sqrt(closest_pair(points, 0, points.size() - 1));
    cout << result << endl;
}
