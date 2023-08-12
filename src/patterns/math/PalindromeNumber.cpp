#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0 || (x != 0 && x % 10 == 0))
      return false;

    int reverted_number = 0;

    while (x > reverted_number) {
      int temp = x % 10;
      reverted_number = reverted_number * 10 + temp;
      x /= 10;
    }

    return ((x == reverted_number) || (x == reverted_number / 10));
  }
};

int main() {
  cout << boolalpha << Solution{}.isPalindrome(121) << endl;  // true
  cout << boolalpha << Solution{}.isPalindrome(-121) << endl; // false
  cout << boolalpha << Solution{}.isPalindrome(10) << endl;   // true
  cout << boolalpha << Solution{}.isPalindrome(123) << endl;  // false
}
