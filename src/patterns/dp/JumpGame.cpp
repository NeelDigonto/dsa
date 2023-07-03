#include <core/Common.hpp>
#include <iostream>

using namespace std;

class Solution {
public:
  bool canJump(const vector<int> &nums) {
    if (nums.size() == 1)
      return true;

    vector<bool> dp(nums.size(), false);
    dp[nums.size() - 1] = true;

    for (size_t i = nums.size() - 2; i != -1; --i) {
      const auto max_jump_index = min(i + nums[i], nums.size() - 1);

      for (size_t jump_index = i + 1; jump_index != max_jump_index + 1; ++jump_index)
        if (dp[jump_index])
          dp[i] = true;
    }

    return dp[0];
  }
};

int main() {
  cout << Solution{}.canJump({2, 3, 1, 1, 4}) << endl;
  cout << Solution{}.canJump({3, 2, 1, 0, 4}) << endl;
  cout << Solution{}.canJump({2, 0}) << endl; // false
}
