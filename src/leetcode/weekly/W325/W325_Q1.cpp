#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
 public:
  int closetTarget(const vector<string>& words, string target, int startIndex) {
    int i = startIndex, j = startIndex;
    size_t ld = 0, rd = 0, n = words.size();
    while (true) {
      if (words[i] == target) return ld;
      if (words[j] == target) return rd;

      i = (i + 1) % n;
      j = (j - 1 + n) % n;

      if (i == startIndex || j == startIndex) return -1;

      ld++;
      rd++;
    }
  }
};

int main() {
  cout << Solution{}.closetTarget({"hello", "i", "am", "leetcode", "hello"},
                                  "hello", 1)
       << endl;
  cout << Solution{}.closetTarget({"a", "b", "leetcode"}, "leetcode", 0)
       << endl;
  cout << Solution{}.closetTarget({"i", "eat", "leetcode"}, "ate", 0) << endl;
  cout << Solution{}.closetTarget(
              {"pgmiltbptl", "jnkxwutznb", "bmeirwjars", "ugzyaufzzp",
               "pgmiltbptl", "sfhtxkmzwn", "pgmiltbptl", "pgmiltbptl",
               "onvmgvjhxa", "jyzdtwbwqp"},
              "pgmiltbptl", 4)
       << endl;
}
// 0