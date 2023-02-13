#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int maxProfit(const vector<int> &prices) {
    int max_profit = 0;
    int min_buy = numeric_limits<int>::max();

    for (auto it = begin(prices); it != end(prices); ++it) {
      if (*it < min_buy)
        min_buy = *it;
      else
        max_profit = max(max_profit, *it - min_buy);
    }

    return max_profit;
  }
};

int main() {
  cout << Solution{}.maxProfit({7, 1, 5, 3, 6, 4}) << endl;
  cout << Solution{}.maxProfit({7, 6, 4, 3, 1}) << endl;
}
