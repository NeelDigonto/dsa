#include <core/Common.hpp>
#include <iostream>

using namespace std;

class Solution {
public:
  int rob(const vector<int> &nums) {
    if (nums.size() == 1)
      return *begin(nums);

    int prev_prev = nums[0], prev = max(nums[0], nums[1]);

    for (int i = 2; i != nums.size(); ++i) {
      auto take = prev_prev + nums[i];
      auto nottake = prev;
      auto current = max(take, nottake);

      prev_prev = prev;
      prev = current;
    }

    return prev;
  }
};

int main() {
  cout << Solution{}.rob({1, 2, 3, 1}) << endl;
  cout << Solution{}.rob({2, 7, 9, 3, 1}) << endl;
}
