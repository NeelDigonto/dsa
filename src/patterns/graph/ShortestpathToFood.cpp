#include <core/Common.hpp>
#include <core/Graph.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int getFood(const vector<vector<char>> &grid) {
    size_t rows = grid.size(), cols = begin(grid)->size();
    int distance = -1;
    queue<pair<uint8_t, uint8_t>> q;
    vector<vector<bool>> seen(rows, vector<bool>(cols, false));

    for (size_t row = 0; row != rows; ++row) {
      for (size_t col = 0; col != cols; ++col) {
        if (grid[row][col] == '*') {
          q.emplace(pair<uint8_t, uint8_t>{row, col});
          seen[row][col] = true;
          break;
        }
      }
    }

    while (!q.empty()) {
      size_t node_count = q.size();
      ++distance;

      for (size_t i = 0; i != node_count; ++i) {
        auto &[row, col] = q.front();

        if (grid[row][col] == '#')
          return distance;

        if (row != 0 && !seen[row - 1][col] && grid[row - 1][col] != 'X')
          q.emplace(pair<int16_t, int16_t>{row - 1, col}), seen[row - 1][col] = true;

        if (col != 0 && !seen[row][col - 1] && grid[row][col - 1] != 'X')
          q.emplace(pair<int16_t, int16_t>{row, col - 1}), seen[row][col - 1] = true;

        if (row != rows - 1 && !seen[row + 1][col] && grid[row + 1][col] != 'X')
          q.emplace(pair<int16_t, int16_t>{row + 1, col}), seen[row + 1][col] = true;

        if (col != cols - 1 && !seen[row][col + 1] && grid[row][col + 1] != 'X')
          q.emplace(pair<int16_t, int16_t>{row, col + 1}), seen[row][col + 1] = true;

        q.pop();
      }
    }

    return -1;
  }
};

int main() {
  cout << Solution{}.getFood({{'X', 'X', 'X', 'X', 'X', 'X'},
                              {'X', '*', 'O', 'O', 'O', 'X'},
                              {'X', 'O', 'O', '#', 'O', 'X'},
                              {'X', 'X', 'X', 'X', 'X', 'X'}})
       << endl; // 3
  cout << Solution{}.getFood({{'X', 'X', 'X', 'X', 'X'},
                              {'X', '*', 'X', 'O', 'X'},
                              {'X', 'O', 'X', '#', 'X'},
                              {'X', 'X', 'X', 'X', 'X'}})
       << endl; // -1
  cout << Solution{}.getFood({{'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                              {'X', '*', 'O', 'X', 'O', '#', 'O', 'X'},
                              {'X', 'O', 'O', 'X', 'O', 'O', 'X', 'X'},
                              {'X', 'O', 'O', 'O', 'O', '#', 'O', 'X'},
                              {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}})
       << endl; // 6
}
