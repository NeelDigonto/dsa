#include <core/Common.hpp>
#include <iostream>

using namespace std;

class Solution {
private:
  template <typename T> T isOdd(T _num) { return _num & 1; }

public:
  int longestAlternatingSubarray(const vector<int> &nums, int threshold) {
    int globalMax = 0;
    int l = 0, r = 0;

    while (l <= r && r < nums.size()) {
      if (isOdd(nums[l])) {
        l++, r++;
        continue;
      }

      r = l;
      while (r < nums.size() && nums[r] <= threshold) {
        const auto count = r - l + 1;
        bool oddeven = ((count >= 2) ? (isOdd(nums[r]) != isOdd(nums[r - 1])) : true);

        if (oddeven) {
          globalMax = max(globalMax, count);
          r++;
        } else {
          globalMax = max(globalMax, count - 1);
          break;
        }
      }

      l++, r++;
    }

    return globalMax;
  }
};

int main() {
  cout << Solution{}.longestAlternatingSubarray({3, 2, 5, 4}, 5) << endl;
  cout << Solution{}.longestAlternatingSubarray({1, 2}, 2) << endl;
  cout << Solution{}.longestAlternatingSubarray({2, 3, 4, 5}, 4) << endl;
  cout << Solution{}.longestAlternatingSubarray({2, 2}, 18) << endl;      // 1
  cout << Solution{}.longestAlternatingSubarray({2, 7}, 9) << endl;       // 2
  cout << Solution{}.longestAlternatingSubarray({3, 2, 5, 4}, 5) << endl; // 3
  cout << Solution{}.longestAlternatingSubarray({8, 4}, 6) << endl;       // 1
}
