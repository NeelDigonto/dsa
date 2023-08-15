#include <core/Common.hpp>
#include <core/List.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next)
      return head;

    ListNode *mid = getMid(head);
    ListNode *left = sortList(head);
    ListNode *right = sortList(mid);
    return merge(left, right);
  }

  ListNode *merge(ListNode *list1, ListNode *list2) {
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

  ListNode *getMid(ListNode *head) {
    size_t size = 0;
    ListNode *temp = head;
    while (temp)
      ++size, temp = temp->next;
    size /= 2;

    while (size-- != 1)
      head = head->next;

    temp = head->next;
    head->next = nullptr;
    return temp;
  }
};

int main() {
  cout << Solution{}.sortList(GetList({4, 2, 1, 3})) << endl;
  cout << Solution{}.sortList(GetList({-1, 5, 3, 4, 0})) << endl;
  cout << Solution{}.sortList(GetList({})) << endl;
}
