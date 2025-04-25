//
// Created by VHHV on 3/4/25.
//

#include <iostream>
#include <algorithm>

using namespace std;

//HEAP IMPLEMENTATION
void _swap(vector<int> &nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
void _heapify(vector<int> &nums, bool isMinHeap, int current){
    int nums_size = nums.size();
    int left_child = current * 2 + 1;
    int right_child = current * 2 + 2;
    if (isMinHeap) {
        if (left_child < nums_size && right_child < nums_size) {
            int swap_value = std::min(nums[left_child], nums[right_child]);
            if (swap_value < nums[current]) {
                if (swap_value == nums[left_child]) {
                    _swap(nums, left_child, current);
                    _heapify(nums, isMinHeap, left_child);
                } else {
                    _swap(nums, right_child, current);
                    _heapify(nums, isMinHeap, right_child);
                }
            }
        } else {
            if (left_child < nums_size && nums[left_child] < nums[current]) {
                _swap(nums, left_child, current);
                _heapify(nums, isMinHeap, left_child);
            } else if (right_child < nums_size && nums[right_child] < nums[current]) {
                _swap(nums, right_child, current);
                _heapify(nums, isMinHeap, right_child);
            }
        }
    } else {
        if (left_child < nums.size() && right_child < nums_size) {
            int swap_value = std::max(nums[left_child], nums[right_child]);
            if (swap_value > nums[current]) {
                if (swap_value == nums[left_child]) {
                    _swap(nums, left_child, current);
                    _heapify(nums, isMinHeap, left_child);
                } else {
                    _swap(nums, right_child, current);
                    _heapify(nums, isMinHeap, right_child);
                }
            }
        } else {
            if (left_child < nums_size && nums[left_child] > nums[current]) {
                _swap(nums, left_child, current);
                _heapify(nums, isMinHeap, left_child);
            } else if (right_child < nums_size && nums[right_child] > nums[current]) {
                _swap(nums, right_child, current);
                _heapify(nums, isMinHeap, right_child);
            }
        }
    }
}
void heapify(vector<int> &nums, bool isMinHeap) {
    //Start from parent which most close to child parent to the right
    //Start checking the parent with all child node, if child node > or < then replace the parent
    //Continue the heapify with lower child
    int current = nums.size()/2 - 1;
    while(current >= 0) {
      _heapify(nums, isMinHeap, current);
      current--;
    }
}
void insert_heap(vector<int> &nums, bool isMinHeap, int value) {
    nums.push_back(value);
    int current = nums.size() - 1;
    while (current > 0) {
        int parent_index = (current - 1) / 2;
        if (isMinHeap) {
            if (nums[parent_index] > nums[current]) {
                _swap(nums, parent_index, current);
            }
        } else {
            if (nums[parent_index] < nums[current]) {
                _swap(nums, parent_index, current);
            }
        }
        current = parent_index;
    }
}
void test_heapify() {
    vector<int> nums = {2,4,7,10,8,3,5,1,9,6};

    heapify(nums, true);
    insert_heap(nums, true, 0);
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    printf("Done Min Heapify\n");

    vector<int> nums2 = {2,4,7,10,8,3,5,1,9,6};
    heapify(nums2, false);
    for(int i = 0; i < nums2.size(); i++) {
        cout << nums2[i] << " ";
    }
    printf("Done Max Heapify\n");
}
//HEAP IMPLEMENTATION

int main() {
    test_heapify();
}