#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int gasStation(const vector<int> &gas, const vector<int> &costs) {
    int total_gain = 0, gas_tank = 0, start_idx = 0;

    for (size_t i = 0; i != gas.size(); ++i) {
      total_gain += gas[i] - costs[i];
      gas_tank += gas[i] - costs[i]; // 3

      if (gas_tank < 0) {
        gas_tank = 0;
        start_idx = i + 1;
      }
    }

    return total_gain >= 0 ? start_idx : -1;
  };
};

int main() {
  cout << Solution{}.gasStation({1, 2, 3, 4, 5}, {3, 4, 5, 1, 2}) << endl;
  cout << Solution{}.gasStation({1, 2, 3, 4, 5}, {3, 4, 6, 1, 2}) << endl;
  cout << Solution{}.gasStation({1, 2, 3, 4, 5, 1, 2, 10, 12}, {3, 4, 5, 1, 2, 6, 7, 1, 3}) << endl;
}