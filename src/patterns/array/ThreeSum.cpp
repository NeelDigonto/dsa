#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
private:
  void specialTwoSum(const vector<int> &nums, vector<int>::const_iterator pivot, vector<vector<int>> &three_sums) {
    auto l = next(pivot), r = prev(end(nums));

    while (l < r) {
      int target = -*pivot;

      if (*l + *r == target) {
        three_sums.emplace_back(vector<int>{*pivot, *l, *r});
        while (++l < r && *prev(l) == *l)
          ;
        while (--r > l && *next(r) == *r)
          ;
      } else if (*l + *r < target)
        while (++l < r && *prev(l) == *l)
          ;
      else
        while (--r > l && *next(r) == *r)
          ;
    }
  }

public:
  vector<vector<int>> threeSum(vector<int> &&nums) {
    vector<vector<int>> three_sums;

    sort(begin(nums), end(nums));

    specialTwoSum(nums, begin(nums), three_sums);

    for (auto it = next(begin(nums)); it != prev(end(nums), 2); ++it)
      if (*prev(it) != *it)
        specialTwoSum(nums, it, three_sums);

    return three_sums;
  }
};

int main() {
  cout << Solution{}.threeSum({-1, 0, 1, 2, -1, -4}) << endl; // [[-1,-1,2],[-1,0,1]]
  cout << Solution{}.threeSum({0, 1, 1}) << endl;             // []
  cout << Solution{}.threeSum({0, 0, 0}) << endl;             // [[0,0,0]]
  cout << Solution{}.threeSum({-1, 0, 1, 2, -1, -4}) << endl; // [[-1,-1,2],[-1,0,1]]
  cout << Solution{}.threeSum({-2, 0, 0, 2, 2}) << endl;      // [[-2,0,2]]
  cout << Solution{}.threeSum({-2, 0, 1, 1, 2}) << endl;      // [[-2,0,2],[-2,1,1]]
}
