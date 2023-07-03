#include <core/Common.hpp>
#include <iostream>

using namespace std;

class Solution {
public:
  int maxProduct(const vector<int> &nums) {

    int curr_max = 1, curr_min = 1, global_max = *begin(nums);

    for (auto num : nums) {
      auto temp_max = max(num, max(curr_max * num, curr_min * num));
      curr_min = min(num, min(curr_max * num, curr_min * num));
      curr_max = temp_max;

      global_max = max(global_max, curr_max);
    }

    return global_max;
  }
};

int main() {
  cout << Solution{}.maxProduct({2, 3, -2, 4}) << endl;
  cout << Solution{}.maxProduct({-2, 0, -1}) << endl;
}
