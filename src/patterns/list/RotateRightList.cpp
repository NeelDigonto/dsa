#include <core/Common.hpp>
#include <core/List.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head || !head->next)
      return head;

    ListNode *last = nullptr, *temp = head;
    size_t size = 1, count = 0;
    while (temp->next)
      size++, temp = temp->next;
    temp->next = head;

    temp = head, k = k % size;
    while (count++ != size - k - 1)
      temp = temp->next;

    auto new_head = temp->next;
    temp->next = nullptr;

    return new_head;
  }
};

int main() {
  cout << boolalpha << Solution{}.rotateRight(GetList({1, 2, 3, 4, 5}), 2) << endl;
  cout << boolalpha << Solution{}.rotateRight(GetList({0, 1, 2}), 4) << endl;
}
