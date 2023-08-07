#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  bool isGood(vector<int> &&nums) {
    const auto maxe_it = distance(begin(nums), max_element(begin(nums), end(nums)));
    const auto maxe = nums[maxe_it];

    if (nums.size() != maxe + 1)
      return false;

    nums[0] *= -1;
    for (size_t i = 0; i != nums.size(); ++i) {
      nums[abs(nums[i])] *= -1;
    }

    for (size_t i = 0; i != nums.size(); ++i) {
      if ((i == nums.size() - 1 || i == nums.size() - 2) && nums[i] >= 0)
        continue;

      if (nums[i] < 0)
        continue;

      return false;
    }

    return true;
  }
};

int main() {
  cout << boolalpha << Solution{}.isGood({2, 1, 3}) << endl;
  cout << boolalpha << Solution{}.isGood({1, 3, 3, 2}) << endl;
  cout << boolalpha << Solution{}.isGood({1, 1}) << endl;
  cout << boolalpha << Solution{}.isGood({3, 4, 4, 1, 2, 1}) << endl;
}
