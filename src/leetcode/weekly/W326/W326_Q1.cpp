#include <iostream>

#include "../../../core/Common.hpp"

using namespace std;

class Solution {
 public:
  int countDigits(int num) {
    int tnum = num, count = 0;

    while (tnum != 0) {
      int digit = tnum % 10;
      int divRes = num / digit;
      if ((divRes * digit) == num) count++;
      tnum /= 10;
    }

    return count;
  }
};

int main() {
  cout << Solution{}.countDigits(7) << endl;
  cout << Solution{}.countDigits(121) << endl;
  cout << Solution{}.countDigits(1248) << endl;
}