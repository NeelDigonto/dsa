#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int findKthLargest(vector<int> &&nums, int k) {
    nth_element(begin(nums), next(nums.begin(), k - 1), end(nums), std::greater<int>{});
    return nums[k - 1];
  }
};

int main() {
  cout << Solution{}.findKthLargest({3, 2, 1, 5, 6, 4}, 2) << endl;          // 5
  cout << Solution{}.findKthLargest({3, 2, 3, 1, 2, 4, 5, 5, 6}, 4) << endl; // 4
}

/*
class Solution {
public:
  int findKthLargest(vector<int> &&nums, int k) {
    priority_queue max_heap(less<int>{}, std::move(nums));
    int cl{};

    while (k-- != 0)
      cl = max_heap.top(), max_heap.pop();

    return cl;
  }
};
*/