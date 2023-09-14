#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  bool containsDuplicate(const vector<int> &nums) {
    unordered_set<int> registry_;

    for (auto &num : nums) {
      if (registry_.find(num) != end(registry_))
        return true;

      registry_.insert(num);
    }

    return false;
  }
};

int main() {
  cout << boolalpha << Solution{}.containsDuplicate({1, 2, 3, 1}) << endl;
  cout << boolalpha << Solution{}.containsDuplicate({1, 2, 3, 4}) << endl;
  cout << boolalpha << Solution{}.containsDuplicate({1, 1, 1, 3, 3, 4, 3, 2, 4, 2}) << endl;
}
