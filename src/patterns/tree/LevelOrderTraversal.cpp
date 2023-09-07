#include <core/Common.hpp>
#include <core/Tree.hpp>
using namespace std;

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (!root)
      return {};

    vector<vector<int>> levels;
    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty()) {
      levels.emplace_back(vector<int>{});

      size_t level_breadth = q.size();
      for (size_t i = 0; i != level_breadth; ++i) {
        auto node = q.front();
        q.pop();

        if (node) {
          levels[levels.size() - 1].push_back(node->val);

          if (node->left)
            q.push(node->left);
          if (node->right)
            q.push(node->right);
        }
      }
    }

    return levels;
  }
};

int main() {

  cout << Solution{}.levelOrder(BinaryTree::deserialize_t({3, 9, 20, nullopt, nullopt, 15, 7})) << endl;
  cout << Solution{}.levelOrder(BinaryTree::deserialize_t({1})) << endl;
  cout << Solution{}.levelOrder(BinaryTree::deserialize_t({})) << endl;
  cout << Solution{}.levelOrder(BinaryTree::deserialize_t({1, 2, nullopt, 3, nullopt, 4, nullopt, 5})) << endl;
}
