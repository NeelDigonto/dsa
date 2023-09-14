#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &&intervals) {
    sort(begin(intervals), end(intervals),
         [](const vector<int> &lhs, const vector<int> &rhs) { return lhs[0] < rhs[0]; });

    vector<int> prev{intervals[0][0], intervals[0][1]};
    vector<vector<int>> mintervals;

    for (auto it = next(begin(intervals)); it != end(intervals); ++it) {
      if (prev[1] < (*it)[0]) {
        mintervals.push_back(prev);
        prev[0] = (*it)[0];
      }

      prev[1] = max(prev[1], (*it)[1]);
    }

    mintervals.emplace_back(prev);
    return mintervals;
  }
};

int main() {
  cout << Solution{}.merge({{1, 3}, {2, 6}, {8, 10}, {15, 18}}) << endl; // [[1,6],[8,10],[15,18]]
  cout << Solution{}.merge({{1, 4}, {4, 5}}) << endl;                    // [[1,5]]
  cout << Solution{}.merge({{1, 4}, {0, 4}}) << endl;                    // [[0,4]]
  cout << Solution{}.merge({{1, 4}, {2, 3}}) << endl;                    // [[1,4]]
}
