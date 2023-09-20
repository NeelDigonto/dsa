#include <core/Common.hpp>
#include <iostream>

using namespace std;

class Solution {
private:
  int maximalSquareTab(const vector<vector<char>> &matrix) {
    const size_t rows = matrix.size(), cols = begin(matrix)->size();
    vector<vector<uint16_t>> dp(rows + 1, vector<uint16_t>(cols + 1, 0));
    uint16_t global_max_area = 0;

    for (size_t i = 1; i != rows + 1; ++i)
      for (size_t j = 1; j != cols + 1; ++j)
        if (matrix[i - 1][j - 1] == '1') {
          dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
          global_max_area = max(dp[i][j], global_max_area);
        }

    return global_max_area * global_max_area;
  }

  inline int maximalSquareTabSO(const vector<vector<char>> &matrix) const noexcept {
    const size_t rows = matrix.size(), cols = begin(matrix)->size();
    vector<uint16_t> dp(cols + 1, 0);
    uint16_t upper_prev = 0, global_max_area = 0;

    for (size_t i = 1; i != rows + 1; ++i) {
      for (size_t j = 1; j != cols + 1; ++j) {
        auto temp = dp[j];

        if (matrix[i - 1][j - 1] == '1') {
          dp[j] = min({dp[j - 1], dp[j], upper_prev}) + 1;
          global_max_area = max(dp[j], global_max_area);
        } else
          dp[j] = 0;

        upper_prev = temp;
      }
    }

    return global_max_area * global_max_area;
  }

public:
  int maximalSquare(const vector<vector<char>> &matrix) {
    //    return maximalSquareTab(matrix);
    return maximalSquareTabSO(matrix);
  }
};

int main() {
  cout << Solution{}.maximalSquare({{'1', '0', '1', '0', '0'},
                                    {'1', '0', '1', '1', '1'},
                                    {'1', '1', '1', '1', '1'},
                                    {'1', '0', '0', '1', '0'}}) // 4
       << endl;
  cout << Solution{}.maximalSquare({{'0'}}) << endl;                  // 0
  cout << Solution{}.maximalSquare({{'0', '1'}, {'1', '0'}}) << endl; // 1
  cout << Solution{}.maximalSquare({{'1', '0'}}) << endl;             // 1

  cout << Solution{}.maximalSquare({
              {'1', '0', '1', '1', '0', '1'},
              {'1', '1', '1', '1', '1', '1'},
              {'0', '1', '1', '0', '1', '1'},
              {'1', '1', '1', '0', '1', '0'},
              {'0', '1', '1', '1', '1', '1'},
              {'1', '1', '0', '1', '1', '1'},
          })
       << endl; // 4
}
