#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &&points, int k) {
    nth_element(begin(points), next(begin(points), k - 1), end(points),
                [](const vector<int> &lhs, const vector<int> &rhs) {
                  const auto lhsd = lhs[0] * lhs[0] + lhs[1] * lhs[1];
                  const auto rhsd = rhs[0] * rhs[0] + rhs[1] * rhs[1];

                  return lhsd < rhsd;
                });

    return vector<vector<int>>{begin(points), next(begin(points), k)};
  }
};

int main() {
  cout << Solution{}.kClosest({{1, 3}, {-2, 2}}, 1) << endl;          // [[-2,2]]
  cout << Solution{}.kClosest({{3, 3}, {5, -1}, {-2, 4}}, 2) << endl; // [[3,3], [-2,4]]
}