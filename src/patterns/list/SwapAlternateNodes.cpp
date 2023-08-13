#include <core/Common.hpp>
#include <core/List.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode *pre_head = new ListNode(-1);
    pre_head->next = head;

    ListNode *prev = pre_head;

    while ((head) && (head->next)) {
      ListNode *first_node = head;
      ListNode *second_node = head->next;

      prev->next = second_node;
      first_node->next = second_node->next;
      second_node->next = first_node;

      prev = first_node;
      head = prev->next;
    }

    return pre_head->next;
  }
};

int main() {
  cout << Solution{}.swapPairs(GetList({1, 2, 3, 4})) << endl;
  cout << Solution{}.swapPairs(GetList({})) << endl;
  cout << Solution{}.swapPairs(GetList({1})) << endl;
}