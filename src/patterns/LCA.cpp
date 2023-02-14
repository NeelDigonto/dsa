#include <core/Common.hpp>
#include <core/Tree.hpp>
using namespace std;

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root->val > p->val && root->val > q->val)
      return lowestCommonAncestor(root->left, p, q);
    if (root->val < p->val && root->val < q->val)
      return lowestCommonAncestor(root->right, p, q);
    return root;
  }
};

int main() {

  const auto root1 = BinaryTree::deserialize_t({6, 2, 8, 0, 4, 7, 9, nullopt, nullopt, 3, 5});
  const auto root2 = BinaryTree::deserialize_t({6, 2, 8, 0, 4, 7, 9, nullopt, nullopt, 3, 5});
  const auto root3 = BinaryTree::deserialize_t({2, 1});

  cout << Solution{}.lowestCommonAncestor(root1, root1->left, root1->right)->val << endl;
  cout << Solution{}.lowestCommonAncestor(root2, root2->left, root2->left->right)->val << endl;
  cout << Solution{}.lowestCommonAncestor(root3, root3, root3->left)->val << endl;
}