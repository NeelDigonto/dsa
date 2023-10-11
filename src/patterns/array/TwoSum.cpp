#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> twoSum(const vector<int> &nums, int target) {
    unordered_map<int, typename vector<int>::const_iterator> cache;
    cache.reserve(nums.size());

    for (auto it = begin(nums); it != end(nums); ++it) {
      const auto complement = target - *it;
      const auto res = cache.find(complement);

      if (res != end(cache))
        return {static_cast<int>(distance(begin(nums), res->second)), static_cast<int>(distance(begin(nums), it))};

      cache.insert({*it, it});
    }

    return {};
  }
};

int main() {
  cout << Solution{}.twoSum({2, 7, 11, 15}, 9) << endl; // [0, 1]
  cout << Solution{}.twoSum({3, 2, 4}, 6) << endl;      // [1, 2]
  cout << Solution{}.twoSum({3, 3}, 6) << endl;         // [0, 1]
}
