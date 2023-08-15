#include <core/Common.hpp>
#include <core/List.hpp>
#include <iostream>
using namespace std;

class Solution {
private:
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

public:
  bool isPalindrome(ListNode *head) {
    size_t size = 0, count = 0;
    ListNode *temp = head;
    while (temp)
      ++size, temp = temp->next;

    if (size & 1)
      size++;
    size /= 2;

    temp = head;
    while (count++ != size)
      temp = temp->next;

    auto reversed = reverseList(temp);

    while (reversed) {
      if (head->val != reversed->val)
        return false;

      head = head->next;
      reversed = reversed->next;
    }

    return true;
  }
};

int main() {
  cout << boolalpha << Solution{}.isPalindrome(GetList({1, 2, 2, 1})) << endl;
  cout << boolalpha << Solution{}.isPalindrome(GetList({1, 2})) << endl;
}
