#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
 public:
  int maximumTastiness(vector<int>&& price, int k) {
    sort(begin(price), end(price));

    int small, small2;
    small = small2 = numeric_limits<int>::max();

    for (size_t i = 0; i != k; ++i) {
      if (small > price[i]) {
        small2 = small;
        small = price[i];
      } else if (small2 > price[i])
        small2 = price[i];
    }
  }
};

int main() {
  cout << Solution{}.maximumTastiness({13, 5, 1, 8, 21, 2}, 3) << endl;
  cout << Solution{}.maximumTastiness({1, 3, 1}, 3) << endl;
  cout << Solution{}.maximumTastiness({7, 7, 7, 7}, 2) << endl;
}