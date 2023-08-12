#include <core/Common.hpp>
#include <core/List.hpp>
#include <iostream>
using namespace std;

class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *sp = head, *fp = head;

    while (fp && fp->next) {
      sp = sp->next;
      fp = fp->next->next;

      if (sp == fp)
        return true;
    }

    return false;
  }
};

int main() {
  {
    ListNode *list = GetList({3, 2, 0, -4});
    list->next->next->next->next = list->next;
    cout << boolalpha << Solution{}.hasCycle(list) << endl;
  }

  {
    ListNode *list = GetList({1, 2});
    list->next->next = list;
    cout << boolalpha << Solution{}.hasCycle(list) << endl;
  }

  {
    ListNode *list = GetList({1});
    cout << boolalpha << Solution{}.hasCycle(list) << endl;
  }
}