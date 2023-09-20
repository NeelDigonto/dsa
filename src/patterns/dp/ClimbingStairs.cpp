#include <core/Common.hpp>
#include <iostream>

using namespace std;

class Solution {
private:
  inline int climbStairsRec(int n) const noexcept {
    if (n == 1)
      return 1;

    if (n == 2)
      return 2;

    return climbStairsRec(n - 1) + climbStairsRec(n - 2);
  }

  inline int _climbStairsMemo(int n, vector<int> &cache) const noexcept {
    if (cache[n] != -1)
      return cache[n];

    const auto res = _climbStairsMemo(n - 1, cache) + _climbStairsMemo(n - 2, cache);
    cache[n] = res;

    return res;
  }

  inline int climbStairsMemo(int n) const noexcept {
    if (n <= 2)
      return n;

    vector<int> cache(n + 1, -1);
    cache[1] = 1;
    cache[2] = 2;

    return _climbStairsMemo(n, cache);
  }

  inline int climbStairsTab(int n) const noexcept {
    if (n <= 2)
      return n;

    vector<int> cache(n + 1, -1);
    cache[1] = 1;
    cache[2] = 2;

    for (size_t i = 3; i != n + 1; ++i) {
      cache[i] = cache[i - 1] + cache[i - 2];
    }

    return cache[n];
  }

  inline int climbStairsTabSO(int n) const noexcept {
    if (n <= 2)
      return n;

    int prev2 = 1, prev = 2;

    for (size_t i = 3; i != n + 1; ++i) {
      auto curr = prev + prev2;
      prev2 = prev;
      prev = curr;
    }

    return prev;
  }

public:
  inline int climbStairs(int n) const noexcept {
    // return climbStairsRec(n);
    // return climbStairsMemo(n);
    // return climbStairsTab(n);
    return climbStairsTabSO(n);
  }
};

int main() {
  cout << Solution{}.climbStairs(2) << endl;  // 2
  cout << Solution{}.climbStairs(3) << endl;  // 3
  cout << Solution{}.climbStairs(45) << endl; // 1836311903
  cout << Solution{}.climbStairs(1) << endl;  // 1
}
