#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int orangesRotting(const vector<vector<int>> &_grid) {
    size_t rows = _grid.size();
    size_t cols = begin(_grid)->size();

    size_t minutes = 0;
    vector<vector<bool>> seen(rows, vector<bool>(cols, false));

    queue<pair<int16_t, int16_t>> q;
    size_t cells_covered = 0;

    for (size_t row = 0; row != rows; ++row) {
      for (size_t col = 0; col != cols; ++col) {
        if (_grid[row][col] == 2)
          q.emplace(pair<int16_t, int16_t>{row, col});

        if (_grid[row][col] != 1)
          seen[row][col] = true, ++cells_covered;
      }
    }

    if (q.empty())
      ++minutes;

    while (!q.empty()) {
      size_t node_count = q.size();
      ++minutes;

      for (size_t i = 0; i != node_count; ++i) {
        auto &[row, col] = q.front();

        if (row != 0 && !seen[row - 1][col])
          q.emplace(pair<int16_t, int16_t>{row - 1, col}), seen[row - 1][col] = true, ++cells_covered;

        if (col != 0 && !seen[row][col - 1])
          q.emplace(pair<int16_t, int16_t>{row, col - 1}), seen[row][col - 1] = true, ++cells_covered;

        if (row != rows - 1 && !seen[row + 1][col])
          q.emplace(pair<int16_t, int16_t>{row + 1, col}), seen[row + 1][col] = true, ++cells_covered;

        if (col != cols - 1 && !seen[row][col + 1])
          q.emplace(pair<int16_t, int16_t>{row, col + 1}), seen[row][col + 1] = true, ++cells_covered;

        q.pop();
      }
    }

    return (cells_covered == rows * cols ? minutes - 1 : -1);
  }
};

int main() {
  cout << Solution{}.orangesRotting({
              {2, 1, 1},
              {1, 1, 0},
              {0, 1, 1},
          })
       << endl; // 4
  cout << Solution{}.orangesRotting({
              {2, 1, 1},
              {0, 1, 1},
              {1, 0, 1},
          })
       << endl;                                        // -1
  cout << Solution{}.orangesRotting({{0, 2}}) << endl; // 0
  cout << Solution{}.orangesRotting({{0}}) << endl;    // 0
}
