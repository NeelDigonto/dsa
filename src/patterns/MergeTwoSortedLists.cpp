#include <core/Common.hpp>
#include <core/List.hpp>
#include <iostream>

using namespace std;

class Solution {
private:
  void Forward(ListNode *&node) { node = node->next; }

public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (!list1 && !list2)
      return list1;
    if (list1 && !list2)
      return list1;
    if (!list1 && list2)
      return list2;

    ListNode *head = nullptr;

    if (list1->val <= list2->val) {
      head = list1;
      Forward(list1);
    } else {
      head = list2;
      Forward(list2);
    }

    ListNode *tail = head;

    while (list1 && list2) {
      if (list1->val <= list2->val) {
        tail->next = list1;
        Forward(list1);
      } else {
        tail->next = list2;
        Forward(list2);
      }
      Forward(tail);
    }

    if (list1)
      tail->next = list1;
    else if (list2)
      tail->next = list2;

    return head;
  }
};

int main() {
  cout << Solution{}.mergeTwoLists(GetList({1, 2, 3, 4, 5}), GetList({1, 3, 4}))
       << endl;
  cout << Solution{}.mergeTwoLists(GetList({}), GetList({})) << endl;
  cout << Solution{}.mergeTwoLists(GetList({}), GetList({0})) << endl;
}