#include <core/Common.hpp>
#include <core/Tree.hpp>
using namespace std;

class Solution {
private:
  struct SubTreeRes {
    bool is_balanced;
    int height;
  };

  SubTreeRes _isBalanced(TreeNode *root) {

    if (root == nullptr)
      return {true, 0};

    auto l = _isBalanced(root->left);
    auto r = _isBalanced(root->right);

    const bool are_children_balanced = l.is_balanced && r.is_balanced;
    const int height_diff = abs(l.height - r.height);

    SubTreeRes res;
    res.height = max(l.height, r.height) + 1;
    res.is_balanced = are_children_balanced && (height_diff <= 1);

    return res;
  }

public:
  bool isBalanced(TreeNode *root) { return _isBalanced(root).is_balanced; }
};

int main() {

  auto res1 = Solution{}.isBalanced(BinaryTree::deserialize_t({3, 9, 20, nullopt, nullopt, 15, 7}));
  auto res2 = Solution{}.isBalanced(BinaryTree::deserialize_t({1, 2, 2, 3, 3, nullopt, nullopt, 4, 4}));
  auto res3 = Solution{}.isBalanced(BinaryTree::deserialize_t({}));

  cout << boolalpha << res1 << endl;
  cout << boolalpha << res2 << endl;
  cout << boolalpha << res3 << endl;
}