#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int minOperations(const vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> registry(k + 1, n);

    for (auto it = rbegin(nums); it != rend(nums); ++it) {
      if (*it <= k)
        registry[*it] = min<int>(registry[*it], distance(rbegin(nums), it) + 1);
    }

    return *max_element(next(begin(registry)), end(registry));
  }
};

int main() {
  cout << Solution{}.minOperations({3, 1, 5, 4, 2}, 2) << endl; // 4
  cout << Solution{}.minOperations({3, 1, 5, 4, 2}, 5) << endl; // 5
  cout << Solution{}.minOperations({3, 2, 5, 3, 1}, 3) << endl; // 4
}