#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  int findDuplicate(const vector<int> &nums) {}
};

int main() {
  cout << Solution{}.findDuplicate({1, 3, 4, 2, 2}) << endl;
  cout << Solution{}.findDuplicate({3, 1, 3, 4, 2}) << endl;
}
