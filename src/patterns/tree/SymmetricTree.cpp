#include <core/Common.hpp>
#include <core/Tree.hpp>

using namespace std;

class Solution {
private:
  bool _isSymmetric(TreeNode *p, TreeNode *q) {
    if (!p && !q)
      return true;

    if (p && q)
      return (p->val == q->val && _isSymmetric(p->left, q->right) && _isSymmetric(p->right, q->left));

    return false;
  }

public:
  bool isSymmetric(TreeNode *root) { return _isSymmetric(root, root); }
};

int main() {

  cout << boolalpha << Solution{}.isSymmetric(BTDeserialize({1, 2, 2, 3, 4, 4, 3})) << endl;           // true
  cout << boolalpha << Solution{}.isSymmetric(BTDeserialize({1, 2, 2, btnull, 3, btnull, 3})) << endl; // false
}