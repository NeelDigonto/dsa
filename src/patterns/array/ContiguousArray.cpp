#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int findMaxLength(const vector<int> &nums) {
    int running_sum = 0, max_len = 0;
    unordered_map<int, int> registry;
    registry.insert({0, -1});

    for (auto it = cbegin(nums); it != cend(nums); ++it) {
      running_sum += *it ? 1 : -1;

      auto res = registry.find(running_sum);
      if (res != end(registry))
        max_len = max<int>(max_len, distance(begin(nums), it) - res->second);
      else
        registry[running_sum] = distance(begin(nums), it);
    }

    return max_len;
  }
};

int main() {
  cout << Solution{}.findMaxLength({0, 1}) << endl;    // 2
  cout << Solution{}.findMaxLength({0, 1, 0}) << endl; // 2
}
