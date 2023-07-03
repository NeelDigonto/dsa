#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int singleNumber(const vector<int> &nums) {
    int unique = 0;
    for (auto num : nums)
      unique ^= num;

    return unique;
  }
};

int main() {
  cout << Solution{}.singleNumber({2, 2, 1}) << endl;
  cout << Solution{}.singleNumber({4, 1, 2, 1, 2}) << endl;
  cout << Solution{}.singleNumber({1}) << endl;
}
