#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    size_t m = matrix.size(), n = begin(matrix)->size();

    // Transpose
    for (size_t i = 0; i != m; ++i)
      for (size_t j = 0; j != i + 1; ++j)
        swap(matrix[i][j], matrix[j][i]);

    // Vertical Flip
    for (size_t i = 0; i != m; ++i)
      for (size_t j = 0; j != n / 2; ++j)
        swap(matrix[i][j], matrix[i][n - 1 - j]);
  }
};

int main() {
  {
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution{}.rotate(matrix);
    cout << matrix << endl;
  }
  cout << endl;
  {
    vector<vector<int>> matrix{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    Solution{}.rotate(matrix);
    cout << matrix << endl;
  }
}
