#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> findClosestElements(vector<int> &&arr, int k, int x) {

    auto lb = lower_bound(begin(arr), end(arr), x);

    if (*lb != x && lb != begin(arr) && abs(x - *prev(lb)) < abs(x - *lb))
      --lb;

    /*     const auto rd = distance(lb, end(arr)) - 1;

        const auto maxrd = min(static_cast<int>(rd), k / 2);
        auto frb = next(lb, k - maxld);
        auto flb = prev(lb, maxld);

        return vector<int>(flb, frb); */

    return {};
  }
};

int main() {
  cout << Solution{}.findClosestElements({1, 2, 3, 4, 5}, 4, 3) << endl;         // [1,2,3,4]
  cout << Solution{}.findClosestElements({1, 2, 3, 4, 5}, 4, -1) << endl;        // [1,2,3,4]
  cout << Solution{}.findClosestElements({-2, -1, 1, 2, 3, 4, 5}, 7, 3) << endl; // [-2,-1,1,2,3,4,5]
}

// to keep [>, <]