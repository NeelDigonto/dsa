#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    k = k % nums.size();
    int prev, curr;
    for (int i = 0; i < k; i++) {
      prev = nums[nums.size() - 1];
      for (int j = 0; j < nums.size(); j++) {
        curr = nums[j];
        nums[j] = prev;
        prev = curr;
      }
    }
  }
};

int main() {
  {
    vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    Solution{}.rotate(nums, 3);

    cout << nums << endl;
  }
}
