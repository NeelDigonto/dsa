#include <core/Common.hpp>
#include <iostream>

using namespace std;

class Solution {
public:
  int countSymmetricIntegers(int low, int high) {
    int count = 0;

    for (int i = low; i != high + 1; ++i) {
      int temp = i;

      if (temp >= 10 && temp <= 99) {
        int rs = temp % 10;
        temp /= 10;

        int ls = temp;

        if (ls == rs)
          count++;
      }

      if (temp >= 1000 && temp <= 9999) {
        int rs = temp % 10;
        temp /= 10;
        rs = rs + (temp % 10);
        temp /= 10;

        int ls = temp % 10;
        temp /= 10;
        ls = ls + temp;

        if (ls == rs)
          count++;
      }
    }

    return count;
  }
};

int main() {
  cout << Solution{}.countSymmetricIntegers(1, 100) << endl;     // 9
  cout << Solution{}.countSymmetricIntegers(1200, 1230) << endl; // 4
}
