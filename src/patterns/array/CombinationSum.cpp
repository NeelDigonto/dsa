#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
private:
  void _combinationSum(const vector<int> &candidates, vector<vector<int>> &combinations,
                       vector<int> &current_combination, int target, int current_sum, vector<int>::const_iterator it) {
    if (current_sum > target)
      return;

    if (current_sum == target) {
      combinations.push_back(current_combination);
      return;
    }

    for (auto lit = it; lit != end(candidates); ++lit) {
      current_combination.push_back(*lit);
      current_sum += *lit;

      _combinationSum(candidates, combinations, current_combination, target, current_sum, lit);

      current_combination.pop_back();
      current_sum -= *lit;
    }
  }

public:
  vector<vector<int>> combinationSum(const vector<int> &candidates, int target) {
    vector<vector<int>> combinations;
    vector<int> current_combination;

    _combinationSum(candidates, combinations, current_combination, target, 0, cbegin(candidates));

    return combinations;
  }
};

int main() {
  cout << Solution{}.combinationSum({2, 3, 6, 7}, 7) << endl; // [[2,2,3],[7]]
  cout << Solution{}.combinationSum({2, 3, 5}, 8) << endl;    // [[2,2,2,2],[2,3,3],[3,5]]
  cout << Solution{}.combinationSum({2}, 1) << endl;          // []
}
