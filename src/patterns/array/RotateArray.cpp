#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    k = k % nums.size();

    reverse(begin(nums), end(nums));
    reverse(begin(nums), next(begin(nums), k));
    reverse(next(begin(nums), k), end(nums));
  }
};

int main() {
  {
    vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    Solution{}.rotate(nums, 3); // [5,6,7,1,2,3,4]
    cout << nums << endl;
  }
  {
    vector<int> nums{-1, -100, 3, 99};
    Solution{}.rotate(nums, 2); // [3,99,-1,-100]
    cout << nums << endl;
  }
}
