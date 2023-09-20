#include <core/Common.hpp>
#include <core/Tree.hpp>
using namespace std;

class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q)
      return true; // both null

    if (p && q)
      return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));

    return false;
  }
};

int main() {

  cout << boolalpha << Solution{}.isSameTree(BTDeserialize({1, 2, 3}), BTDeserialize({1, 2, 3})) << endl;   // true
  cout << boolalpha << Solution{}.isSameTree(BTDeserialize({1, 2}), BTDeserialize({1, btnull, 2})) << endl; // false
  cout << boolalpha << Solution{}.isSameTree(BTDeserialize({1, 2, 1}), BTDeserialize({1, 1, 2})) << endl;   // false
}