#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> findOrder(int numCourses, const vector<vector<int>> &prerequisites) {
    vector<uint16_t> in_degrees(numCourses, 0U);
    vector<vector<uint16_t>> graph(numCourses);

    for (const auto &prerequisite : prerequisites) {
      const auto &to = prerequisite[0], &from = prerequisite[1];
      in_degrees[to]++;
      graph[from].push_back(to);
    }

    queue<int16_t> q;
    vector<int> topological_order;
    topological_order.reserve(numCourses);

    for (size_t i = 0; i != numCourses; ++i) {
      if (in_degrees[i] == 0)
        q.push(i);
    }

    size_t nodes_visited = 0;

    while (!q.empty()) {
      auto node = q.front();
      q.pop();
      ++nodes_visited;
      topological_order.push_back(node);

      for (auto &neighbor : graph[node]) {
        --in_degrees[neighbor];

        if (in_degrees[neighbor] == 0)
          q.push(neighbor);
      }
    }

    return (nodes_visited == numCourses ? topological_order : vector<int>{});
  }
};

int main() {
  cout << boolalpha << Solution{}.findOrder(2, {{1, 0}}) << endl;                         // [0,1]
  cout << boolalpha << Solution{}.findOrder(4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}) << endl; // [0,2,1,3]
  cout << boolalpha << Solution{}.findOrder(1, {}) << endl;                               // [0]
  cout << boolalpha << Solution{}.findOrder(3, {{1, 0}, {1, 2}, {0, 1}}) << endl;         // []
}
