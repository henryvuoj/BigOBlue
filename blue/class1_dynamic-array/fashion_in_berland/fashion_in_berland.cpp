//
// Created by VuHai on 11/3/25.
//

#include <iostream>
#include <vector>

using namespace std;

int run(int N, vector<int> buttons) {
    if (N==1) {
        if (buttons[0]==1) {
            cout << "YES" << endl;
            return 0;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }
    bool check = false;
    for (int i = 0; i < N; i++) {
        if (buttons[i] == 0) {
            if (check == true) {
                cout << "NO" << endl;
                return 0;
            }
            check = true;
        }
    }
    if (check == true) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

int main() {
    int N;
    cin >> N;  // Read the number of buttons

    vector<int> buttons(N);
    for (int i = 0; i < N; i++) {
        cin >> buttons[i];
    }

    // int N = 3;
    // std::vector<int> buttons = {1, 0, 0};

    // int N = 3;
    // std::vector<int> buttons = {1, 0, 1};

    return run(N, buttons);
}
