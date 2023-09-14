#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
    int total_gain = 0, current_gain = 0, start = 0;

    for (size_t i = 0; i != gas.size(); ++i) {
      total_gain += gas[i] - cost[i];
      current_gain += gas[i] - cost[i];

      if (current_gain < 0)
        current_gain = 0, start = i + 1;
    }

    return total_gain >= 0 ? start : -1;
  }
};

int main() {
  cout << Solution{}.canCompleteCircuit({1, 2, 3, 4, 5}, {3, 4, 5, 1, 2}) << endl; // 3
  cout << Solution{}.canCompleteCircuit({2, 3, 4}, {3, 4, 3}) << endl;             // -1
}
