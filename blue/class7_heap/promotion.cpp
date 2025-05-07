//
// Created by VuHai on 7/4/25.
//

#include <iostream>
#include <queue>
using namespace std;

// HEAP IMPLEMENTATION
bool _compare(int64_t a, int64_t b, bool isMinHeap) {
    return isMinHeap ? a < b : a > b;
}

void _swap(vector<int64_t> &nums, size_t i, size_t j) {
    int64_t tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

void _heapify(vector<int64_t> &nums, bool isMinHeap, size_t current) {
    size_t nums_size = nums.size();
    size_t left_child = current * 2 + 1;
    size_t right_child = current * 2 + 2;
    int64_t swap_value;
    size_t swap_index;

    if (left_child < nums_size && right_child < nums_size) {
        if (_compare(nums[left_child], nums[right_child], isMinHeap)) {
            swap_value = nums[left_child];
            swap_index = left_child;
        } else {
            swap_value = nums[right_child];
            swap_index = right_child;
        }
    } else if (left_child < nums_size && _compare(nums[left_child], nums[current], isMinHeap)) {
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

void heapify(vector<int64_t> &nums, bool isMinHeap) {
    int current = nums.size() / 2 - 1;
    while (current >= 0) {
        _heapify(nums, isMinHeap, current);
        current--;
    }
}

void insert_heap(vector<int64_t> &nums, bool isMinHeap, int64_t value) {
    nums.push_back(value);
    size_t current = nums.size() - 1;
    while (current > 0) {
        size_t parent_index = (current - 1) / 2;
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

void remove_heap(vector<int64_t> &nums, bool isMinHeap) {
    if (!nums.empty()) {
        _swap(nums, 0, nums.size() - 1);
        nums.pop_back();
        _heapify(nums, isMinHeap, 0);
    }
}

void remove_heap_specific(vector<int64_t> &nums, bool isMinHeap, int64_t value) {
    for (size_t i = 0; i < nums.size(); i++) {
        if (nums[i] == value) {
            // Swap the element with the last element
            _swap(nums, i, nums.size() - 1);
            // Pop the last element (which is now the one we wanted to remove)
            nums.pop_back();
            // Re-heapify from the swapped position to restore the heap property
            _heapify(nums, isMinHeap, i);
            break;  // Remove only the first match
        }
    }
}

void test_heap() {
    vector<int64_t> nums = {2, 4, 7, 10, 8, 3, 5, 1, 9, 6};

    heapify(nums, true);
    remove_heap(nums, true);
    remove_heap(nums, true);
    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    printf("\nDone Min Heapify\n");

    vector<int64_t> nums2 = {2, 4, 7, 10, 8, 3, 5, 1, 9, 6};
    heapify(nums2, false);
    remove_heap_specific(nums2, false, 9);
    for (size_t i = 0; i < nums2.size(); i++) {
        cout << nums2[i] << " ";
    }
    printf("\nDone Max Heapify\n");
}

// HEAP IMPLEMENTATION

int main() {
    vector<int64_t> max_pq;
    vector<int64_t> min_pq;
    int64_t total = 0;
    int64_t days;
    cin >> days;
    for (int64_t day = 0; day < days; day++) {
        int64_t bills;
        cin >> bills;
        for (int64_t bill = 0; bill < bills; bill++) {
            int64_t bill_value;
            cin >> bill_value;
            insert_heap(max_pq, false, bill_value);
            insert_heap(min_pq, true, bill_value);
        }
        total += max_pq[0] - min_pq[0];
        remove_heap(max_pq, false);
        max_pq.pop_back();
        remove_heap(min_pq, true);
        min_pq.pop_back();
    }
    cout << total << endl;
}