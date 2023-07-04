#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int myAtoi(const string s) {
    int sign = 1;
    int32_t number = 0;
    bool has_number = false, has_sign = false;

    for (size_t i = 0; i != s.size(); i++) {
      if (!has_number && s[i] == ' ')
        continue;

      if (!has_number && !has_sign && s[i] == '-') {
        sign = -1;
        has_sign = true;
        continue;
      }

      if (!has_number && !has_sign && s[i] == '+') {
        sign = +1;
        has_sign = true;
        continue;
      }

      if (s[i] >= '0' && s[i] <= '9') {
        has_number = true;

        const auto test_val = (10LL * number + (s[i] - '0')) * sign;

        if (test_val > numeric_limits<int32_t>::max()) {
          number = numeric_limits<int32_t>::max();
          break;
        } else if (test_val < numeric_limits<int32_t>::min()) {
          number = numeric_limits<int32_t>::min();
          break;
        }

        number = 10LL * number + (s[i] - '0');
        continue;
        ;
      }

      // Fall through if unkown chars & no number read
      break;
    }

    return number == numeric_limits<int32_t>::min() ? number : number * sign;
  }
};

int main() {
  cout << Solution{}.myAtoi("42") << endl;
  cout << Solution{}.myAtoi("   -42") << endl;
  cout << Solution{}.myAtoi("4193 with words") << endl;
  cout << Solution{}.myAtoi("words and 987") << endl;
  cout << Solution{}.myAtoi("-91283472332") << endl;
  cout << Solution{}.myAtoi("3.14159") << endl;
  cout << Solution{}.myAtoi("+-12") << endl;
  cout << Solution{}.myAtoi("00000-42a1234") << endl;
  cout << Solution{}.myAtoi("   +0 123") << endl;
  cout << Solution{}.myAtoi("-2147483647") << endl;
}
