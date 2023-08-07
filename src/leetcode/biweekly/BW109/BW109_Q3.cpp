#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {

  bool isParity(int a, int b) const noexcept { return !((a ^ b) & 1); }

public:
  long long maxScore(const vector<int> &nums, int x) {
    int64_t maxv = nums[0];

    for (size_t i = 2; i != nums.size(); ++i) {

      if (isParity(nums[i - 1], nums[i])) {
        maxv += nums[i];
      } else {
        maxv += max(maxv, maxv + nums[1] - x);
      }
    }

    // return max(with, without);
    return 0;
  }
};

int main() {
  cout << Solution{}.maxScore({2, 3, 6, 1, 9, 2}, 5) << endl;
  cout << Solution{}.maxScore({2, 4, 6, 8}, 3) << endl;
}
