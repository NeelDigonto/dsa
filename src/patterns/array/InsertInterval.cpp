#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<vector<int>> insert(const vector<vector<int>> &intervals, const vector<int> &newInterval) {
    vector<vector<int>> new_intervals;

    const auto lb = lower_bound(begin(intervals), end(intervals), newInterval,
                                [](const auto &lhs, const auto &rhs) { return lhs[0] < rhs[0]; });

    new_intervals.insert(end(new_intervals), begin(intervals), lb);

    const auto ub = upper_bound(begin(intervals), end(intervals), newInterval,
                                [](const auto &lhs, const auto &rhs) { return lhs[1] < rhs[1]; });

    vector<int> merged_interval{2, {}};
    merged_interval[0] = min((*lb)[0], newInterval[0]);
    merged_interval[1] = max((*ub)[1], newInterval[1]);
    new_intervals.emplace_back(move(merged_interval));

    new_intervals.insert(end(new_intervals), lb, end(intervals));

    return new_intervals;
  }
};

int main() {
  cout << Solution{}.insert({{1, 3}, {6, 9}}, {2, 5}) << endl;
  cout << Solution{}.insert({{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}}, {4, 8}) << endl;
}

/*
    vector<vector<int>> finalInterval;
    const auto rbs = upper_bound(begin(intervals), end(intervals), newInterval[0],
                                 [](const auto lhs, const auto rhs) { return lhs[0] < rhs[0]; });

    finalInterval.insert(end(finalInterval), begin(intervals), rbs);

    const auto rbe = upper_bound(begin(intervals), end(intervals), newInterval[1],
                                 [](const auto lhs, const auto rhs) { return lhs[1] < rhs[1]; });
*/