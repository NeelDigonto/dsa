#include <core/Common.hpp>
#include <iostream>

using namespace std;

class Solution {
public:
  int lengthOfLIS(const vector<int> &nums) {
    vector<int> dp(nums.size(), 1);
    dp[0] = 1;

    for (size_t r = 1; r != nums.size(); ++r)
      for (size_t l = 0; l != r; ++l)
        if (nums[l] < nums[r])
          dp[r] = max(dp[r], dp[l] + 1);

    return *max_element(begin(dp), end(dp));
  }
};

int main() {
  cout << Solution{}.lengthOfLIS({10, 9, 2, 5, 3, 7, 101, 18}) << endl;
  cout << Solution{}.lengthOfLIS({0, 1, 0, 3, 2, 3}) << endl;
  cout << Solution{}.lengthOfLIS({7, 7, 7, 7, 7, 7, 7}) << endl;
  cout << Solution{}.lengthOfLIS({1, 3, 6, 7, 9, 4, 10, 5, 6}) << endl; // 6
}
