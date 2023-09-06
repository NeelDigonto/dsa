#include <core/Common.hpp>
#include <core/Tree.hpp>
using namespace std;

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (!root)
      return {{}};

    vector<vector<int>> res;
    size_t i = 0, level = 0;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      auto node = q.front();
      q.pop();

      res[level].push_back(node->val);

      if (node->val) {
        q.push(node->left);
        q.push(node->right);
      }

      i++;

      if (i == static_cast<int>(pow(2, level)))
        level++;
    }

    return res;
  }
};

int main() {

  cout << Solution{}.levelOrder(BinaryTree::deserialize_t({3, 9, 20, nullopt, nullopt, 15, 7})) << endl;
  cout << Solution{}.levelOrder(BinaryTree::deserialize_t({1})) << endl;
  cout << Solution{}.levelOrder(BinaryTree::deserialize_t({})) << endl;
}
