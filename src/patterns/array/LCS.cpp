#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int longestConsecutive(const vector<int> &nums) {
    unordered_set<int> registry(begin(nums), end(nums));
    int mlen = 0;

    for (auto it = begin(nums); it != end(nums); ++it) {
      if (registry.find(*it - 1) == end(registry)) {
        int llen = 1;
        int val = *it;
        while (registry.find(++val) != end(registry))
          llen++;

        mlen = max(mlen, llen);
      }
    }

    return mlen;
  }
};

int main() {
  cout << Solution{}.longestConsecutive({100, 4, 200, 1, 3, 2}) << endl;         // 4
  cout << Solution{}.longestConsecutive({0, 3, 7, 2, 5, 8, 4, 6, 0, 1}) << endl; // 9
}
