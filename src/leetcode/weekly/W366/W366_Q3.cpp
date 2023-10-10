#include <core/Common.hpp>
#include <iostream>

using namespace std;

class Solution {
private:
  struct patch {
    int start;
    int end;
  };

public:
  int minOperations(string s1, string s2, int x) {
    int ops = 0;

    vector<patch> patches;
    bool collecting_patch = false;

    for (int i = 0; i != s2.size(); ++i) {
      if (collecting_patch == false) {
        if (s1[i] != s2[i])
          patches.emplace_back(patch{.start = i, .end = i + 1});
      }

      if (collecting_patch == true) {
        if (s1[i] != s2[i])
          patches[i].end = i + 1;
        else
          collecting_patch = false;
      }
    }

    for (int i = 0; i != patches.size(); ++i) {
      auto dist = patches[i].end - patches[i].start;

      if (dist % 2 == 0)
        patches[i].start = patches[i].end, ops += dist / 2;
      else {
        if (i == 0) {
          patches[i].start = patches[i].end - 1;
          ops += dist / 2;
          continue;
        }

        if (patches[i - 1].end + 1 == patches[i].start)
          patches[i].start = patches[i].end, ops += dist / 2 + 1;
      }
    }

    int diff = 0;
    for (int i = 0; i != patches.size(); ++i)
      if (patches[i].end - patches[i].start > 0)
        ++diff;

    if (diff & 1)
      return -1;
    else
      return ops + (diff / 2) * x;
  }
};

int main() {
  cout << Solution{}.minOperations("1100011000", "0101001010", 2) << endl; // 4
  cout << Solution{}.minOperations("10110", "00011", 4) << endl;           // -1
}
