//
// Created by VHHV on 19/6/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Person {
    public:
        int idx;
        int s;
        int b;
};

vector<int> organize(vector<Person> people) {
    sort(people.begin(), people.end(), [](const Person&a, const Person&b) {
        return a.s == b.s ? a.b < b.b : a.s < b.s;
    });
    // A[i+1] find in all A[0] -> A[i] to find A with longest lineup
    // A A A+2 A+1 A+3 A
    // 1 1  2   2   3  1
    vector<int> dp(people.size(), 1);
    vector<int> path(people.size(), -1);
    for (int i = 1; i < people.size(); ++i) {
        for (int j = 0; j < i; j++) {
            if (people[i].s > people[j].s && people[i].b > people[j].b) {
                if (dp[i] <= dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    path[people[i].idx] = people[j].idx;
                }
            }
        }
    }
    int last = -1;
    int length = 0;
    for (int i = 0; i < people.size(); ++i) {
        if (dp[i] > length) {
            last = people[i].idx;
            length = dp[i];
        }
    }
    vector<int> ans;
    while (last != -1) {
        ans.push_back(last);
        last = path[last];
    }
    return ans;
}

int binary_search_person(vector<Person> people, Person target) {
    int l = 0, r = people.size() - 1;
    int pos = people.size();
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (people[mid].s < target.s && people[mid].b < target.b) {
            l = mid + 1;
            pos = mid;
        } else if (people[mid].s > target.s && people[mid].b > target.b){
            r = mid;
        } else {
            return -1;
        }
    }
    return pos;
}

vector<int> organize_optimized(vector<Person> people) {
    sort(people.begin(), people.end(), [](const Person&p1, const Person&p2) {
        return p1.b <= p2.b && p1.s <= p2.s;
    });
    vector<Person> ans;
    vector<int> res;
    ans.push_back(people[0]);
    res.push_back(people[0].idx);
    for (int i = 1; i < people.size(); ++i) {
        int pos = binary_search_person(ans, people[i]);
        if (pos == ans.size() - 1) {
            ans.push_back(people[i]);
            res.push_back(people[i].idx);
        } else if (pos == -1) {
            continue;
        } else {
            ans[pos] = people[i];
            res[pos] = people[i].idx;
        }
    }
    return res;
}

struct Person2 {
    int idx;
    int s;
    int b;

    bool operator<(const Person2 &other) const {
        return this->s == other.s ? this->b > other.b : this->s < other.s;
    }
};

int binary_search_person_b(vector<Person2> people, vector<int> ans, Person2 target) {
    int l = 0, r = ans.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (people[ans[mid]].b < target.b) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return r;
}

vector<int> organize_optimized2(vector<Person2> people) {
    sort(people.begin(), people.end());
    vector<int> ans;
    vector<int> path(people.size(), -1);
    ans.push_back(0);
    for (int i = 1; i < people.size(); i++) {
        int last_ans = ans[ans.size() - 1];
        if (people[i].b > people[last_ans].b) {
            if (ans.size() > 0) {
                path[i] = ans.back();
            }
            ans.push_back(i);
        } else {
            int pos = binary_search_person_b(people, ans, people[i]);
            if (pos > 0) {
                path[i] = ans[pos-1];
            }
            ans[pos] = i;
        }
    }
    vector<int> res;
    int path_pos = ans.back();
    res.push_back(people[path_pos].idx);
    while (path[path_pos] != -1) {
        path_pos = path[path_pos];
        res.push_back(people[path_pos].idx);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    //1,4,5
    // vector<Person2> people = {
    //     {0, 1,1},
    //     {1, 2,9},
    //     {2, 4,5},
    //     {3,  6,3},
    //     {4, 10,10},
    // };

    //1,4,5
     // vector<Person2> people = {
     //     {0, 1,1},
     //     {1, 1,2},
     //     {2, 2,1},
     //     {3,  2,2}
     // };
    //
    // vector<Person2> people = {
    //     {0, 1,1},
    //     {1, 2,5},
    //     {2, 3,7},
    //     {3,  4,2},
    //     {4,  5,3},
    //     {5,  6,4}
    // };

    // vector<int> invited_people = organize_optimized2(people);
    // cout << "DONE";

    int N;
    cin >> N;
    vector<Person2> people;
    for (int i = 0; i < N; ++i) {
        int s, b;
        cin >> s >> b;
        people.push_back({i, s, b});
    }
    vector<int> invited_people = organize_optimized2(people);
    cout << invited_people.size() << endl;
    for (int i = 0; i < invited_people.size(); ++i) {
        cout << invited_people[i] + 1 << " ";
    }
    return 0;
}
