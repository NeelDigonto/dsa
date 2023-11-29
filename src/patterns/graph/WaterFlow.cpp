#include <core/Common.hpp>
#include <core/Graph.hpp>
#include <iostream>
using namespace std;

class Solution {
private:
  struct index {
    uint8_t row;
    uint8_t col;
  };

  vector<vector<bool>> bfs(queue<index> &_queue, const vector<vector<int>> &_grid) {
    auto &q = _queue;
    const size_t rows = _grid.size(), cols = begin(_grid)->size();
    vector<vector<bool>> seen(rows, vector<bool>(cols, false));

    while (!q.empty()) {
      const uint8_t node_count = q.size();

      for (uint8_t i = 0; i != node_count; ++i) {
        auto node = q.front();
        auto row = node.row, col = node.col;
        seen[row][col] = true;
        q.pop();

        if (row != 0 && !seen[row - 1][col] && _grid[row][col] <= _grid[row - 1][col])
          q.emplace(index{static_cast<uint8_t>(row - 1U), col});

        if (col != 0 && !seen[row][col - 1] && _grid[row][col] <= _grid[row][col - 1])
          q.emplace(index{row, static_cast<uint8_t>(col - 1)});

        if (row != rows - 1 && !seen[row + 1][col] && _grid[row][col] <= _grid[row + 1][col])
          q.emplace(index{static_cast<uint8_t>(row + 1), col});

        if (col != cols - 1 && !seen[row][col + 1] && _grid[row][col] <= _grid[row][col + 1])
          q.emplace(index{row, static_cast<uint8_t>(col + 1)});
      }
    }

    return seen;
  }

public:
  vector<vector<int>> pacificAtlantic(const vector<vector<int>> &heights) {
    const size_t rows = heights.size(), cols = begin(heights)->size();
    queue<index> pacific_q, atlantic_q;

    for (size_t row = 0; row != rows; ++row) {
      pacific_q.emplace(index{static_cast<uint8_t>(row), 0U});
      atlantic_q.emplace(index{static_cast<uint8_t>(row), static_cast<uint8_t>(cols - 1)});
    }

    for (size_t col = 0; col != cols; ++col) {
      pacific_q.emplace(index{0U, static_cast<uint8_t>(col)});
      atlantic_q.emplace(index{static_cast<uint8_t>(rows - 1), static_cast<uint8_t>(col)});
    }

    auto pacific_flow = bfs(pacific_q, heights);
    auto atlantic_flow = bfs(atlantic_q, heights);
    vector<vector<int>> result_set;

    for (size_t row = 0; row != rows; ++row) {
      for (size_t col = 0; col != cols; ++col) {
        if (pacific_flow[row][col] && atlantic_flow[row][col])
          result_set.emplace_back(vector<int>{static_cast<uint8_t>(row), static_cast<uint8_t>(col)});
      }
    }

    return result_set;
  }
};

int main() {
  cout << Solution{}.pacificAtlantic(
              {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}})
       << endl;                                                 // [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
  cout << Solution{}.pacificAtlantic({{1}}) << endl;            // [[0,0]]
  cout << Solution{}.pacificAtlantic({{2, 1}, {1, 2}}) << endl; // [[0,0],[0,1],[1,0],[1,1]]
}
