#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
private:
  void moveK(vector<int> &nums, int k) {
    size_t k_count = 0;

    for (size_t i = 0; i != nums.size(); ++i) {
      if (nums[i] == k) {
        k_count++;
        continue;
      }

      swap(nums[i], nums[i - k_count]);
    }
  }

public:
  void sortColors(vector<int> &nums) {
    moveK(nums, 1);
    moveK(nums, 2);
  }
};

int main() {
  {
    vector<int> nums{2, 0, 2, 1, 1, 0};
    Solution{}.sortColors(nums);
    cout << nums << endl;
  }
  {
    vector<int> nums{2, 0, 1};
    Solution{}.sortColors(nums);
    cout << nums << endl;
  }
}
