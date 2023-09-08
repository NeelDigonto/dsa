#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <optional>
#include <queue>
#include <stack>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinaryTree {
public:
  using arr_rep_t = std::vector<std::optional<int>>;

  template <typename Callback> static void lvlorderTraverse(const TreeNode *_root, Callback _fn) {
    if (_root == nullptr) {
      _fn(std::optional<int>{std::nullopt});
      return;
    }

    std::vector<const TreeNode *> lvl1, lvl2;
    std::vector<const TreeNode *> *current_lvl{&lvl1}, *next_lvl{&lvl2};

    current_lvl->push_back(_root);

    while (!current_lvl->empty()) {
      // generate next node
      for (auto &current_node : *current_lvl) {
        if (current_node) {
          next_lvl->push_back(current_node->left);
          next_lvl->push_back(current_node->right);

          _fn(std::optional<int>{current_node->val});
        } else {
          _fn(std::optional<int>{std::nullopt});
        }
      }

      // now set current_lvl to next_lvl
      current_lvl->clear();
      std::swap(current_lvl, next_lvl);
    }
  }

  [[nodiscard]] static arr_rep_t serialize_t(TreeNode *_root) {
    arr_rep_t _arr_rep;

    lvlorderTraverse(_root, [&_arr_rep](const std::optional<int> &_res) { _arr_rep.push_back(_res); });

    // auto rit = prev(end(_arr_rep));
    // while (rit != begin(_arr_rep) && *rit == std::nullopt) advance(rit, -1);

    // return arr_rep_t(begin(_arr_rep), rit);
    return _arr_rep;
  }

  // Encodes a tree to a single string.
  [[nodiscard]] static std::string serialize(TreeNode *root) {
    if (!root)
      return std::string{};

    arr_rep_t _arr_rep = serialize_t(root);

    const char *buffer_data = reinterpret_cast<const char *>(_arr_rep.data());
    const std::size_t buffer_size = _arr_rep.size() * sizeof(arr_rep_t::value_type);

    std::string buffer(buffer_data, buffer_size);

    return buffer;
  }

  [[nodiscard]] static TreeNode *deserialize_t(arr_rep_t _arr_rep) {
    if (_arr_rep.empty())
      return nullptr;

    std::queue<TreeNode *> queqe;
    arr_rep_t::const_iterator pos = std::begin(_arr_rep);

    TreeNode *root = new TreeNode(pos++->value());
    queqe.push(root);

    while (!queqe.empty()) {
      auto node = queqe.front();

      node->left = (pos != _arr_rep.end() && pos->has_value()) ? new TreeNode(pos->value()) : nullptr;
      pos++;
      node->right = (pos != _arr_rep.end() && pos->has_value()) ? new TreeNode(pos->value()) : nullptr;
      pos++;

      if (node->left != nullptr)
        queqe.push(node->left);
      if (node->right != nullptr)
        queqe.push(node->right);

      queqe.pop();
    }

    return root;
  }

  // Decodes a string rep of a tree
  [[nodiscard]] static TreeNode *deserialize(std::string data) {
    if (data.size() < sizeof(arr_rep_t::value_type))
      return nullptr;

    arr_rep_t _arr_rep;
    auto buffer_t = reinterpret_cast<std::optional<int> *>(data.data());
    _arr_rep.assign(buffer_t, buffer_t + data.size() / sizeof(arr_rep_t::value_type));

    return deserialize_t(_arr_rep);
  }

  static void printLvlOrderTraverse(TreeNode *_root) {
    lvlorderTraverse(_root, [](std::optional<int> _elem) {
      std::cout << (_elem.has_value() ? std::to_string(_elem.value()) : "null") << ", ";
    });
  }
};

static constexpr auto btnull = std::numeric_limits<int>::max();

inline std::vector<int> BTSerialize_t(const TreeNode *const root) noexcept {

  std::vector<int> v;
  std::queue<const TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    auto node = q.front();

    if (node) {
      v.push_back(node->val);
      q.push(node->left);
      q.push(node->right);
    } else
      v.push_back(btnull);

    q.pop();
  }

  const size_t valid_range_end = std::distance(
      std::find_if_not(std::crbegin(v), std::crend(v), [](const auto &val) { return val == btnull; }), std::crend(v));

  return std::vector<int>(std::begin(v), std::next(begin(v), valid_range_end));
}

// inline std::string BTSerialize(TreeNode *root) noexcept {
//
//   auto v = BTSerialize_t(root);
//
//   const size_t valid_range_end = distance(
//       find_if_not(std::crbegin(v), std::crend(v), [](const auto &val) { return val == btnull; }), std::crend(v));
//
//   std::string s_view(valid_range_end * sizeof(int), {});
//   auto buffer = reinterpret_cast<int *>(s_view.data());
//
//   std::copy_n(v.data(), valid_range_end, buffer);
//
//   return s_view;
// }

inline TreeNode *BTDeserialize_t(const int *buffer, size_t node_count) noexcept {
  std::queue<TreeNode *> q;
  TreeNode *root = new TreeNode(buffer[0]);
  q.push(root);

  for (size_t i = 1; i != node_count;) {
    auto node = q.front();
    q.pop();

    if (buffer[i] != btnull)
      node->left = new TreeNode(buffer[i]), q.push(node->left);
    i++;

    if (i == node_count)
      break;

    if (buffer[i] != btnull)
      node->right = new TreeNode(buffer[i]), q.push(node->right);
    i++;
  }

  return root;
}

inline TreeNode *BTDeserialize(const std::vector<int> &data) noexcept {
  if (data.size() == 0)
    return nullptr;

  size_t node_count = data.size();
  auto *buffer = reinterpret_cast<const int *>(data.data());

  return BTDeserialize_t(buffer, node_count);
}

std::ostream &operator<<(std::ostream &os, const TreeNode *root) {
  auto v = BTSerialize_t(root);

  os << "[ ";
  for (auto it = v.cbegin(); it != v.cend(); ++it)
    if (*it != btnull)
      os << *it << " ";
    else
      os << "null ";
  os << "]";

  return os;
}
