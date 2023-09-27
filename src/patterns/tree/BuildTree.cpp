#include <core/Common.hpp>
#include <core/Tree.hpp>
using namespace std;

class Solution {
private:
  using It = vector<int>::const_iterator;

  TreeNode *_buildTree(const unordered_map<int, It> &cache, It &preorder_it, It _begin, It _end) {
    if (_begin == _end)
      return nullptr;

    TreeNode *root = new TreeNode(*(preorder_it++));
    root->left = _buildTree(cache, preorder_it, _begin, cache.find(root->val)->second);
    root->right = _buildTree(cache, preorder_it, cache.find(root->val)->second + 1, _end);

    return root;
  }

public:
  TreeNode *buildTree(const vector<int> &preorder, const vector<int> &inorder) {
    unordered_map<int, It> cache;
    for (size_t i = 0; i != inorder.size(); ++i)
      cache[inorder[i]] = next(begin(inorder), i);

    It preorder_it = begin(preorder);
    return _buildTree(cache, preorder_it, begin(inorder), end(inorder));
  }
};

int main() {

  cout << Solution{}.buildTree({3, 9, 20, 15, 7}, {9, 3, 15, 20, 7}) << endl; //[3,9,20,null,null,15,7]
  cout << Solution{}.buildTree({-1}, {-1}) << endl;                           //[-1]
}
