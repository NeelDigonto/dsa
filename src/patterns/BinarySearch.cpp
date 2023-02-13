#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int search(const vector<int> &nums, int target) {
    auto left = begin(nums), right = end(nums);

    while (left < right) {
      const auto d = distance(left, right);
      const auto mid = next(left, d / 2);

      if (*mid == target)
        return distance(begin(nums), mid);
      else if (*mid < target)
        left = next(mid);
      else
        right = mid;
    }

    return -1;
  }
};

/*
class Solution {
public:
  int search(const vector<int> &nums, int target) {
    auto left = begin(nums), right = prev(end(nums));

    while (left <= right) {
      const auto d = distance(left, right);
      const auto mid = next(left, d / 2);

      if (*mid == target)
        return distance(begin(nums), mid);
      else if (*mid < target)
        left = next(mid);
      else
        right = mid - 1;
    }

    return -1;
  }
};
*/

int main() {
  cout << Solution{}.search({-1, 0, 3, 5, 9, 12}, 9) << endl;
  cout << Solution{}.search({-1, 0, 3, 5, 9, 12}, 2) << endl;
  cout << Solution{}.search({}, 2) << endl;
}
