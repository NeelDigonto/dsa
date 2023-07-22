#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int majorityElement(const vector<int> &nums) {
    int majority_num = *begin(nums);
    int count = 1;

    for (auto it = next(begin(nums)); it != end(nums); ++it) {
      if (count == 0)
        majority_num = *it;

      if (*it == majority_num)
        count++;
      else
        count--;
    }

    return majority_num;
  }
};

int main() {
  cout << Solution{}.majorityElement({3, 2, 3}) << endl;
  cout << Solution{}.majorityElement({2, 2, 1, 1, 1, 2, 2}) << endl;
}
