#include <core/Common.hpp>
#include <core/List.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int leastInterval(const vector<char> &tasks, int n) {
    array<int, 26U> freqs;
    freqs.fill(0);
    int max_freq = 0, max_freq_count = 0;

    for (auto task : tasks)
      freqs[task - 'A']++, max_freq = max(max_freq, freqs[task - 'A']);

    for (auto freq : freqs)
      if (freq == max_freq)
        max_freq_count++;

    const int time = (max_freq - 1) * (n + 1) + max_freq_count;

    return max(time, static_cast<int>(tasks.size()));
  }
};

int main() {
  cout << Solution{}.leastInterval({'A', 'A', 'A', 'B', 'B', 'B'}, 2) << endl; // 8
  cout << Solution{}.leastInterval({'A', 'A', 'A', 'B', 'B', 'B'}, 0) << endl; // 6
  cout << Solution{}.leastInterval({'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'},
                                   2) << endl; // 16
}