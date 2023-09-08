#include <core/Common.hpp>
#include <core/Tree.hpp>
using namespace std;

class Codec {
private:
  static constexpr auto nullv = numeric_limits<int16_t>::max();

  inline vector<int16_t> serialize_t(const TreeNode *const root) const noexcept {
    vector<int16_t> level_order;
    queue<const TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      auto node = q.front();

      if (node) {
        level_order.push_back(node->val);
        q.push(node->left);
        q.push(node->right);
      } else
        level_order.push_back(nullv);

      q.pop();
    }

    return level_order;
  }

  inline TreeNode *deserialize_t(const int16_t *buffer, size_t node_count) const noexcept {
    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(buffer[0]);
    q.push(root);

    for (size_t i = 1; i != node_count;) {
      auto node = q.front();
      q.pop();

      if (buffer[i] != nullv)
        node->left = new TreeNode(buffer[i]), q.push(node->left);
      i++;

      if (i == node_count)
        break;

      if (buffer[i] != nullv)
        node->right = new TreeNode(buffer[i]), q.push(node->right);
      i++;
    }

    return root;
  }

public:
  inline string serialize(TreeNode *root) const noexcept {
    auto v = Codec::serialize_t(root);

    const size_t valid_range_end =
        distance(find_if_not(crbegin(v), crend(v), [](const auto &val) { return val == nullv; }), crend(v));

    string s_view(valid_range_end * sizeof(int16_t), {});
    auto buffer = reinterpret_cast<int16_t *>(s_view.data());

    copy_n(v.data(), valid_range_end, buffer);

    return s_view;
  }

  inline TreeNode *deserialize(string data) const noexcept {
    if (data.size() == 0)
      return nullptr;

    size_t node_count = data.size() / sizeof(int16_t);
    auto *buffer = reinterpret_cast<int16_t *>(data.data());

    return deserialize_t(buffer, node_count);
  }
};

int main() {
  cout << Codec{}.deserialize(Codec{}.serialize(BTDeserialize({1, 2, 3, btnull, btnull, 4, 5}))) << endl;
  cout << Codec{}.deserialize(Codec{}.serialize(BTDeserialize({}))) << endl;
  cout << Codec{}.deserialize(Codec{}.serialize(BTDeserialize({1, 2}))) << endl;
}