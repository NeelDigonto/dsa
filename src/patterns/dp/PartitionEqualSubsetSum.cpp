#include <core/Common.hpp>
#include <iostream>

using namespace std;

class Solution {
private:
  bool canPartition(const vector<int> &nums, vector<vector<int8_t>> &dp, int idx, int subset_sum) {

    if (subset_sum == 0)
      return true;

    if (idx == 0)
      return false;

    if (dp[idx][subset_sum] != -1)
      return dp[idx][subset_sum];

    auto take = 0;
    if (subset_sum - nums[idx] >= 0)
      take = canPartition(nums, dp, idx - 1, subset_sum - nums[idx]);
    auto nottake = canPartition(nums, dp, idx - 1, subset_sum);

    return dp[idx][subset_sum] = take | nottake;
  }

public:
  bool canPartition(const vector<int> &nums) {
    const auto total_sum = reduce(begin(nums), end(nums));
    if (total_sum & 1)
      return false;

    const auto subset_sum = total_sum / 2;

    vector<vector<int8_t>> dp(nums.size(), vector<int8_t>(subset_sum + 1, -1));

    return canPartition(nums, dp, nums.size() - 1, subset_sum);
  }
};

int main() {
  cout << Solution{}.canPartition({1, 5, 11, 5}) << endl;
  cout << Solution{}.canPartition({1, 2, 3, 5}) << endl;
}
