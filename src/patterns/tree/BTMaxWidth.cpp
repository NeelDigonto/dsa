#include <core/Common.hpp>
#include <core/Tree.hpp>

using namespace std;

class Solution {
public:
  int widthOfBinaryTree(TreeNode *root) {
    if (!root)
      return 0;

    size_t max_width = 0;
    queue<pair<TreeNode *, size_t>> q;
    q.push({root, 0});

    while (!q.empty()) {
      size_t node_count = q.size();
      std::pair<TreeNode *, size_t> first_node = q.front(), node{};

      for (size_t i = 0; i != node_count; ++i) {
        node = q.front();
        q.pop();

        if (node.first->left)
          q.push({node.first->left, 2 * node.second});
        if (node.first->right)
          q.push({node.first->right, 2 * node.second + 1});
      }

      max_width = max(max_width, node.second - first_node.second + 1);
    }

    return max_width;
  }
};

int main() {

  cout << Solution{}.widthOfBinaryTree(BTDeserialize({1, 3, 2, 5, 3, btnull, 9})) << endl;                    // 4
  cout << Solution{}.widthOfBinaryTree(BTDeserialize({1, 3, 2, 5, btnull, btnull, 9, 6, btnull, 7})) << endl; // 7
  cout << Solution{}.widthOfBinaryTree(BTDeserialize({1, 3, 2, 5})) << endl;                                  // 2
}