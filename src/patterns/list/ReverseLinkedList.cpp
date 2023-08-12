#include <core/Common.hpp>
#include <core/List.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *prev_node = nullptr;
    ListNode *curr_node = head;

    while (curr_node) {
      ListNode *next_node = curr_node->next;
      curr_node->next = prev_node;
      prev_node = curr_node;
      curr_node = next_node;
    }

    return prev_node;
  }
};

int main() {
  cout << Solution{}.reverseList(GetList({1, 2, 3, 4, 5})) << endl;
  cout << Solution{}.reverseList(GetList({1, 2})) << endl;
  cout << Solution{}.reverseList(GetList({})) << endl;
}