#include <iostream>

#include <core/Common.hpp>
using namespace std;

class Solution {
public:
  vector<vector<int>> *image;
  size_t m, n;
  int fill_color, area_color;

  vector<vector<int>> &floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
    Solution::image = &image;
    m = image.size(), n = begin(image)->size();
    Solution::fill_color = color;
    Solution::area_color = image[sr][sc];

    _floodFill(sr, sc);

    return image;
  }

  void _floodFill(int sr, int sc) {
    if (sr < 0 || sr >= m || sc < 0 || sc >= n || (*image)[sr][sc] == fill_color || (*image)[sr][sc] != area_color)
      return;

    (*image)[sr][sc] = fill_color;

    _floodFill(sr - 1, sc); // up
    _floodFill(sr + 1, sc); // down
    _floodFill(sr, sc - 1); // left
    _floodFill(sr, sc + 1); // right
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
