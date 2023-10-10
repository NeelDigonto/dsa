#include <core/Common.hpp>
#include <core/Graph.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int countComponents(int n, const vector<vector<int>> &edges) {
    DSU<uint16_t> dsu(n);

    for (const auto &edge : edges) {
      dsu.connect(edge[0], edge[1]);
    }

    return dsu.getComponentCount();
  }
};

int main() {
  cout << Solution{}.countComponents(5, {{0, 1}, {1, 2}, {3, 4}}) << endl;         // 2
  cout << Solution{}.countComponents(5, {{0, 1}, {1, 2}, {2, 3}, {3, 4}}) << endl; // 1
}
