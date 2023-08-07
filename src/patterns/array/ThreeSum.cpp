#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
private:
  optional<array<int, 2>> specialTwoSum(const vector<int> &nums) {}

public:
  vector<vector<int>> threeSum(const vector<int> &nums) {}
};

int main() {
  cout << Solution{}.threeSum({-1, 0, 1, 2, -1, -4}) << endl;
  cout << Solution{}.threeSum({0, 1, 1}) << endl;
  cout << Solution{}.threeSum({0, 0, 0}) << endl;
}
