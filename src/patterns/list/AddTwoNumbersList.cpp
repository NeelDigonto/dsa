#include <core/Common.hpp>
#include <core/List.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    ListNode *pre_head = new ListNode(-1), *prev = pre_head;

    while (l1 || l2 || carry) {
      if (l1) {
        carry += l1->val;
        l1 = l1->next;
      }

      if (l2) {
        carry += l2->val;
        l2 = l2->next;
      }

      prev->next = new ListNode(carry % 10);
      carry /= 10;
      prev = prev->next;
    }

    return pre_head->next;
  }
};

int main() {
  cout << Solution{}.addTwoNumbers(GetList({2, 4, 3}), GetList({5, 6, 4})) << endl;
  cout << Solution{}.addTwoNumbers(GetList({0}), GetList({0})) << endl;
  cout << Solution{}.addTwoNumbers(GetList({9, 9, 9, 9, 9, 9, 9}), GetList({9, 9, 9, 9})) << endl;
}
