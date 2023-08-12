#include <core/Common.hpp>
#include <iostream>
using namespace std;

class Solution {
private:
  struct IndexDesc {
    int index;
    int w;
  };
  vector<IndexDesc> index_order_;

  size_t current_vidx_ = 0;
  size_t current_count_ = 0;

public:
  Solution(const vector<int> &w) {
    index_order_.reserve(w.size());

    for (int i = 0; i != w.size(); ++i)
      index_order_.emplace_back(IndexDesc{i, w[i]});

    stable_sort(begin(index_order_), end(index_order_),
                [](const IndexDesc &lhs, const IndexDesc &rhs) { return lhs.w > rhs.w; });

    current_vidx_ = 0;
    current_count_ = 0;
  }

  int pickIndex() {
    if (current_count_ == index_order_[current_vidx_].w) {
      current_count_ = 0;
      current_vidx_ = (current_vidx_ + 1) % index_order_.size();
    }

    current_count_++;
    return index_order_[current_vidx_].index;
  }
};

int main() {
  {
    Solution solution({1});
    cout << solution.pickIndex() << endl;
  }
  cout << endl;
  {
    Solution solution({1, 3});
    for (size_t i = 0; i != 4; i++)
      cout << solution.pickIndex() << endl;
  }
  cout << endl;
  {
    Solution solution({188, 927, 949, 95, 151, 659, 405, 906, 481, 363, 728, 839});
    for (size_t i = 0; i != 4; i++)
      cout << solution.pickIndex() << endl;
  }
}
