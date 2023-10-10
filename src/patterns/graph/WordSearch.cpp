#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
private:
  bool bactrack(const vector<vector<char>> &board, size_t row, size_t col, const string &word, size_t idx,
                vector<vector<bool>> &seen) {
    if (idx == word.size())
      return true;

    size_t rows = board.size();
    size_t cols = begin(board)->size();

    if (row == -1 || col == -1 || row == rows || col == cols || seen[row][col] || board[row][col] != word[idx])
      return false;

    seen[row][col] = true;

    bool res = bactrack(board, row + 1, col, word, idx + 1, seen) ||
               bactrack(board, row, col + 1, word, idx + 1, seen) ||
               bactrack(board, row - 1, col, word, idx + 1, seen) || bactrack(board, row, col - 1, word, idx + 1, seen);

    seen[row][col] = false;

    return res;
  }

public:
  bool exist(const vector<vector<char>> &board, const string &word) {
    size_t rows = board.size();
    size_t cols = begin(board)->size();

    vector<vector<bool>> seen(rows, vector<bool>(cols, false));

    for (size_t row = 0; row != rows; ++row) {
      for (size_t col = 0; col != cols; ++col) {
        if (bactrack(board, row, col, word, 0, seen))
          return true;
      }
    }

    return false;
  }
};

int main() {
  cout << boolalpha
       << Solution{}.exist(
              {
                  {'A', 'B', 'C', 'E'},
                  {'S', 'F', 'C', 'S'},
                  {'A', 'D', 'E', 'E'},
              },
              "ABCCED")
       << endl; // true
  cout << boolalpha
       << Solution{}.exist(
              {
                  {'A', 'B', 'C', 'E'},
                  {'S', 'F', 'C', 'S'},
                  {'A', 'D', 'E', 'E'},
              },
              "SEE")
       << endl; // true
  cout << boolalpha
       << Solution{}.exist(
              {
                  {'A', 'B', 'C', 'E'},
                  {'S', 'F', 'C', 'S'},
                  {'A', 'D', 'E', 'E'},
              },
              "ABCB")
       << endl; // false
}
