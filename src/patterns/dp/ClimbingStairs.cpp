#include <core/Common.hpp>
#include <iostream>

using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    if (n == 1)
      return 1;
    int prev_prev = 1, prev = 2;

    for (int i = 3; i != n + 1; ++i) {
      int curr = prev + prev_prev;
      prev_prev = prev;
      prev = curr;
    }

    return prev;
  }
};

int main() {
  cout << Solution{}.climbStairs(2) << endl;
  cout << Solution{}.climbStairs(3) << endl;
}
