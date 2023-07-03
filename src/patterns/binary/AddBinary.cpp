#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    auto n1 = crbegin(a), n2 = crbegin(b);
    int carry = 0;
    string add;
    add.reserve(max(a.size(), b.size()) + 1U);

    while (n1 != crend(a) || n2 != crend(b) || carry) {
      if (n1 != crend(a))
        carry += *(n1++) - '0';
      if (n2 != crend(b))
        carry += *(n2++) - '0';

      add += carry % 2 + '0';
      carry /= 2;
    }

    reverse(begin(add), end(add));
    return add;
  }
};

int main() {
  cout << Solution{}.addBinary("11", "1") << endl;
  cout << Solution{}.addBinary("1010", "1011") << endl;
}
