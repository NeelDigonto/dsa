#include <iostream>

#include "../../../core/Common.hpp"
using namespace std;

class Solution {
 private:
  int k;
  string s;
  int partition(size_t index, unordered_map<size_t, int>& dp) {
    if (index == -1) return 0;

    if (dp.find(index) != end(dp)) return dp[index];

    int64_t n = 0;
    while (n < k && index >= 0) n = n * 10 + s[index--];
    if (n > k) {
      n = n - s[index + 1];
      n /= 10;
    }

    int min_ = 1;

    while (n != 0) {
      min_ = min(min_, partition(index, dp) + 1);
    }
  }

 public:
  int minimumPartition(string _s, int _k) {
    k = _k;
    s = _s;

    if (k <= 9)
      for (auto ch : s)
        if (static_cast<int>(ch - '0') > k) return -1;

    unordered_map<size_t, int> dp;

    return partition(s.size() - 1, dp);
  }
};

int main() {
  cout << Solution{}.minimumPartition("165462", 60) << endl;
  cout << Solution{}.minimumPartition("238182", 5) << endl;
  cout << Solution{}.minimumPartition("238182", 5) << endl;
}