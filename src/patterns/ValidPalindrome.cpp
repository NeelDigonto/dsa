#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
private:
  bool isValid(char ch) { return (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'); }

public:
  bool isPalindrome(const string &s) {
    auto left = begin(s), right = prev(end(s));
    while (left <= right) {
      if (!isValid(tolower(*left)))
        left++;

      else if (!isValid(tolower(*right)))
        right--;

      else if (tolower(*left) != tolower(*right))
        return false;

      else
        left++, right--;
    }

    return true;
  }
};

int main() {
  cout << boolalpha << Solution{}.isPalindrome("A man, a plan, a canal: Panama") << endl;
  cout << boolalpha << Solution{}.isPalindrome("race a car") << endl;
  cout << boolalpha << Solution{}.isPalindrome(" ") << endl;
  cout << boolalpha << Solution{}.isPalindrome("0P") << endl;
}
