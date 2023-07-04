#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
private:
  template <typename T = uint16_t> T char_to_idx(char _ch) {
    if (_ch >= 'a' && _ch <= 'z')
      return _ch - 'a';
    else
      return _ch - 'A' + 26;
  }

public:
  int longestPalindrome(string s) {
    array<uint16_t, 52> registry_;
    registry_.fill(0);

    for (size_t i = 0; i != s.size(); ++i)
      registry_[char_to_idx(s[i])]++;

    uint16_t max_len = 0, odd_count = 0;

    for (size_t i = 0; i != registry_.size(); ++i)
      if (registry_[i] % 2 == 0)
        max_len += registry_[i];
      else {
        max_len += registry_[i] - 1;
        odd_count++;
      }

    if (odd_count > 0)
      max_len += 1;

    return max_len;
  }
};

int main() {
  cout << Solution{}.longestPalindrome("abccccdd") << endl;
  cout << Solution{}.longestPalindrome("a") << endl;
}
