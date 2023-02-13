#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  bool isAnagram(const string &s, const string &t) {
    unordered_map<char, int> counts;
    counts.reserve(26);

    for (const auto &ch : s)
      counts[ch]++;
    for (const auto &ch : t)
      counts[ch]--;
    for (const auto &[_, count] : counts)
      if (count != 0)
        return false;
    return true;
  }
};

int main() {
  cout << boolalpha << Solution{}.isAnagram("anagram", "nagaram") << endl;
  cout << boolalpha << Solution{}.isAnagram("rat", "car") << endl;
}
