//
// Created by VHHV on 3/4/25.
//

#include <iostream>
#include <vector>
#include <inttypes.h>  // Required for PRId64

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

int test1() {
    vector<int64_t> nums = {};
    bool isMinHeap = true;

    insert_heap(nums, isMinHeap, 286789035);  // 1
    insert_heap(nums, isMinHeap, 255653921);  // 2
    insert_heap(nums, isMinHeap, 274310529);  // 3
    insert_heap(nums, isMinHeap, 494521015);  // 4

    // 5: print and remove min
    printf("%" PRId64 "\n", nums[0]);
    remove_heap(nums, isMinHeap);

    remove_heap_specific(nums, isMinHeap, 255653921);  // 6
    remove_heap_specific(nums, isMinHeap, 286789035);  // 7

    // 8: print and remove min
    printf("%" PRId64 "\n", nums[0]);
    remove_heap(nums, isMinHeap);

    insert_heap(nums, isMinHeap, 236295092);  // 9
    insert_heap(nums, isMinHeap, 254828111);  // 10
    remove_heap_specific(nums, isMinHeap, 254828111);  // 11
    insert_heap(nums, isMinHeap, 465995753);  // 12
    insert_heap(nums, isMinHeap, 85886315);   // 13
    insert_heap(nums, isMinHeap, 7959587);    // 14
    insert_heap(nums, isMinHeap, 20842598);   // 15
    remove_heap_specific(nums, isMinHeap, 7959587);    // 16

    // 17: print and remove min
    printf("%" PRId64 "\n", nums[0]);
    remove_heap(nums, isMinHeap);

    insert_heap(nums, isMinHeap, -51159108);  // 18

    // 19: print and remove min
    printf("%" PRId64 "\n", nums[0]);
    remove_heap(nums, isMinHeap);

    remove_heap_specific(nums, isMinHeap, -51159108);  // 20

    // 21: print and remove min
    printf("%" PRId64 "\n", nums[0]);
    remove_heap(nums, isMinHeap);

    insert_heap(nums, isMinHeap, 789534713);  // 22

    return 0;
}


int test2() {
    vector<int64_t> nums = {};
    bool isMinHeap = true;

    insert_heap(nums, isMinHeap, -890112362);
    if (!nums.empty()) {
        printf("%" PRId64 "\n", nums[0]);
        remove_heap(nums, isMinHeap);
    }

    remove_heap_specific(nums, isMinHeap, -890112362);

    insert_heap(nums, isMinHeap, 310432408);
    if (!nums.empty()) {
        printf("%" PRId64 "\n", nums[0]);
        remove_heap(nums, isMinHeap);
    }

    // These 2 operations are '3' with empty heap, so we skip them

    insert_heap(nums, isMinHeap, 151263095);
    if (!nums.empty()) {
        printf("%" PRId64 "\n", nums[0]);
        remove_heap(nums, isMinHeap);
    }

    insert_heap(nums, isMinHeap, 450851372);
    insert_heap(nums, isMinHeap, 189370081);
    remove_heap_specific(nums, isMinHeap, 151263095);

    if (!nums.empty()) {
        printf("%" PRId64 "\n", nums[0]);
        remove_heap(nums, isMinHeap);
    }

    remove_heap_specific(nums, isMinHeap, 450851372);
    insert_heap(nums, isMinHeap, 832507865);
    remove_heap_specific(nums, isMinHeap, 310432408);

    insert_heap(nums, isMinHeap, 760146198);
    remove_heap_specific(nums, isMinHeap, 760146198);

    if (!nums.empty()) {
        printf("%" PRId64 "\n", nums[0]);
        remove_heap(nums, isMinHeap);
    }

    insert_heap(nums, isMinHeap, 44966095);
    insert_heap(nums, isMinHeap, -181396956);
    if (!nums.empty()) {
        printf("%" PRId64 "\n", nums[0]);
        remove_heap(nums, isMinHeap);
    }

    remove_heap_specific(nums, isMinHeap, -181396956);
    insert_heap(nums, isMinHeap, 444313908);
    insert_heap(nums, isMinHeap, -60738113);
    insert_heap(nums, isMinHeap, -309681688);
    remove_heap_specific(nums, isMinHeap, -309681688);

    return 0;
}



int main() {
    // test_heap();
    // test2();

    vector<int64_t> nums;
    bool isMinHeap = true;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int query;
        cin >> query;
        if (query == 1) {
            int64_t value;
            cin >> value;
            insert_heap(nums, isMinHeap, value);
        } else if (query == 2) {
            int64_t value;
            cin >> value;
            remove_heap_specific(nums, isMinHeap, value);
        } else {
            if (!nums.empty()) {
                printf("%" PRId64 "\n", nums[0]);
            }
        }
    }

    return 0;
}
