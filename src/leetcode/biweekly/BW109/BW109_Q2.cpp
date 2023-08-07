#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  string sortVowels(string &&s) {
    vector<char> sorted_vowels;
    vector<int> indices;

    for (int i = 0; i != s.size(); ++i) {
      switch (s[i]) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
        indices.push_back(i);
        sorted_vowels.push_back(s[i]);
        break;

      default:
        break;
      }
    }
    sort(begin(sorted_vowels), end(sorted_vowels));

    int count = 0;
    for (auto &vowel : sorted_vowels)
      s[indices[count++]] = vowel;

    return s;
  }
};

int main() {
  cout << Solution{}.sortVowels("lEetcOde") << endl;
  cout << Solution{}.sortVowels("lYmpH") << endl;
  cout << Solution{}.sortVowels("qUSUCJeJZt") << endl; //"qUSUCJeJZt"
}
