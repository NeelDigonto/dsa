#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
 public:
  int maxProfit(const vector<int>& prices) {
    vector<int> max_sell(prices.size(), numeric_limits<int>::min());

    auto it = rbegin(max_sell);
    auto it2 = rbegin(prices);
    *it = *it2, it++, it2++;

    for (; it != rend(max_sell); ++it, ++it2) *it = max(*prev(it), *it2);

    int max_profit = 0;
    for (auto it3 = begin(prices); it3 != prev(end(prices)); ++it3) {
      const auto d = distance(begin(prices), it3);
      const auto sell = *next(begin(max_sell), d + 1);
      const auto profit = sell - *it3;
      max_profit = max(max_profit, profit);
    }

    return max_profit;
  }
};

int main() {
  cout << Solution{}.maxProfit({7, 1, 5, 3, 6, 4}) << endl;
  cout << Solution{}.maxProfit({7, 6, 4, 3, 1}) << endl;
}
