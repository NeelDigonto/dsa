#include <core/Common.hpp>
#include <iostream>

using namespace std;

class Solution {
private:
  /*  int coinChangeM(const vector<int> &coins, vector<int> &dp, int amount) {
     if (amount == 0)
       return 0;

     if (dp[amount] != -1)
       return dp[amount];

     for (auto coin : coins) {
       const auto diff = amount - coin;
       if (diff >= 0)
         dp[amount] = min(dp[amount], 1 + coinChange(coins, dp, diff));
     }

     return dp[amount];
   } */

public:
  /* int coinChange(const vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;
    coinChange(coins, dp, amount);
  } */

  int coinChange(const vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, numeric_limits<int>::max() - 1);
    dp[0] = 0;

    for (int curr_amt = 1; curr_amt != amount + 1; ++curr_amt)
      for (auto coin : coins)
        if (coin <= curr_amt)
          dp[curr_amt] = min(dp[curr_amt], 1 + dp[curr_amt - coin]);

    return (dp[amount] != numeric_limits<int>::max() - 1 ? dp[amount] : -1);
  }
};

int main() {
  cout << Solution{}.coinChange({1, 2, 5}, 11) << endl;
  cout << Solution{}.coinChange({2}, 3) << endl;
  cout << Solution{}.coinChange({1}, 0) << endl;
}
