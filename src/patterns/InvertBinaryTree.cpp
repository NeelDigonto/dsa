#include <core/Common.hpp>
#include <core/Tree.hpp>
using namespace std;

class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (!root)
      return root;

    const auto temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
  }
};

int main() {

  auto res1 =
      Solution{}.invertTree(BinaryTree::deserialize_t({4, 2, 7, 1, 3, 6, 9}));
  auto res2 = Solution{}.invertTree(BinaryTree::deserialize_t({2, 1, 3}));
  auto res3 = Solution{}.invertTree(BinaryTree::deserialize_t({}));

  cout << BinaryTree::serialize_t(res1) << endl;
  cout << BinaryTree::serialize_t(res2) << endl;
  cout << BinaryTree::serialize_t(res3) << endl;
}