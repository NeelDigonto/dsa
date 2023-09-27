#pragma once
#include <core/Common.hpp>
#include <iterator>

// Definition for a Node.
class Node {
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
};

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