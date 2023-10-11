#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int maxArea(const vector<int> &height) {
    int marea = 0;
    auto l = begin(height), r = prev(end(height));

    while (l < r) {
      marea = max<int>(marea, min(*l, *r) * distance(l, r));

      if (*l <= *r)
        l++;
      else
        r--;
    }

    return marea;
  }
};

int main() {
  cout << Solution{}.maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7}) << endl; // 49
  cout << Solution{}.maxArea({1, 1}) << endl;                      // 1
}
