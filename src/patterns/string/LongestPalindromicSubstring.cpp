#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
private:
  string getPalindrome(const string &s, int l, int r) {
    while (l >= 0 && r < s.size() && s[l] == s[r])
      l--, r++;

    return s.substr(l + 1, r - l - 1);
  }

public:
  string longestPalindrome(const string &s) {
    string longest_palindrome = "";

    for (size_t i = 0; i != s.size(); i++) {
      const auto p1 = getPalindrome(s, i, i);
      const auto p2 = getPalindrome(s, i, i + 1);

      if (p1.size() > longest_palindrome.size())
        longest_palindrome = p1;

      if (p2.size() > longest_palindrome.size())
        longest_palindrome = p2;
    }

    return longest_palindrome;
  }
};

int main() {
  cout << Solution{}.longestPalindrome("babad") << endl; // 3
  cout << Solution{}.longestPalindrome("cbbd") << endl;  // 1
}
