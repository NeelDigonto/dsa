#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int numIslands(const vector<vector<char>> &grid) { return {}; }
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
