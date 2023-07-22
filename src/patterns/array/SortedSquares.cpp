#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> sortedSquares(const vector<int> &nums) {
    size_t pos_idx = distance(begin(nums), find_if(begin(nums), end(nums), [](auto val) { return val >= 0; })),
           neg_idx = pos_idx - 1;

    vector<int> sorted_squares;
    sorted_squares.reserve(nums.size());

    while (neg_idx != -1 || pos_idx != nums.size()) {
      const auto negv = (neg_idx != -1) ? nums[neg_idx] : numeric_limits<int>::min() + 1; // stops overflow
      const auto posv = (pos_idx != nums.size()) ? nums[pos_idx] : numeric_limits<int>::max();

      if (abs(negv) < abs(posv)) {
        sorted_squares.push_back(negv * negv);
        neg_idx--;
      } else {
        sorted_squares.push_back(posv * posv);
        pos_idx++;
      }
    }

    return sorted_squares;
  }
};

int main() {
  cout << boolalpha << Solution{}.sortedSquares({-4, -1, 0, 3, 10}) << endl;
  cout << boolalpha << Solution{}.sortedSquares({-7, -3, 2, 3, 11}) << endl;
}
