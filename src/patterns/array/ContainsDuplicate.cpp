#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  bool containsDuplicate(const vector<int> &nums) {
    unordered_map<int, int> registry_;

    for (auto &num : nums)
      registry_[num]++;

    for (auto &[num, count] : registry_)
      if (count > 1)
        return true;

    return false;
  }
};

int main() {
  cout << boolalpha << Solution{}.containsDuplicate({1, 2, 3, 1}) << endl;
  cout << boolalpha << Solution{}.containsDuplicate({1, 2, 3, 4}) << endl;
  cout << boolalpha << Solution{}.containsDuplicate({1, 1, 1, 3, 3, 4, 3, 2, 4, 2}) << endl;
}
