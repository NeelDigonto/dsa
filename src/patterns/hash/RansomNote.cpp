#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  bool canConstruct(const string ransomNote, const string magazine) {
    array<int32_t, 26> dict;
    dict.fill(0);

    for (auto letter : magazine)
      dict[letter - 'a']++;

    for (auto letter : ransomNote)
      dict[letter - 'a']--;

    for (auto count : dict)
      if (count < 0)
        return false;

    return true;
  }
};

int main() {
  cout << Solution{}.canConstruct("a", "b") << endl;
  cout << Solution{}.canConstruct("aa", "ab") << endl;
  cout << Solution{}.canConstruct("aa", "aab") << endl;
}
