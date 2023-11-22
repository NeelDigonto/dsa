#include <core/Common.hpp>
#include <core/Graph.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> findMinHeightTrees(int n, const vector<vector<int>> &edges) {
    if (n == 1)
      return {0};

    vector<int> in_degrees(n, 0U);
    vector<vector<int>> graph(n);
    queue<int> q;
    vector<int> result_set;

    for (const auto &edge : edges) {
      ++in_degrees[edge[0]];
      ++in_degrees[edge[1]];
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    for (size_t i = 0; i != n; ++i) {
      if (in_degrees[i] == 1)
        q.push(i);
    }

    while (!q.empty()) {
      size_t node_count = q.size();
      result_set.clear();

      for (size_t i = 0; i != node_count; ++i) {
        auto node = q.front();
        q.pop();

        if (node_count <= 2)
          result_set.push_back(node);

        for (auto &neighbor : graph[node]) {
          --in_degrees[neighbor];

          if (in_degrees[neighbor] == 1)
            q.push(neighbor);
        }
      }
    }

    return result_set;
  }
};

int main() {
  cout << Solution{}.findMinHeightTrees(4, {{1, 0}, {1, 2}, {1, 3}}) << endl;                 // {1}
  cout << Solution{}.findMinHeightTrees(6, {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}}) << endl; // {3, 4}
}
