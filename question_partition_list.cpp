//
// Created by soapsnake@gmail.com on 4/15/21.
//

#include "ListNode.h"
class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    if (head == nullptr) {
      return head;
    }
    //思路,搞两个链表,比x小的放链表1,比x大的放链表2,然后把2拼到1的后面

    ListNode *list1Head = new ListNode(0);
    ListNode *list1 = list1Head;
    ListNode *list2Head = new ListNode(0);
    ListNode *list2 = list2Head;
    ListNode *cur = head;
    while (cur != nullptr) {
      if (cur->val < x) {
        list1->next = cur;
        list1 = list1->next;
      } else {
        list2->next = cur;
        list2 = list2->next;
      }
      cur = cur->next;
    }
    list2->next = nullptr;
    list1Head->next = list2Head->next;
    return list1Head->next;

  }
};