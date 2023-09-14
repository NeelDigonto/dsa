#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int subarraySum(vector<int> &&nums, int k) {
    unordered_map<int, int> cache;
    size_t count = 0;

    partial_sum(nums.begin(), nums.end(), begin(nums));

    for (auto it = begin(nums); it != end(nums); ++it) {
      if (*it == k)
        count++;

      const auto complement = *it - k;
      if (cache.find(complement) != cache.end())
        count += cache[complement];

      cache[*it]++;
    }

    return count;
  }
};

int main() {
  cout << Solution{}.subarraySum({1, 1, 1}, 2) << endl; // 2
  cout << Solution{}.subarraySum({1, 2, 3}, 3) << endl; // 2
}
