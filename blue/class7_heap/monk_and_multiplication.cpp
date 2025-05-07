//
// Created by VHHV on 3/4/25.
//

#include <iostream>
#include <vector>

using namespace std;

//HEAP IMPLEMENTATION
bool _compare(uint64_t a, uint64_t b, bool isMinHeap) {
    return isMinHeap ? a < b : a > b;
}
void _swap(vector<uint64_t> &nums, int i, int j) {
    uint64_t tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
void _heapify(vector<uint64_t> &nums, bool isMinHeap, int current){
    int nums_size = nums.size();
    int left_child = current * 2 + 1;
    int right_child = current * 2 + 2;
    int swap_value;
    int swap_index;
    if (left_child < nums_size && right_child < nums_size) {
        swap_value = _compare(nums[left_child], nums[right_child], isMinHeap) ? nums[left_child] : nums[right_child];
        swap_index = _compare(nums[left_child], nums[right_child], isMinHeap) ? left_child : right_child;
    } else if (left_child < nums_size && _compare(nums[left_child], nums[current], isMinHeap)){
        swap_value = nums[left_child];
        swap_index = left_child;
    } else if (right_child < nums_size && _compare(nums[right_child], nums[current], isMinHeap)) {
        swap_value = nums[right_child];
        swap_index = right_child;
    } else {
        return;
    }
    if (_compare(swap_value, nums[current], isMinHeap)) {
        _swap(nums, swap_index, current);
        _heapify(nums, isMinHeap, swap_index);
    }
}
void heapify(vector<uint64_t> &nums, bool isMinHeap) {
    //Start from parent which most close to child parent to the right
    //Start checking the parent with all child node, if child node > or < then replace the parent
    //Continue the heapify with lower child
    int current = nums.size()/2 - 1;
    while(current >= 0) {
      _heapify(nums, isMinHeap, current);
      current--;
    }
}
void insert_heap(vector<uint64_t> &nums, bool isMinHeap, int value) {
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
void remove_heap(vector<uint64_t> &nums, bool isMinHeap) {
    if (nums.size() > 0) {
        _swap(nums, 0, nums.size() - 1);
        nums.pop_back();
        _heapify(nums, isMinHeap, 0);
    }
}
void test_heap() {
    vector<uint64_t> nums = {2,4,7,10,8,3,5,1,9,6};

    heapify(nums, true);
    // insert_heap(nums, true, 0);
    remove_heap(nums, true);
    remove_heap(nums, true);
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    printf("Done Min Heapify\n");

    vector<uint64_t> nums2 = {2,4,7,10,8,3,5,1,9,6};
    heapify(nums2, false);
    for(int i = 0; i < nums2.size(); i++) {
        cout << nums2[i] << " ";
    }
    printf("Done Max Heapify\n");
}
//HEAP IMPLEMENTATION

void monk_and_multiplication(vector<uint64_t> nums) {
    bool isMinHeap = false;
    vector<uint64_t> heap = {};
    for (uint64_t i = 0; i < nums.size(); i++) {
        insert_heap(heap, isMinHeap, nums[i]);
        if (heap.size() > 2) {
            vector<uint64_t> temp;
            uint64_t total = 1;
            for (int j = 0; j < 3; j++) {
                total *= heap[0];
                temp.push_back(heap[0]);
                remove_heap(heap, isMinHeap);
            }
            printf("%llu\n", total);
            for (int j = 0; j < 3; j++) {
                insert_heap(heap, isMinHeap, temp[j]);
            }
        } else {
            printf("-1\n");
        }
    }
}

int test1() {
    int n = 5;
    vector<uint64_t> nums = {1,2,3,4,5};
    monk_and_multiplication(nums);
}

int test2() {
    int n = 5;
    vector<uint64_t> nums = {474709,855829,759911,977393,157547,455037,807388};
    monk_and_multiplication(nums);
}

int main() {
    test_heap();
    test1();
    test2();

    // uint64_t n;
    // cin >> n; // read how many numbers you want to input
    // vector<uint64_t> nums;
    //
    // for (int i = 0; i < n; i++) {
    //     uint64_t num;
    //     cin >> num;
    //     nums.push_back(num);
    // }
    //
    // monk_and_multiplication(nums);
}