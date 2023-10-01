#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int minOperations(const vector<int> &nums) {
    unordered_map<int, int> registry;

    for (auto num : nums)
      registry[num]++;

    int ops = 0;

    for (auto v : registry) {
      int count = v.second;

      int d3 = count / 3;
      ops += d3;
      count -= d3 * 3;

      if (d3 != 0 && count == 1) {
        // revert 1 step;
        --ops;
        count += 3;
      }

      if (count % 2 != 0)
        return -1;

      ops += count / 2;
    }

    return ops;
  }
};

int main() {
  cout << Solution{}.minOperations({2, 3, 3, 2, 2, 4, 2, 3, 4}) << endl; // 4
  cout << Solution{}.minOperations({2, 1, 2, 2, 3, 3}) << endl;          // -1
  cout << Solution{}.minOperations({14, 12, 14, 14, 12, 14, 14, 12, 12, 12, 12, 14, 14, 12, 14, 14, 14, 12, 12})
       << endl; // 7
}

// 12 : 9 ; 14 : 10

/*
  void createqset(vector<bool> &qset) {
    qset[2] = 1;
    qset[3] = 1;
    queue<int> q;
    q.push(2);
    q.push(3);

    while (!q.empty()) {
      int num = q.front();
      int ops = qset[num];

      int p2 = num + 2;
      int p3 = num + 3;

    }
  }
*/