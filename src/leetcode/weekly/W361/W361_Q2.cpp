#include <core/Common.hpp>
#include <iostream>

using namespace std;

class Solution {
public:
  int minimumOperations(const string &num) {
    const auto l0 = num.find_last_of('0');
    const auto l5 = num.find_last_of('5');
    const auto f0 = num.find_first_of('0');

    const auto p0 = !l0 ? -1 : num.find_last_of('0', l0 - 1);
    const auto p5 = !l0 ? -1 : num.find_last_of('5', l0 - 1);

    const auto p2 = !l5 ? -1 : num.find_last_of('2', l5 - 1);
    const auto p7 = !l5 ? -1 : num.find_last_of('7', l5 - 1);

    size_t ops = numeric_limits<size_t>::max(), lx = num.size() - 1;

    if (l0 != string::npos) {
      if (p0 != string::npos)
        ops = min(ops, (lx - l0) + (l0 - p0 - 1));

      if (p5 != string::npos)
        ops = min(ops, (lx - l0) + (l0 - p5 - 1));
    }

    if (l5 != string::npos) {
      if (p2 != string::npos)
        ops = min(ops, (lx - l5) + (l5 - p2 - 1));

      if (p7 != string::npos)
        ops = min(ops, (lx - l5) + (l5 - p7 - 1));
    }

    if (f0 != string::npos)
      ops = min(ops, (f0 - 0) + (lx - f0));

    if (l0 != string::npos)
      ops = min(ops, (l0 - 0) + (lx - l0));

    if (ops == numeric_limits<size_t>::max())
      return lx + 1;

    return ops;
  }
};

int main() {
  cout << Solution{}.minimumOperations("2245047") << endl; // 2
  cout << Solution{}.minimumOperations("2908305") << endl; // 3
  cout << Solution{}.minimumOperations("10") << endl;      // 1
  cout << Solution{}.minimumOperations("1") << endl;       // 1
}