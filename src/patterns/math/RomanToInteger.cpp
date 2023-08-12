#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int romanToInt(string s) {

    int_fast16_t value = 0;

    for (size_t i = 0; i != s.size(); ++i) {

      switch (s[i]) {
      case 'I':
        value += 1;
        break;

      case 'V':
        if (i != 0 && s[i - 1] == 'I')
          value += 4 - 1;
        else
          value += 5;
        break;

      case 'X':
        if (i != 0 && s[i - 1] == 'I')
          value += 9 - 1;
        else
          value += 10;
        break;

      case 'L':
        if (i != 0 && s[i - 1] == 'X')
          value += 40 - 10;
        else
          value += 50;
        break;

      case 'C':
        if (i != 0 && s[i - 1] == 'X')
          value += 90 - 10;
        else
          value += 100;
        break;

      case 'D':
        if (i != 0 && s[i - 1] == 'C')
          value += 400 - 100;
        else
          value += 500;
        break;

      case 'M':
        if (i != 0 && s[i - 1] == 'C')
          value += 900 - 100;
        else
          value += 1000;
        break;

      default:
        break;
      }
    }

    return value;
  }
};

int main() {
  cout << Solution{}.romanToInt("III") << endl;     // 3
  cout << Solution{}.romanToInt("LVIII") << endl;   // 58
  cout << Solution{}.romanToInt("MCMXCIV") << endl; // 1994
}
