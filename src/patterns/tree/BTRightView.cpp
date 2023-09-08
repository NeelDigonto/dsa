#include <core/Common.hpp>
#include <core/Tree.hpp>
using namespace std;

class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    if (!root)
      return {};

    size_t level{0};
    vector<int> right_view;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      const auto level_depth = q.size();
      right_view.push_back(q.front()->val);

      for (size_t i = 0; i != level_depth; ++i) {
        auto node = q.front();
        q.pop();

        if (node) {
          if (node->right)
            q.push(node->right);

          if (node->left)
            q.push(node->left);
        }
      }
    }

    return right_view;
  }
};

int main() {

  cout << Solution{}.rightSideView(BTDeserialize({1, 2, 3, btnull, 5, btnull, 4})) << endl; // [1,3,4]
  cout << Solution{}.rightSideView(BTDeserialize({1, btnull, 3})) << endl;                  // [1,3]
  cout << Solution{}.rightSideView(BinaryTree::deserialize_t({})) << endl;                  // []
}