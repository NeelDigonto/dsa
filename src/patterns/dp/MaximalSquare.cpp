#include <core/Common.hpp>
#include <iostream>

using namespace std;

class Solution {
public:
  int maximalSquare(const vector<vector<char>> &matrix) {
    const size_t rows = matrix.size(), cols = begin(matrix)->size();
    vector<vector<uint16_t>> dp(rows + 1, vector<uint16_t>(cols + 1, 0));
    uint16_t global_max_area = 0;

    for (size_t i = 1; i != rows + 1; ++i)
      for (size_t j = 1; j != cols + 1; ++j)
        if (matrix[i - 1][j - 1] == '1') {
          dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
          global_max_area = max(dp[i][j], global_max_area);
        }

    return global_max_area * global_max_area;
  }
};

int main() {
  cout << Solution{}.maximalSquare({{'1', '0', '1', '0', '0'},
                                    {'1', '0', '1', '1', '1'},
                                    {'1', '1', '1', '1', '1'},
                                    {'1', '0', '0', '1', '0'}})
       << endl;
  cout << Solution{}.maximalSquare({{'0', '1'}, {'1', '0'}}) << endl;
  cout << Solution{}.maximalSquare({{'0'}}) << endl;
}
