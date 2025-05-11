//
// Created by VuHai on 11/5/25.
//

#include <iostream>
#include <vector>

using namespace std;

vector<string> multiplier(long long a, long long b) {
    vector<string> result;
    int count = 0;
    long long origin = a;
    while (b > 0) {
        if (b & 1) {
            result.push_back("("+to_string(origin)+"<<"+to_string(count)+")");
        }
        a <<= 1;
        b >>= 1;
        count++;
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long a, b;
        cin >> a >> b;
        vector<string> result = multiplier(a, b);
        for (int j = result.size() - 1; j >= 0; j--) {
            if (j != 0) {
                cout << result[j]+ " + ";
            } else {
                cout << result[j]<< endl;
            }
        }
    }
}