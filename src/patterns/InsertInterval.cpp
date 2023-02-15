#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<vector<int>> insert(const vector<vector<int>> &intervals, const vector<int> &newInterval) {
    vector<vector<int>> finalInterval;
    const auto rbs = upper_bound(begin(intervals), end(intervals), newInterval[0],
                                 [](const auto lhs, const auto rhs) { lhs[0] < rhs[0] });

    finalInterval.insert(end(finalInterval), begin(intervals), rbs);

    const auto rbe = upper_bound(begin(intervals), end(intervals), newInterval[1],
                                 [](const auto lhs, const auto rhs) { lhs[1] < rhs[1] });
  }
};

int main() {
  cout << Solution{}.insert({{1, 3}, {6, 9}}, {2, 5}) << endl;
  cout << Solution{}.insert({{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}}, {4, 8}) << endl;
}
