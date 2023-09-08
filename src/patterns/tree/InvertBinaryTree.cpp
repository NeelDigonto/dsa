#include <core/Common.hpp>
#include <core/Tree.hpp>
using namespace std;

class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr)
      return root;

    auto temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
  }
};

int main() {

  cout << Solution{}.invertTree(BTDeserialize({4, 2, 7, 1, 3, 6, 9})) << endl;
  cout << Solution{}.invertTree(BTDeserialize({2, 1, 3})) << endl;
  cout << Solution{}.invertTree(BTDeserialize({})) << endl;
}