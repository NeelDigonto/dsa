#include <core/Common.hpp>
#include <iostream>

using namespace std;

class Solution {
private:
  int isExclusive(char a, char b) { return (a == '0' || b == '0'); }

public:
  int numDecodings(const string s) {
    if (s.size() == 1)
      return 1;

    for (size_t i = 0; i != s.size() - 1; ++i)
      if (isExclusive(s[i], s[i + 1]))
        ;
  }
};

int main() {
  cout << Solution{}.numDecodings("12") << endl;
  cout << Solution{}.numDecodings("226") << endl;
  cout << Solution{}.numDecodings("06") << endl;
}
