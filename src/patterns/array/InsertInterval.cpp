#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<vector<int>> insert(const vector<vector<int>> &intervals, const vector<int> &newInterval) {
    vector<vector<int>> new_intervals;

    auto lb = lower_bound(begin(intervals), end(intervals), newInterval,
                          [](const auto &lhs, const auto &val) { return lhs[1] < val[0]; });

    auto ub = upper_bound(begin(intervals), end(intervals), newInterval,
                          [](const auto &val, const auto &rhs) { return val[1] < rhs[0]; });

    if (lb == end(intervals)) {
      new_intervals.insert(end(new_intervals), begin(intervals), end(intervals));
      new_intervals.push_back(newInterval);
      return new_intervals;
    }

    vector<int> merged_interval{2, {}};
    merged_interval[0] = min((*lb)[0], newInterval[0]);
    merged_interval[1] = ub != begin(intervals) ? max((*prev(ub))[1], newInterval[1]) : newInterval[1];

    new_intervals.insert(end(new_intervals), begin(intervals), lb);
    new_intervals.push_back(merged_interval);
    new_intervals.insert(end(new_intervals), ub, end(intervals));

    return new_intervals;
  }
};

int main() {
  cout << Solution{}.insert({{1, 3}, {6, 9}}, {2, 5}) << endl;
  cout << Solution{}.insert({{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}}, {4, 8}) << endl;
  cout << Solution{}.insert({}, {5, 7}) << endl;
  cout << Solution{}.insert({{1, 5}}, {5, 7}) << endl;
  cout << Solution{}.insert({{1, 5}}, {6, 8}) << endl;
  cout << Solution{}.insert({{1, 5}}, {0, 0}) << endl;
}
