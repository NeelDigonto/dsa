#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  double myPow(double x, int _n) {
    if (_n == 0)
      return 1.0;

    if (_n < 0)
      x = 1.0 / x;

    long long n = abs((long long)_n);
    double result = 1.0;

    while (n) {
      if (n % 2)
        result *= x, --n;

      x *= x, n /= 2;
    }

    return result;
  }
};

int main() {
  cout << Solution{}.myPow(2.00000, 10) << endl;          // 1024
  cout << Solution{}.myPow(2.10000, 3) << endl;           // 9.261
  cout << Solution{}.myPow(2.00000, -2) << endl;          // 0.25
  cout << Solution{}.myPow(1.00000, -2147483648) << endl; // 1.0
  cout << Solution{}.myPow(2.00000, 3) << endl;           // 2.00
}
