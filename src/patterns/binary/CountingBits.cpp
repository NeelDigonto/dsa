#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> bit_counts(n + 1);
    bit_counts[0] = 0;

    for (uint32_t i = 1; i != n + 1; ++i)
      bit_counts[i] = bit_counts[i / 2] + (i & 1);

    return bit_counts;
  }
};

int main() {
  cout << Solution{}.countBits(2) << endl;
  cout << Solution{}.countBits(5) << endl;
}
