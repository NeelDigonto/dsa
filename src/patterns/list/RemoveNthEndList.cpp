#include <core/Common.hpp>
#include <core/List.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    size_t size = 0;

    ListNode *pre_head = new ListNode(-1);
    pre_head->next = head;
    ListNode *prev = pre_head;

    while ((prev = prev->next))
      ++size;

    prev = pre_head;
    while (size-- - n != 0)
      prev = prev->next;

    auto redundant_node = prev->next;
    prev->next = prev->next->next;
    delete redundant_node;

    return pre_head->next;
  }
};

int main() {
  cout << Solution{}.removeNthFromEnd(GetList({1, 2, 3, 4, 5}), 2) << endl;
  cout << Solution{}.removeNthFromEnd(GetList({1}), 1) << endl;
  cout << Solution{}.removeNthFromEnd(GetList({1, 2}), 1) << endl;
}