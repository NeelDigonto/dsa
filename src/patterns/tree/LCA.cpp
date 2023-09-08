#include <core/Common.hpp>
#include <core/Tree.hpp>
using namespace std;

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root)
      return nullptr;

    if (root == p || root == q)
      return root;

    auto l = lowestCommonAncestor(root->left, p, q);
    auto r = lowestCommonAncestor(root->right, p, q);

    if (l && r)
      return root;
    if (l)
      return l;
    else
      return r;
  }
};

int main() {

  const auto root1 = BTDeserialize({3, 5, 1, 6, 2, 0, 8, btnull, btnull, 5, 1}); // 3
  const auto root2 = BTDeserialize({3, 5, 1, 6, 2, 0, 8, btnull, btnull, 5, 4}); // 5
  const auto root3 = BTDeserialize({1, 2});                                      // 1

  cout << Solution{}.lowestCommonAncestor(root1, root1->left, root1->right)->val << endl;
  cout << Solution{}.lowestCommonAncestor(root2, root2->left, root2->left->right->right)->val << endl;
  cout << Solution{}.lowestCommonAncestor(root3, root3, root3->left)->val << endl;
}