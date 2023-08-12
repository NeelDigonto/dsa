#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    size_t m = matrix.size(), n = begin(matrix)->size();

    for (size_t i = 0; i != m; ++i)
      for (size_t j = 0; j != n; ++j)
        if (matrix[i][j] == 0)
          matrix[i][0] = 0, matrix[0][j] = 0;

    for (size_t i = 0; i != m; ++i)
      for (size_t j = 0; j != n; ++j)
        if ((matrix[i][0] == 0) || (matrix[0][j] == 0))
          matrix[i][j] = 0;
  }
};

int main() {
  {
    vector<vector<int>> matrix{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    Solution{}.setZeroes(matrix);
    cout << matrix << endl;
  }
  cout << endl;
  {
    vector<vector<int>> matrix{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    Solution{}.setZeroes(matrix);
    cout << matrix << endl;
  }
}
