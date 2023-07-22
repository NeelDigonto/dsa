#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    size_t zero_count = 0;

    for (size_t i = 0; i != nums.size(); ++i) {
      if (nums[i] == 0) {
        zero_count++;
        continue;
      }

      swap(nums[i], nums[i - zero_count]);
    }
  }
};

int main() {
  {
    vector<int> nums{0, 1, 0, 3, 12};
    Solution{}.moveZeroes(nums);
    cout << nums << endl;
  }
  {
    vector<int> nums{0};
    Solution{}.moveZeroes(nums);
    cout << nums << endl;
  }
}
