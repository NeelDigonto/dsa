#include <core/Common.hpp>
#include <core/List.hpp>
#include <iostream>
using namespace std;

class Solution {
private:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {

    ListNode *pre_head = new ListNode(-1);
    ListNode *prev = pre_head;

    while (list1 && list2) {
      if (list1->val <= list2->val) {
        prev->next = list1;
        list1 = list1->next;
      } else {
        prev->next = list2;
        list2 = list2->next;
      }

      prev = prev->next;
    }

    prev->next = list1 == nullptr ? list2 : list1;

    return pre_head->next;
  }

public:
  struct Comparator {
    constexpr bool operator()(ListNode *lhs, ListNode *rhs) { return lhs->val > rhs->val; }
  };

  ListNode *mergeKLists(const vector<ListNode *> &lists) {

    ListNode _pre_head;
    ListNode *pre_head = &_pre_head, *prev = pre_head;

    priority_queue<ListNode *, vector<ListNode *>, Comparator> q;

    for (size_t i = 0; i != lists.size(); i++)
      if (lists[i])
        q.push(lists[i]);

    while (!q.empty()) {
      auto node = q.top();
      q.pop();

      prev->next = node;
      prev = prev->next;

      if (node->next)
        q.push(node->next);
    }

    return pre_head->next;
  }
};

int main() {
  cout << Solution{}.mergeKLists({GetList({1, 4, 5}), GetList({1, 3, 4}), GetList({2, 6})})
       << endl;                                          // [1,1,2,3,4,4,5,6]
  cout << Solution{}.mergeKLists({}) << endl;            // []
  cout << Solution{}.mergeKLists({GetList({})}) << endl; // []
}

/*
class Solution {
private:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {

    ListNode *pre_head = new ListNode(-1);
    ListNode *prev = pre_head;

    while (list1 && list2) {
      if (list1->val <= list2->val) {
        prev->next = list1;
        list1 = list1->next;
      } else {
        prev->next = list2;
        list2 = list2->next;
      }

      prev = prev->next;
    }

    prev->next = list1 == nullptr ? list2 : list1;

    return pre_head->next;
  }

public:
  ListNode *mergeKLists(const vector<ListNode *> &lists) {

    ListNode _pre_head;
    ListNode *pre_head = &_pre_head;

    for (size_t i = 0; i != lists.size(); i++)
      pre_head->next = mergeTwoLists(pre_head->next, lists[i]);

    return pre_head->next;
  }
};
*/