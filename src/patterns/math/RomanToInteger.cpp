#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int romanToInt(string s) {}
};

int main() {
  cout << Solution{}.romanToInt("III") << endl;     // 3
  cout << Solution{}.romanToInt("LVIII") << endl;   // 1
  cout << Solution{}.romanToInt("MCMXCIV") << endl; // 3
}
