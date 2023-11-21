#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int sumCounts(const vector<int> &nums) {
    size_t n = nums.size();
    unordered_set<int> registry;
    int sum = 0;

    for (size_t i = 0; i != n; ++i) {
      for (size_t j = i; j != n; ++j) {
        registry.insert(nums[j]);
        sum += registry.size() * registry.size();
      }
    }

    return sum;
  }
};

int main() {
  cout << Solution{}.sumCounts({1, 2, 1}) << endl; // 15
  // cout << Solution{}.sumCounts({1, 1}) << endl;    // 3
}