//
// Created by VHHV on 13/3/25.
//
#include <iostream>
#include <vector>

using namespace std;

vector<int> get_freq(string s) {
    vector<int> freq = vector<int>(26, 0);
    for (int i = 0; i < s.length(); i++) {
        freq[s[i] - 'a']++;
    }
    return freq;
}

int check_suffix_automaton(string s, string t) {
    bool is_permutation = true;
    vector<int> freq_s = get_freq(s);
    vector<int> freq_t = get_freq(t);
    for (int i = 0; i < freq_s.size(); i++) {
        if (freq_s[i] < freq_t[i]) {
            return -1;
        } else if (freq_s[i] > freq_t[i]) {
            is_permutation = false;
        }
    }
    return is_permutation ? 1 : 0;
}

bool check_suffix_array(string s, string t) {
    int is = 0;
    int it = 0;
    while (it < t.length() && is < s.length()) {
        if (s[is] == t[it]) {
            it++;
        }
        is++;
    }
    if (it == t.length()) {
        return true;
    }
    return false;
}
// voczualgsktwmfivbztaovhjmdjqkpyuhlyaigrpzhfnemepaqkhijjaybjjzwsxgjmsdohysjbxqzkjgntinitk
//bvoczualgnsktwmfivbztaovhjmdjqkpyuhlyaigrpzhfnemepaqkhijjaybjjzwsxgjmsdohysjbxqzkjgntinitk

void run(string s, string t) {
    //Check suffix automaton
    int checked_suffix_automaton = check_suffix_automaton(s, t);
    if (checked_suffix_automaton == -1) {
        cout << "need tree";
        return;
    }
    if (checked_suffix_automaton == 1) {
        cout << "array";
        return;
    }
    if (check_suffix_array(s, t)) {
        cout << "automaton";
    } else {
        cout << "both";
    }
    return;
}

void test1() {
    string s = "automaton";
    string t = "tomat";
    run(s, t);
    cout << endl;
}

void test2() {
    string s = "array";
    string t = "arary";
    run(s, t);
    cout << endl;
}

void test3() {
    string s = "both";
    string t = "hot";
    run(s, t);
    cout << endl;
}

void test4() {
    string s = "need";
    string t = "tree";
    run(s, t);
    cout << endl;
}

void test5() {
    string s = "bvoczualgnsktwmfivbztaovhjmdjqkpyuhlyaigrpzhfnemepaqkhijjaybjjzwsxgjmsdohysjbxqzkjgntinitk";
    string t = "voczualgsktwmfivbztaovhjmdjqkpyuhlyaigrpzhfnemepaqkhijjaybjjzwsxgjmsdohysjbxqzkjgntinitk";
    run(s, t);
    cout << endl;
}


int main() {
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();

    string s;
    getline(cin, s);
    string t;
    getline(cin, t);
    run(s, t);
}