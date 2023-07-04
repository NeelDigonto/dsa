#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(const vector<string> &strs) {
    string prefix = "";

    for (size_t i = 0; i != -1; ++i) {
      char ch;
      if (strs[0].size() && i < strs[0].size())
        ch = strs[0][i];

      for (auto &str : strs) {
        if (i == str.size()) {
          i = -1;
          break;
        }

        if (str[i] != ch) {
          i = -1;
          break;
        }
      }

      if (i != -1)
        prefix += ch;
    }

    return prefix;
  }
};

int main() {
  cout << Solution{}.longestCommonPrefix({"flower", "flow", "flight"}) << endl;
  // cout << Solution{}.longestCommonPrefix({"dog", "racecar", "car"}) << endl;
}
