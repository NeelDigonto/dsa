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

  cout << boolalpha << Solution{}.isBalanced(BTDeserialize({3, 9, 20, btnull, btnull, 15, 7})) << endl;
  cout << boolalpha << Solution{}.isBalanced(BTDeserialize({1, 2, 2, 3, 3, btnull, btnull, 4, 4})) << endl;
  cout << boolalpha << Solution{}.isBalanced(BTDeserialize({})) << endl;
}