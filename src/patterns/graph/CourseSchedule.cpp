#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, const vector<vector<int>> &prerequisites) {
    vector<uint16_t> in_degrees(numCourses, 0U);
    vector<vector<uint16_t>> graph(numCourses);

    for (const auto &prerequisite : prerequisites) {
      in_degrees[prerequisite[0]]++;
      graph[prerequisite[1]].push_back(prerequisite[0]);
    }

    queue<int16_t> q;
    for (size_t i = 0; i != numCourses; ++i) {
      if (in_degrees[i] == 0)
        q.push(i);
    }

    size_t nodes_visited = 0;
    while (!q.empty()) {
      auto node = q.front();
      q.pop();
      ++nodes_visited;

      for (auto &neighbor : graph[node]) {
        --in_degrees[neighbor];

        if (in_degrees[neighbor] == 0)
          q.push(neighbor);
      }
    }

    return nodes_visited == numCourses;
  }
};

int main() {
  cout << boolalpha << Solution{}.canFinish(2, {{1, 0}}) << endl;         // true
  cout << boolalpha << Solution{}.canFinish(2, {{1, 0}, {0, 1}}) << endl; // false
}
