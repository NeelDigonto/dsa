#include <core/Common.hpp>
#include <iostream>

using namespace std;

class Solution {
public:
  int minProcessingTime(vector<int> &&processorTime, vector<int> &&tasks) {
    sort(begin(processorTime), end(processorTime), less<int>{});
    sort(begin(tasks), end(tasks), greater<int>{});

    int max_time = 0;

    for (size_t i = 0; i != processorTime.size(); ++i) {
      int l_max_time = processorTime[i] + max({tasks[i * 4 + 0], tasks[i * 4 + 1], tasks[i * 4 + 2], tasks[i * 4 + 3]});
      max_time = max(max_time, l_max_time);
    }

    return max_time;
  }
};

int main() {
  cout << Solution{}.minProcessingTime({8, 10}, {2, 2, 3, 1, 8, 7, 4, 5}) << endl;  // 16
  cout << Solution{}.minProcessingTime({10, 20}, {2, 3, 1, 2, 5, 8, 4, 3}) << endl; // 23
}