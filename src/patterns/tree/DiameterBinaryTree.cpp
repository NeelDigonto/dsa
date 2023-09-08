#include <core/Common.hpp>
#include <core/Tree.hpp>
using namespace std;

class Solution {
private:
  int max_diameter{0};

  int _diameterOfBinaryTree(TreeNode *root) {
    if (!root)
      return 0;

    auto lh = _diameterOfBinaryTree(root->left);
    auto rh = _diameterOfBinaryTree(root->right);

    max_diameter = max(lh + rh, max_diameter);

    return max(lh, rh) + 1;
  }

public:
  int diameterOfBinaryTree(TreeNode *root) {
    _diameterOfBinaryTree(root);
    return max_diameter;
  }
};

int main() {

  cout << Solution{}.diameterOfBinaryTree(BTDeserialize({1, 2, 3, 4, 5})) << endl; // 3
  cout << Solution{}.diameterOfBinaryTree(BTDeserialize({1, 2})) << endl;          // 1
  cout << Solution{}.diameterOfBinaryTree(BinaryTree::deserialize_t(
              {4,       -7, -3,      nullopt, nullopt, -9,      -3,      9,       -7,      -4,
               nullopt, 6,  nullopt, -6,      -6,      nullopt, nullopt, 0,       6,       5,
               nullopt, 9,  nullopt, nullopt, -1,      -4,      nullopt, nullopt, nullopt, -2}))
       << endl; // 8
}