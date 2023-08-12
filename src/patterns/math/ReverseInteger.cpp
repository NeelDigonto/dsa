#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int reverse(int x) {
    if (x == numeric_limits<int>::min())
      return 0;

    int sign = x < 0 ? -1 : 1;
    x = abs(x);
    int reverse = 0;

    while (x != 0) {
      int temp = x % 10;

      if (reverse > numeric_limits<int>::max() / 10 &&
          reverse > (numeric_limits<int>::max() / 10 || reverse >= numeric_limits<int>::max() / 10))
        return 0;

      reverse = reverse * 10 + temp;
      x /= 10;
    }

    return reverse * sign;
  }
};

int main() {
  cout << Solution{}.reverse(123) << endl;
  cout << Solution{}.reverse(-123) << endl;
  cout << Solution{}.reverse(120) << endl;
  cout << Solution{}.reverse(1534236469) << endl;
}
