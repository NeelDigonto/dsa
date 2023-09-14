#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int minMeetingRooms(vector<vector<int>> &&intervals) {
    sort(begin(intervals), end(intervals),
         [](const vector<int> &lhs, const vector<int> &rhs) { return lhs[0] < rhs[0]; });

    priority_queue<int, vector<int>, greater<int>> meets;

    for (const auto &interval : intervals) {
      if (!meets.empty() && meets.top() <= interval[0])
        meets.pop();

      meets.push(interval[1]);
    }

    return meets.size();
  }
};

int main() {
  cout << Solution{}.minMeetingRooms({{0, 30}, {5, 10}, {15, 20}}) << endl; // 2
  cout << Solution{}.minMeetingRooms({{7, 10}, {2, 4}}) << endl;            // 1
  cout << Solution{}.minMeetingRooms({{5, 8}, {6, 8}}) << endl;             // 2
}
