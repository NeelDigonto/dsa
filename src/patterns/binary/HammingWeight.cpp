#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int_fast8_t count = 0;
    while (n != 0) {
      count++;
      n &= n - 1;
    }

    return count;
  }
};

int main() {
  cout << Solution{}.hammingWeight(0b00000000000000000000000000001011) << endl;
  cout << Solution{}.hammingWeight(0b00000000000000000000000010000000) << endl;
  cout << Solution{}.hammingWeight(0b11111111111111111111111111111101) << endl;
}
