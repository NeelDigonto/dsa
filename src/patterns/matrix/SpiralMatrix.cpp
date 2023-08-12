#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(const vector<vector<int>> &matrix) {
    size_t m = matrix.size(), n = begin(matrix)->size();
    int left = 0, up = 0, right = n - 1, down = m - 1;

    vector<int> result;
    result.reserve(m + n);

    while (result.size() != m * n) {
      // Traverse from left to right.
      for (int col = left; col <= right; col++) {
        result.push_back(matrix[up][col]);
      }
      // Traverse downwards.
      for (int row = up + 1; row <= down; row++) {
        result.push_back(matrix[row][right]);
      }
      // Make sure we are now on a different row.
      if (up != down) {
        // Traverse from right to left.
        for (int col = right - 1; col >= left; col--) {
          result.push_back(matrix[down][col]);
        }
      }
      // Make sure we are now on a different column.
      if (left != right) {
        // Traverse upwards.
        for (int row = down - 1; row > up; row--) {
          result.push_back(matrix[row][left]);
        }
      }
      left++;
      right--;
      up++;
      down--;
    }

    return result;
  }
};

int main() {
  cout << Solution{}.spiralOrder({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}) << endl;
  cout << Solution{}.spiralOrder({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}) << endl;
}
