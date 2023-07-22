#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  bool canAttendMeetings(vector<vector<int>> &&intervals) {
    if (intervals.empty())
      return true;

    sort(begin(intervals), end(intervals), [](const auto &lhs, const auto &rhs) { return lhs[0] < rhs[0]; });

    for (size_t i = 1; i != intervals.size(); ++i)
      if (intervals[i - 1][1] > intervals[i][0])
        return false;

    return true;
  }
};

int main() {
  cout << boolalpha << Solution{}.canAttendMeetings({{0, 30}, {5, 10}, {15, 20}}) << endl;
  cout << boolalpha << Solution{}.canAttendMeetings({{7, 10}, {2, 4}}) << endl;
}
