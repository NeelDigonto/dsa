#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  string largestNumber(const vector<int> &nums) {
    vector<string> str_nums;
    str_nums.reserve(nums.size());

    for (auto num : nums)
      str_nums.emplace_back(move(to_string(num)));

    sort(begin(str_nums), end(str_nums), [](const string &a, const string &b) {
      const string v1 = a + b;
      const string v2 = b + a;
      return v1 > v2;
    });

    if (str_nums[0] == "0")
      return "0";

    string largest_number = "";
    for (auto &str_num : str_nums)
      largest_number += str_num;

    return largest_number;
  }
};

int main() {
  cout << Solution{}.largestNumber({10, 2}) << endl;
  cout << Solution{}.largestNumber({3, 30, 34, 5, 9}) << endl;
  cout << Solution{}.largestNumber({0, 0}) << endl;
}
