#pragma once
#include <core/Common.hpp>
#include <iterator>

// Definition for a Node.
/* class Node {
public:
  int val;
  std::vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = std::vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node *>();
  }
  Node(int _val, std::vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
}; */

/* std::ostream &operator<<(std::ostream &os, ListNode *head) {
  os << "[";

  while (head != nullptr) {
    os << head->val << (head->next != nullptr ? ", " : "");
    head = head->next;
  }

  os << "]" << std::endl;

  return os;
}

ListNode *GetList(std::initializer_list<int> l) {
  ListNode *head = nullptr;
  size_t n = l.size();

  if (n == 0)
    return head;
  head = new ListNode(*begin(l));

  ListNode *temp = head;
  for (auto it = std::next(begin(l)); it != std::end(l); ++it) {
    temp->next = new ListNode(*it);
    temp = temp->next;
  }

  return head;
} */

// must be unsigned integer
template <typename T> class DSU {
private:
  T size_;
  T component_count_;
  std::vector<T> parents_;
  std::vector<T> component_sizes_;

public:
  DSU() = delete;
  DSU(T _size) : size_{_size}, component_count_{_size} {
    parents_.resize(_size);
    component_sizes_.resize(_size);

    for (T idx = 0; idx != _size; ++idx) {
      parents_[idx] = idx;
      component_sizes_[idx] = 1;
    }
  }

  T find(T _node) {
    T root = _node;

    while (root != parents_[root])
      root = parents_[root];

    while (_node != root) {
      T next = parents_[_node];
      parents_[_node] = root;
      _node = next;
    }

    return root;
  }

  bool isConnected(T _node1, T _node2) { return find(_node1) == find(_node2); }

  T getComponentSize(T _node) { return component_sizes_[find(_node)]; }

  T size() const { return size_; }

  T getComponentCount() const { return component_count_; }

  void connect(T _node1, T _node2) {
    if (isConnected(_node1, _node2))
      return;

    T root1 = find(_node1);
    T root2 = find(_node2);

    if (component_sizes_[root1] < component_sizes_[root2]) {
      component_sizes_[root2] += component_sizes_[root1];
      parents_[root1] = root2;
      component_sizes_[root1] = 0;
    } else {
      component_sizes_[root1] += component_sizes_[root2];
      parents_[root2] = root1;
      component_sizes_[root2] = 0;
    }

    --component_count_;
  }
};