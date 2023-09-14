#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &&nums) {
    vector<int> products(nums.size(), {});

    int prefix = 1, suffix = 1;
    for (auto it = begin(nums), it2 = begin(products); it != end(nums); ++it, ++it2)
      *it2 = prefix, prefix *= *it;

    for (auto it = rbegin(nums), it2 = rbegin(products); it != rend(nums); ++it, ++it2)
      *it2 = *it2 * suffix, suffix *= *it;

    return products;
  }
};

int main() {
  cout << Solution{}.productExceptSelf({1, 2, 3, 4}) << endl;      // [24,12,8,6]
  cout << Solution{}.productExceptSelf({-1, 1, 0, -3, 3}) << endl; // [0,0,9,0,0]
}
