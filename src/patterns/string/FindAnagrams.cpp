#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> findAnagrams(const string s, const string p) {
    if (s.size() < p.size())
      return {};

    array<uint16_t, 26> registry;
    array<uint16_t, 26> window;
    registry.fill(0);
    window.fill(0);
    vector<int> indexes;

    for (size_t i = 0; i != p.size(); ++i) {
      registry[p[i] - 'a']++;
      window[s[i] - 'a']++;
    }

    if (window == registry)
      indexes.push_back(0);

    for (size_t i = p.size(); i != s.size(); ++i) {
      window[s[i - p.size()] - 'a']--;
      window[s[i] - 'a']++;

      if (window == registry)
        indexes.push_back(i - p.size() + 1);
    }

    return indexes;
  }
};

int main() {
  cout << Solution{}.findAnagrams("cbaebabacd", "abc") << endl;
  cout << Solution{}.findAnagrams("abab", "ab") << endl;
}
