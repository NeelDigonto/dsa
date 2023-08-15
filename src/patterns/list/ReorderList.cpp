#include <core/Common.hpp>
#include <core/List.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  void reorderList(ListNode *head) {
    if (!head)
      return;

    // find the middle of linked list [Problem 876]
    // in 1->2->3->4->5->6 find 4
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // reverse the second part of the list [Problem 206]
    // convert 1->2->3->4->5->6 into 1->2->3->4 and 6->5->4
    // reverse the second half in-place
    ListNode *prev = nullptr, *curr = slow, *tmp;
    while (curr) {
      tmp = curr->next;

      curr->next = prev;
      prev = curr;
      curr = tmp;
    }

    // merge two sorted linked lists [Problem 21]
    // merge 1->2->3->4 and 6->5->4 into 1->6->2->5->3->4
    ListNode *first = head, *second = prev;
    while (second->next) {
      tmp = first->next;
      first->next = second;
      first = tmp;

      tmp = second->next;
      second->next = first;
      second = tmp;
    }
  }
};

int main() {
  {
    auto list = GetList({1, 2, 3, 4});
    Solution{}.reorderList(list);
    cout << list << endl;
  }
  {
    auto list = GetList({1, 2, 3, 4, 5});
    Solution{}.reorderList(list);
    cout << list << endl;
  }
}