#include <core/Common.hpp>
#include <core/List.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  ListNode *oddEvenList(ListNode *head) {
    if (!head)
      return head;

    ListNode *odd = head, *even = head->next, *even_head = even;

    while (even && even->next) {
      odd->next = odd->next->next;
      even->next = even->next->next;

      odd = odd->next;
      even = even->next;
    }

    odd->next = even_head;

    return head;
  }
};

int main() {
  cout << Solution{}.oddEvenList(GetList({1, 2, 3, 4, 5})) << endl;
  cout << Solution{}.oddEvenList(GetList({2, 1, 3, 5, 6, 4, 7})) << endl;
  cout << Solution{}.oddEvenList(GetList({1, 2, 3, 4, 5, 6, 7, 8})) << endl;
  cout << Solution{}.oddEvenList(GetList({})) << endl;
}
