#include <core/Common.hpp>
#include <core/Tree.hpp>
using namespace std;

class Solution {
private:
  struct SubTreeRes {
    int height;
    int max_diameter;
  };
  SubTreeRes _diameterOfBinaryTree(TreeNode *root) {

    if (!root)
      return {0, 0};

    const auto l = _diameterOfBinaryTree(root->left);
    const auto r = _diameterOfBinaryTree(root->right);

    SubTreeRes res;
    res.height = max(l.height, r.height) + 1;
    res.max_diameter = l.height + r.height;

    if (root->left)
      res.max_diameter++;

    if (root->right)
      res.max_diameter++;

    return res;
  }

public:
  int diameterOfBinaryTree(TreeNode *root) { return _diameterOfBinaryTree(root).max_diameter; }
};

int main() {

  auto res1 = Solution{}.diameterOfBinaryTree(BinaryTree::deserialize_t({1, 2, 3, 4, 5}));
  auto res2 = Solution{}.diameterOfBinaryTree(BinaryTree::deserialize_t({1, 2}));

  // 4,-7,-3,null,null,-9,-3,9,-7,-4,null,6,null,-6,-6,null,null,0,6,5,null,9,null,null,-1,-4,null,null,null,-2

  cout << boolalpha << res1 << endl;
  cout << boolalpha << res2 << endl;
}