#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int minChanges(const string &s) {
    if (s.size() & 1)
      return -1;

    if (s.size() == 2)
      if (s[0] == s[1])
        return 0;
      else
        return 1;

    array<int, 2> lc, rc;
    lc.fill(0);
    rc.fill(0);

    size_t lidx = 0, ridx = s.size() - 1, min_ops = 0;

    while (lidx != s.size() - 2) {
      ++lc[s[lidx++] - '0'];
      ++rc[s[ridx--] - '0'];
    }

    return min_ops;

    return (abs(lc[0] - lc[1]), abs(lc[0] - lc[1]));
  }
};

int main() {
  cout << Solution{}.minChanges("1001") << endl; // 2
  cout << Solution{}.minChanges("10") << endl;   // 1
  cout << Solution{}.minChanges("0000") << endl; // 0
}
