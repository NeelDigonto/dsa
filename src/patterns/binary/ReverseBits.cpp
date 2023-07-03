#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;

    for (auto i = 0; i != 32; ++i) {
      uint32_t bit = (n >> i) & 1;
      res |= (bit << (31 - i));
    }

    return res;
  }
};

int main() {
  cout << Solution{}.reverseBits(0b00000010100101000001111010011100) << endl;
  cout << Solution{}.reverseBits(0b11111111111111111111111111111101) << endl;
}
