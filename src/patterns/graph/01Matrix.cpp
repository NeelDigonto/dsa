#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<vector<int>> updateMatrix(const vector<vector<int>> &mat) {
    size_t m = mat.size(), n = begin(mat)->size();
    vector<vector<int>> res(m, vector<int>(n, 0));
    vector<vector<bool>> seen(m, vector<bool>(n, false));
    queue<pair<int16_t, int16_t>> q;

    for (size_t row = 0; row != m; ++row)
      for (size_t col = 0; col != n; ++col)
        if (mat[row][col] == 0) {
          q.emplace(pair<int16_t, int16_t>{row, col});
          seen[row][col] = true;
        }

    int level{0};

    while (!q.empty()) {
      size_t node_count = q.size();

      for (size_t i = 0; i != node_count; ++i) {
        auto [row, col] = q.front();
        q.pop();

        res[row][col] = level;

        // left
        if (col != 0 && !seen[row][col - 1])
          q.emplace(pair<int16_t, int16_t>{row, col - 1}), seen[row][col - 1] = true;
        // top
        if (row != 0 && !seen[row - 1][col])
          q.emplace(pair<int16_t, int16_t>{row - 1, col}), seen[row - 1][col] = true;
        // right
        if (col != n - 1 && !seen[row][col + 1])
          q.emplace(pair<int16_t, int16_t>{row, col + 1}), seen[row][col + 1] = true;
        // bottom
        if (row != m - 1 && !seen[row + 1][col])
          q.emplace(pair<int16_t, int16_t>{row + 1, col}), seen[row + 1][col] = true;
      }

      ++level;
    }

    return res;
  }
};

int main() {
  cout << Solution{}.updateMatrix({
              {0, 0, 0},
              {0, 1, 0},
              {0, 0, 0},
          })
       << endl; // [[0,0,0],[0,1,0],[0,0,0]]
  cout << Solution{}.updateMatrix({
              {0, 0, 0},
              {0, 1, 0},
              {1, 1, 1},
          })
       << endl; // [[0,0,0],[0,1,0],[1,2,1]]
}
