//
// Created by VHHV on 12/3/25.
//
#include <iostream>
#include <vector>

using namespace std;

int run(string s) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        int dif = 0;
        if (i == 0) {
            dif = s[i] - 'a';
        } else {
            dif = s[i] - s[i-1];
        }
        if (dif < 0) {
            dif = -dif;
        }
        if (dif > 13) {
            dif = 26 - dif;
        }
        count += dif;
    }
    return count;
}

int test1() {
    int res = run("ares");
    cout << res << endl;
}
int test2() {
    int res = run("zeus");
    cout << res << endl;
}
int test3() {
    int res = run("map");
    cout << res << endl;
}

int main() {
    string input;
    getline(cin, input);
    cout << run(input) << endl;
    // test1();
    // test2();
    // test3();
}