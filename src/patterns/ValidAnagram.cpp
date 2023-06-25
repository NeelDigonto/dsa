#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  bool isAnagram(const string &s, const string &t) {
    array<int, static_cast<std::size_t>('z') + 1U> counts;
    counts.fill(0);

    for (const auto &ch : s)
      counts[ch]++;
    for (const auto &ch : t)
      counts[ch]--;
    for (auto count : counts)
      if (count != 0)
        return false;
    return true;
  }
};

int main() {
  cout << boolalpha << Solution{}.isAnagram("anagram", "nagaram") << endl;
  cout << boolalpha << Solution{}.isAnagram("rat", "car") << endl;
}
