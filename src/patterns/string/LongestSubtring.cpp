#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(const string s) {
    array<uint_fast16_t, 128> registry_;
    registry_.fill(-1);

    size_t left = 0, right = 0, max_len = 0;

    while (right != s.size()) {
      const auto r = s[right];
      const auto idx = registry_[r];

      if (idx != -1 && idx >= left && idx < right)
        left = idx + 1;

      max_len = max(right - left + 1, max_len);

      registry_[r] = right;
      right++;
    }

    return max_len;
  }
};

int main() {
  cout << Solution{}.lengthOfLongestSubstring("abcabcbb") << endl; // 3
  cout << Solution{}.lengthOfLongestSubstring("bbbbb") << endl;    // 1
  cout << Solution{}.lengthOfLongestSubstring("pwwkew") << endl;   // 3
}
