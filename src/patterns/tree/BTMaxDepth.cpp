#include <core/Common.hpp>
#include <core/Tree.hpp>
using namespace std;

class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (!root)
      return 0;

    auto l = maxDepth(root->left);
    auto r = maxDepth(root->right);

    return max(l, r) + 1;
  }
};

int main() {

  cout << Solution{}.maxDepth(BTDeserialize({3, 9, 20, btnull, btnull, 15, 7})) << endl; // 3
  cout << Solution{}.maxDepth(BTDeserialize({1, btnull, 2})) << endl;                    // 2
}