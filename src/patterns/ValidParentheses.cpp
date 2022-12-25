#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
 public:
  bool isValid(const string s) {
    stack<typename string::value_type> set;
    for (const auto ch : s) {
      if (set.empty())
        set.push(ch);
      else if (set.top() == '(' && ch == ')')
        set.pop();
      else if (set.top() == '{' && ch == '}')
        set.pop();
      else if (set.top() == '[' && ch == ']')
        set.pop();
      else
        set.push(ch);
    }

    return set.empty();
  }
};

int main() {
  cout << boolalpha << Solution{}.isValid("()") << endl;
  cout << boolalpha << Solution{}.isValid("()[]{}") << endl;
  cout << boolalpha << Solution{}.isValid("(]") << endl;
}
