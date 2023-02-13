#include <core/Common.hpp>
#include <iostream>

using namespace std;

class Solution {
public:
  int maxSubArray(const vector<int> &nums) {
    int max, globalMax;
    max = globalMax = *begin(nums);

    for (auto it = next(begin(nums)); it != end(nums); ++it) {

      max = std::max(max, 0) + *it;
      globalMax = std::max(globalMax, max);
    }

    return globalMax;
  }
};

int main() {
  cout << Solution{}.maxSubArray({-2, 1, -3, 4, -1, 2, 1, -5, 4}) << endl;
  cout << Solution{}.maxSubArray({1}) << endl;
  cout << Solution{}.maxSubArray({5, 4, -1, 7, 8}) << endl;
}
