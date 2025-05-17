//
// Created by VHHV on 15/5/25.
//

// #include <iostream>
// #include <set>
// #include <vector>
//
// using namespace std;
//
// const vector<char> VOWELS = {'A', 'E', 'I', 'O', 'U', 'Y'};

// vector<string> get_all_permutation(vector<vector<char>> combinations) {
//
// }
//
// void _combination(vector<char> vec, vector<vector<char>> &combinations, vector<char> &tmp, int left, int k) {
//     if (k == 0) {
//         combinations.push_back(tmp);
//         return;
//     }
//     for (int i = left; i < vec.size(); i++) {
//         tmp.push_back(vec[i]);
//         _combination(vec, combinations, tmp, i + 1, k - 1);
//         tmp.pop_back();
//     }
// }
//
// vector<vector<char>> get_combination(vector<char> vec, int k) {
//     vector<vector<char>> combinations;
//     vector<char> tmp;
//     _combination(vec, combinations, tmp, 0, k);
//     return combinations;
// }
//
// vector<vector<char>> get_all_combinations(set<char> boards) {
//     vector<char> vowels;
//     vector<char> others;
//     for (char c : boards) {
//         bool is_vowel = false;
//         for (char v : VOWELS) {
//             if (c == v) {
//                 is_vowel = true;
//                 break;
//             }
//         }
//         if (is_vowel) {
//             vowels.push_back(c);
//         } else {
//             others.push_back(c);
//         }
//     }
//     vector<vector<char>> vowel_combinations = get_combination(vowels, 2);
//     vector<vector<char>> others_combinations = get_combination(others, 2);
//     vector<vector<char>> combinations;
//     for (vector<char> v : vowel_combinations) {
//         for (vector<char> o : others_combinations) {
//             vector<char> com;
//             com.insert(com.end(), v.begin(), v.end());
//             com.insert(com.end(), o.begin(), o.end());
//             sort(com.begin(), com.end());
//             //Need to check the is path reachable
//             combinations.push_back(com);
//         }
//     }
//     return combinations;
// }
// /*
// D F F B    W A S U
// T U G I    B R E T
// O K J M    Y A P Q
// K M B E    L O Y R
//
//
// Z W A V    G S F U
// U N C O    A H F T
// Y T G I    G N A L
// H G P M    B O O B
//
//
//  */
// int main() {
//     while (true) {
//         set<char> board_1;
//         set<char> board_2;
//         for (int i = 0; i < 4; i++) {
//             string line;
//             getline(cin, line);
//             if (line == "#") return 0;
//             int count = 0;
//             for (char c : line) {
//                 if (c != ' ') {
//                     if (count < 4) {
//                         board_1.insert(c);
//                     } else {
//                         board_2.insert(c);
//                     }
//                     count++;
//                 }
//             }
//         }
//         vector<vector<char>> board_1_combinations = get_all_combinations(board_1);
//         vector<vector<char>> board_2_combinations = get_all_combinations(board_2);
//         vector<vector<char>> combinations;
//         for (vector<char> board_1_com : board_1_combinations) {
//             for (vector<char> board_2_com : board_2_combinations) {
//                 if (board_1_com == board_2_com) {
//                     combinations.push_back(board_1_com);
//                 }
//             }
//         }
//         vector<string> permutations = get_all_permutation(combinations);
//         sort(permutations.begin(), permutations.end());
//         for (string s : permutations) {
//             cout << s << endl;
//         }
//     }
// }


#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

const vector<char> VOWELS = {'A', 'E', 'I', 'O', 'U', 'Y'};

/*
D F F B    W A S U
T U G I    B R E T
O K J M    Y A P Q
K M B E    L O Y R


Z W A V    G S F U
U N C O    A H F T
Y T G I    G N A L
H G P M    B O O B

 */

bool is_vowel(char c) {
    for (char v : VOWELS) {
        if (c == v) return true;
    }
    return false;
}

