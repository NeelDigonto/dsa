#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
private:
  void bfs(const vector<vector<char>> &_grid, vector<vector<bool>> &seen, pair<int16_t, int16_t> root) {
    size_t rows = _grid.size();
    size_t cols = begin(_grid)->size();

    queue<pair<int16_t, int16_t>> q;
    q.push(root);
    seen[root.first][root.second] = true;

    while (!q.empty()) {
      auto &[row, col] = q.front();

      if (row != 0 && !seen[row - 1][col] && _grid[row - 1][col] == '1')
        q.emplace(pair<int16_t, int16_t>{row - 1, col}), seen[row - 1][col] = true;

      if (col != 0 && !seen[row][col - 1] && _grid[row][col - 1] == '1')
        q.emplace(pair<int16_t, int16_t>{row, col - 1}), seen[row][col - 1] = true;

      if (row != rows - 1 && !seen[row + 1][col] && _grid[row + 1][col] == '1')
        q.emplace(pair<int16_t, int16_t>{row + 1, col}), seen[row + 1][col] = true;

      if (col != cols - 1 && !seen[row][col + 1] && _grid[row][col + 1] == '1')
        q.emplace(pair<int16_t, int16_t>{row, col + 1}), seen[row][col + 1] = true;

      q.pop();
    }
  }

public:
  int numIslands(const vector<vector<char>> &_grid) {
    size_t rows = _grid.size();
    size_t cols = begin(_grid)->size();

    size_t islands = 0;
    vector<vector<bool>> seen(rows, vector<bool>(cols, false));

    for (size_t row = 0; row != rows; ++row) {
      for (size_t col = 0; col != cols; ++col) {
        if (_grid[row][col] == '1' && !seen[row][col])
          bfs(_grid, seen, {row, col}), ++islands;
      }
    }

    return islands;
  }
};

int main() {
  cout << Solution{}.numIslands({{'1', '1', '1', '1', '0'},
                                 {'1', '1', '0', '1', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '0', '0', '0'}})
       << endl; // 1
  cout << Solution{}.numIslands({{'1', '1', '0', '0', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '1', '0', '0'},
                                 {'0', '0', '0', '1', '1'}})
       << endl; // 3
}
