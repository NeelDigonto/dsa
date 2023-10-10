#include <core/Common.hpp>
#include <iostream>

using namespace std;

class Solution {
public:
  int differenceOfSums(int n, int m) {
    int64_t num1 = 0, num2 = 0;

    for (int i = 1; i != n + 1; ++i) {
      if (i % m == 0)
        num2 += i;
      else
        num1 += i;
    }

    return num1 - num2;
  }
};

int main() {
  cout << Solution{}.differenceOfSums(10, 3) << endl; // 19
  cout << Solution{}.differenceOfSums(5, 6) << endl;  // 15
  cout << Solution{}.differenceOfSums(5, 1) << endl;  // -15
}
