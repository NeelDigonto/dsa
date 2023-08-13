#include <core/Common.hpp>
#include <core/List.hpp>
#include <iostream>
using namespace std;

class Solution {
private:
  ListNode *_sortList(ListNode *head) {
    if (!head->next)
      return head;
  }

public:
  ListNode *sortList(ListNode *head) {
    if (!head)
      return head;

    return _sortList(head);
  }
};

int main() {
  cout << Solution{}.sortList(GetList({4, 2, 1, 3})) << endl;
  cout << Solution{}.sortList(GetList({-1, 5, 3, 4, 0})) << endl;
  cout << Solution{}.sortList(GetList({})) << endl;
}
