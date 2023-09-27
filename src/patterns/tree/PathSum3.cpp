#include <core/Common.hpp>
#include <core/Tree.hpp>

using namespace std;

class Solution {
private:
  void _pathSum(TreeNode *root, vector<vector<int>> &res, vector<int> &path, int targetSum) {
    if (!root)
      return;

    path.push_back(root->val);
    if (!root->left && !root->right && root->val == targetSum)
      res.push_back(path);

    _pathSum(root->left, res, path, targetSum - root->val);
    _pathSum(root->right, res, path, targetSum - root->val);

    path.pop_back();
  }

public:
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    vector<vector<int>> res;
    vector<int> path;

    _pathSum(root, res, path, targetSum);
    return res;
  }
};

int main() {

  cout << Solution{}.pathSum(BTDeserialize({10, 5, -3, 3, 2, btnull, 11, 3, -2, btnull, 1}), 8) << endl;           // 3
  cout << Solution{}.pathSum(BTDeserialize({5, 4, 8, 11, btnull, 13, 4, 7, 2, btnull, btnull, 5, 1}), 22) << endl; // 3
}