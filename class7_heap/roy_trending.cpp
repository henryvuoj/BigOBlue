//
// Created by VuHai on 7/4/25.
//

#include <iostream>
#include <queue>
#include <inttypes.h>  // Required for PRId64
using namespace std;

struct TopicData {
    int id;
    int64_t value;
    int64_t new_z_score;

    // Custom comparator for min-heap based on value
    bool operator<(const TopicData& other) const {
        if (value == other.value) {
            return id < other.id;
        }
        return value < other.value;
    }
};

int main() {
    priority_queue<TopicData, vector<TopicData>, less<TopicData>> pq;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        int current_value;
        cin >> current_value;
        int post;
        cin >> post;
        int like;
        cin >> like;
        int comment;
        cin >> comment;
        int share;
        cin >> share;
        int new_z_score = post*50+like*5+comment*10+share*20;
        pq.push({id, new_z_score - current_value, new_z_score});
    }
    for (int i = 0; i < 5; i++) {
        TopicData p = pq.top(); pq.pop();
        cout << p.id << " " << p.new_z_score << endl;
    }
}