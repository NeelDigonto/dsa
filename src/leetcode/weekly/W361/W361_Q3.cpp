#include <core/Common.hpp>
#include <iostream>

using namespace std;

class Solution {
public:
  long long countInterestingSubarrays(const vector<int> &nums, int modulo, int k) {
    long long count = 0;
    vector<int> lens;

    int start = -1, end = -1;
    for (int i = 0; i != nums.size(); ++i) {
      if (start == -1 && (nums[i] % modulo == k))
        start = end = i;

      if (nums[i] % modulo == k)
        end = i;
      else if (start != -1) {
        lens.push_back(end - start + 1);
        start = end = -1;
      }
    }

    for (int cnt : lens) {
      while (cnt-- != 0)
        if (cnt % modulo == k)
          count++;
    }

    return count;
  }
};

int main() {
  cout << Solution{}.countInterestingSubarrays({3, 2, 4}, 2, 1) << endl;    // 3
  cout << Solution{}.countInterestingSubarrays({3, 1, 9, 6}, 3, 0) << endl; // 2
}
