#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int missingNumber(const vector<int> &nums) {
    int missing = 0;
    for (auto num : nums)
      missing ^= num;
    for (auto i = 0; i != nums.size() + 1; ++i)
      missing ^= i;

    return missing;
  }
};

int main() {
  cout << Solution{}.missingNumber({3, 0, 1}) << endl;
  cout << Solution{}.missingNumber({0, 1}) << endl;
  cout << Solution{}.missingNumber({9, 6, 4, 2, 3, 5, 7, 0, 1}) << endl;
}
