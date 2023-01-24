#include <iostream>

#include "../core/Common.hpp"
using namespace std;

class Solution {
 public:
  vector<vector<int>>* image;
  size_t m, n;
  int color;

  vector<vector<int>>& floodFill(vector<vector<int>>& image, int sr, int sc,
                                 int color) {
    Solution::image = &image;
    m = image.size(), n = begin(image)->size();
    Solution::color = color;

    _floodFill(sr, sc);

    return image;
  }

  void _floodFill(int sr, int sc) {
    if (sr < 0 || sr >= m || sc < 0 || sc >= n || (*image)[sr][sc] == color)
      return;

    const auto curr_val = (*image)[sr][sc];
    (*image)[sr][sc] = color;

    if ((*image)[sr - 1][sc] == curr_val) _floodFill(sr - 1, sc);  // up
    if ((*image)[sr + 1][sc] == curr_val) _floodFill(sr + 1, sc);  // down
    if ((*image)[sr][sc - 1] == curr_val) _floodFill(sr, sc - 1);  // left
    if ((*image)[sr][sc + 1] == curr_val) _floodFill(sr, sc + 1);  // right
  }
};

int main() {
  vector<vector<int>> i1 = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}}, i2 = {
                                                                  {0, 0, 0},
                                                                  {0, 0, 0},
                                                              };

  cout << Solution{}.floodFill(i1, 1, 1, 2) << endl;
  cout << Solution{}.floodFill(i2, 0, 0, 0) << endl;
}
