#include <core/Common.hpp>
#include <core/Tree.hpp>

using namespace std;

class Solution {
private:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q)
      return true; // both null

    if (p && q)
      return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));

    return false;
  }

public:
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (!root && subRoot)
      return false;
    //
    return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }
};

int main() {

  cout << boolalpha << Solution{}.isSubtree(BTDeserialize({3, 4, 5, 1, 2}), BTDeserialize({4, 1, 2})) << endl; // true
  cout << boolalpha
       << Solution{}.isSubtree(BTDeserialize({3, 4, 5, 1, 2, btnull, btnull, btnull, btnull, 0}),
                               BTDeserialize({4, 1, 2}))
       << endl; // false
  cout << boolalpha
       << Solution{}.isSubtree(BTDeserialize({1, btnull, 1, btnull, 1, btnull, 1, btnull, 1, btnull, 1, btnull,
                                              1, btnull, 1, btnull, 1, btnull, 1, btnull, 1, 2}),
                               BTDeserialize({1, btnull, 1, btnull, 1, btnull, 1, btnull, 1, btnull, 1, 2}))
       << endl; // true
}