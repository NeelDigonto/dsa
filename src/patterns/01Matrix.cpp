#include <core/Common.hpp>
#include <iostream>
using namespace std;

/* class Solution {
public:
  vector<vector<int>> updateMatrix(const vector<vector<int>> &mat) {
    size_t m = mat.size(), n = begin(mat)->size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // cout << mat << endl;

    for (size_t row = 0; row != m; row++)
      for (size_t col = 0; col != n; col++)
        if (mat[row][col])
          dp[row][col] = m * n;

    //   cout << dp << endl;

    for (size_t row = 1; row != m; row++)
      for (size_t col = 1; col != n; col++)
        if (dp[row][col])
          dp[row][col] = 1 + min(dp[row - 1][col], dp[row][col - 1]);

    // cout << dp << endl;

    for (size_t row = m - 1; row != -1; row--)
      for (size_t col = n - 1; col != -1; col--) {
        if (dp[row][col])
          continue;

        if (row < m - 1)
          dp[row][col] = min(dp[row][col], dp[row + 1][col] + 1);

        if (col < n - 1)
          dp[row][col] = min(dp[row][col], dp[row][col + 1] + 1);
      }

    return dp;
  }
}; */

class Solution {
public:
  vector<vector<int>> updateMatrix(const vector<vector<int>> &mat) {
    vector<vector<int>> cost = mat;

    queue<pair<uint16_t, uint16_t>> visited;
    queue<pair<uint16_t, uint16_t>> to_visited;
  }
};

int main() {
  cout << Solution{}.updateMatrix({{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}) << endl;
  cout << Solution{}.updateMatrix({{0, 0, 0}, {0, 1, 0}, {1, 1, 1}}) << endl;
}
