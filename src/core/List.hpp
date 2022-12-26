#pragma once
#include <core/Common.hpp>
#include <iterator>
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

std::ostream& operator<<(std::ostream& os, ListNode* head) {
  os << "[";

  while (head != nullptr) {
    os << head->val << (head->next != nullptr ? ", " : "");
    head = head->next;
  }

  os << "]" << std::endl;
}

ListNode* GetList(std::initializer_list<int> l) {
  ListNode* head = nullptr;
  size_t n = l.size();

  if (n == 0) return head;
  head = new ListNode(*begin(l));

  ListNode* temp = head;
  for (auto it = std::next(begin(l)); it != std::end(l); ++it) {
    temp->next = new ListNode(*it);
    temp = temp->next;
  }

  return head;
}