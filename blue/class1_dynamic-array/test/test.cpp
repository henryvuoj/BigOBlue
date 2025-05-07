//
// Created by VuHai on 11/3/25.
//

#include "test.h"
#include <iostream>

int main() {
    std::vector<int> v;
    v.push_back(1);
    std::vector<int>::iterator it = v.begin();
    v.insert(it, 3);
    v.insert(it, 4);

    for (int num : v) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
