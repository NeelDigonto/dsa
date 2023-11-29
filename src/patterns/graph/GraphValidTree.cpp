#include <core/Common.hpp>
#include <core/Graph.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  bool validTree(int n, const vector<vector<int>> &edges) {
    if (edges.size() != n - 1)
      return false;

    DSU<uint16_t> dsu(n);

    for (auto edge : edges) {
      if (!dsu.connect(edge[0], edge[1]))
        return false;
    }

    return true;
  }
};

int main() {
  cout << boolalpha << Solution{}.validTree(5, {{0, 1}, {0, 2}, {0, 3}, {1, 4}}) << endl;         // true
  cout << boolalpha << Solution{}.validTree(5, {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}}) << endl; // false
}
