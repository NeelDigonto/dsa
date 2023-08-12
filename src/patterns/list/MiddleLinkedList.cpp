#include <core/Common.hpp>
#include <core/List.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    size_t count = 0, adv_count = 0;

    ListNode *temp = head;
    while (temp) {
      ++count;
      temp = temp->next;
    }

    adv_count = count / 2;

    for (size_t i = 0; i != adv_count; ++i, head = head->next)
      ;

    return head;
  }
};

int main() {
  cout << Solution{}.middleNode(GetList({1, 2, 3, 4, 5})) << endl;
  cout << Solution{}.middleNode(GetList({1, 2})) << endl;
  cout << Solution{}.middleNode(GetList({})) << endl;
}