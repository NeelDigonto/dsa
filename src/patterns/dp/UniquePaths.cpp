#include <core/Common.hpp>
#include <iostream>

using namespace std;

class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<int> upper(n, 1);
    int left = 1;

    for (int i = 1; i != m; ++i) {
      left = 1;

      for (int j = 1; j != n; ++j)
        upper[j] = left = left + upper[j];
    }

    return left;
  }
};

int main() {
  cout << Solution{}.uniquePaths(3, 7) << endl;
  cout << Solution{}.uniquePaths(3, 2) << endl;
}
