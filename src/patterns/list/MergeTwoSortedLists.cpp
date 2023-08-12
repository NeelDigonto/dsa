#include <core/Common.hpp>
#include <core/List.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
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
};

int main() {
  cout << Solution{}.mergeTwoLists(GetList({1, 2, 3, 4, 5}), GetList({1, 3, 4})) << endl;
  cout << Solution{}.mergeTwoLists(GetList({}), GetList({})) << endl;
  cout << Solution{}.mergeTwoLists(GetList({}), GetList({0})) << endl;
}