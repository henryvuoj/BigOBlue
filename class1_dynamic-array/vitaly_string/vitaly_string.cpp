//
// Created by VHHV on 12/3/25.
//
#include <iostream>
#include <vector>

using namespace std;

int run(string a, string b) {
    bool check = false;
    for (int i = 0; i < a.length(); i++) {
        if (b[i] - a[i] > 1) {
            a[i] = a[i] + 1;
            cout << a;
            return 0;
        } else if (b[i] - a[i] == 1) {
            if (check) {
                a[i] = a[i] + 1;
                cout << a;
                return 0;
            }
            check = true;
        } else {
            if (check) {
                if (a[i] != 'z') {
                    a[i] = a[i] + 1;
                    cout << a;
                    return 0;
                } else {
                    a[i-1] = a[i-1] + 1;
                    a[i] = 'a';
                    cout << a;
                    return 0;
                }

            }
        }
    }
    cout << "No such string";
}

int main() {
    // string a, b;
    // getline(cin, a);
    // getline(cin, b);
    // run(a, b);


    run("a","c");
    cout << endl;
    run("aaa","zzz");
    cout << endl;
    run("abcdefg","abcdefh");
    cout << endl;
    run("abaa","acaa");
    cout << endl;
    run(
        "xxxxxxxxxxxxxxxxxyyyyyyyyyyybbbbbbbccccccccddddddddddeeeeeeellllllllllzzzzzzzz",
        "xxxxxxxxxxxxxxxxxyyyyyyyyyyybbbbbbbccccccccddddddddddeeeeeeelllllllllmzzzzzzzz"
        );
    cout << endl;
    run(
        "abcdefxzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz",
        "abcdefyaaaaaaaaaaaaaaaaaaaaaaaaaaaaes"
        );
}