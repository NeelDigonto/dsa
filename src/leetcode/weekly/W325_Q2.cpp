#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
 private:
  struct st {
    int a;
    int b;
    int c;
  };

 public:
  int takeCharacters(const string& s, int k) {
    if (k == 0) return 0;
    int n = s.size();
    vector<st> lc, rc;
    lc.reserve(k);
    rc.reserve(k);

    if (s[0] == 'a') lc.emplace_back(st{1, -1, -1});
    if (s[0] == 'b') lc.emplace_back(st{-1, 1, -1});
    if (s[0] == 'c') lc.emplace_back(st{-1, -1, 1});

    if (s[n - 1] == 'a') rc.emplace_back(st{1, -1, -1});
    if (s[n - 1] == 'b') rc.emplace_back(st{-1, 1, -1});
    if (s[n - 1] == 'c') rc.emplace_back(st{-1, -1, 1});

    for (int i = 1; i != n; ++i) {
      lc.push_back(lc[i - 1]);
      if (s[i] == 'a') lc[i].a = i + 1;
      if (s[i] == 'b') lc[i].b = i + 1;
      if (s[i] == 'c') lc[i].c = i + 1;
    }

    for (int i = 1; i != n; ++i) {
      rc.push_back(lc[i - 1]);
      if (s[n - 1 - i] == 'a') lc[i].a = i + 1;
      if (s[n - 1 - i] == 'b') lc[i].b = i + 1;
      if (s[n - 1 - i] == 'c') lc[i].c = i + 1;
    }

    for (int i = 1; i != n; ++i) {
    }
  }
};

int main() {
  cout << Solution{}.takeCharacters("aabaaaacaabc", 2) << endl;
  cout << Solution{}.takeCharacters("a", 1) << endl;
}