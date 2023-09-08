#include <core/Common.hpp>
#include <core/Tree.hpp>
using namespace std;

class Solution {
private:
  struct SubTreeRes {
    int16_t height;
    int16_t max_diameter;
  };

  SubTreeRes _diameterOfBinaryTree(TreeNode *root) {

    if (!root)
      return {0, 0};

    const auto l = _diameterOfBinaryTree(root->left);
    const auto r = _diameterOfBinaryTree(root->right);

    SubTreeRes res;
    res.height = max(l.height, r.height) + 1;
    res.max_diameter = max(static_cast<int16_t>(l.height + r.height), res.max_diameter);

    return res;
  }

public:
  int diameterOfBinaryTree(TreeNode *root) { return _diameterOfBinaryTree(root).max_diameter; }
};

int main() {

  // cout << Solution{}.diameterOfBinaryTree(BTDeserialize({1, 2, 3, 4, 5})) << endl; // 3
  cout << Solution{}.diameterOfBinaryTree(BTDeserialize({1, 2})) << endl; // 1
  //  cout << Solution{}.diameterOfBinaryTree(BinaryTree::deserialize_t(
  //              {4,       -7, -3,      nullopt, nullopt, -9,      -3,      9,       -7,      -4,
  //               nullopt, 6,  nullopt, -6,      -6,      nullopt, nullopt, 0,       6,       5,
  //               nullopt, 9,  nullopt, nullopt, -1,      -4,      nullopt, nullopt, nullopt, -2}))
  //       << endl; // 8
}