vector<pair<int, int>> find_next_poses(vector<vector<char>> board, map<char, bool> check_duplicate, pair<int, int> pos, int count_vowels, int count_others) {
    vector<pair<int, int>> next_poses;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            pair<int, int> next_pos = make_pair(pos.first + i, pos.second + j);
            if (next_pos.first >= 0 && next_pos.first < board.size() &&
                next_pos.second >= 0 && next_pos.second< board.size()) {
                if (!check_duplicate[board[next_pos.first][next_pos.second]]) {
                    bool check_is_vowel = is_vowel(board[next_pos.first][next_pos.second]);
                    if (check_is_vowel && count_vowels < 2) next_poses.push_back(next_pos);
                    if (!check_is_vowel && count_others < 2) next_poses.push_back(next_pos);
                }
            }
        }
    }
    return next_poses;
}

void backtrack_combination(vector<vector<char>> board, set<vector<char>> &results, vector<pair<int, int>> &tmp, map<char, bool> &check_duplicate, int count_vowels, int count_others, pair<int, int> pos) {
    if (count_vowels == 2 && count_others == 2) {
        vector<char> tmp_char;
        for (pair<int, int> tmp_pos : tmp) {
            tmp_char.push_back(board[tmp_pos.first][tmp_pos.second]);
        }
        // In case it only need to connect, don't need to form a path from x -> y -> z -> t
        // sort(tmp_char.begin(), tmp_char.end());
        results.insert(tmp_char);
        return;
    }
    vector<pair<int, int>> next_poses = find_next_poses(board, check_duplicate, pos, count_vowels, count_others);
    for (pair<int, int> next_pos : next_poses) {
        tmp.push_back(next_pos);
        check_duplicate[board[next_pos.first][next_pos.second]] = true;

        bool check_is_vowel = is_vowel(board[next_pos.first][next_pos.second]);
        backtrack_combination(
                board,
                results,
                tmp,
                check_duplicate,
                count_vowels + (check_is_vowel ? 1 : 0),
                count_others + (!check_is_vowel ? 1 : 0),
                next_pos);

        tmp.pop_back();
        check_duplicate[board[next_pos.first][next_pos.second]] = false;
    }
}

set<vector<char>> find_all_words(vector<vector<char>> board) {
    set<vector<char>> results;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            pair<int, int> pos = make_pair(i, j);
            bool check_is_vowel = is_vowel(board[i][j]);
            vector<pair<int, int>> tmp;
            map<char, bool> check_duplicate;
            check_duplicate[board[i][j]] = true;
            tmp.push_back(pos);
            backtrack_combination(
                board,
                results,
                tmp ,
                check_duplicate,
                check_is_vowel ? 1 : 0,
                !check_is_vowel ? 1 : 0,
                make_pair(i, j));
        }
    }
    return results;
}

void backtrack_permutation() {

}

vector<string> find_all_word_permutations(vector<vector<char>> all_words) {
    for (vector<char> word_chars : all_words) {
        for (char word : word_chars) {
            backtrack_permutation();
        }
    }
}

int main() {
    while (true) {
        vector<vector<char>> board_1 = vector<vector<char>>(4, vector<char>(4));
        vector<vector<char>> board_2 = vector<vector<char>>(4, vector<char>(4));
        for (int i = 0; i < 4; i++) {
            string line;
            getline(cin, line);
            if (line == "#") return 0;
            int count = 0;
            for (char c : line) {
                if (c != ' ') {
                    if (count < 4) {
                        board_1[i][count] = c;
                    } else {
                        board_2[i][count - 4] = c;
                    }
                    count++;
                }
            }
        }
        set<vector<char>> board_1_words = find_all_words(board_1);
        set<vector<char>> board_2_words = find_all_words(board_2);
        vector<string> results;
        for (vector<char> words_1 : board_1_words) {
            for (vector<char> words_2 : board_2_words) {
                if (words_1[0] == words_2[0] &&
                    words_1[1] == words_2[1] &&
                    words_1[2] == words_2[2] &&
                    words_1[3] == words_2[3]) {
                    if (words_1[0] == 'A' &&
                    words_1[1] == 'B' &&
                    words_1[2] == 'B' &&
                    words_1[3] == 'A') {
                        cout << endl;
                    }
                    results.push_back({words_1[0], words_1[1], words_1[2], words_1[3]});
                }
            }
        }
        if (results.empty()) {
            cout << "There are no common words for this pair of boggle boards." << endl;
        } else {
            sort(results.begin(), results.end());
            for (string word : results) {
                cout << word << endl;
            }
        }

        cin.ignore();
    }
}

/*
A B B A    A B B A
E D D E    E D D E
E F F A    E F F A
A E F G    A E F G

 */