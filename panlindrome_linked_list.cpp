//
// Created by soapsnake@gmail.com on 4/2/21.
//

#include "ListNode.h"

//检测回文链表,Java没写出来,用c++到是写出来了
class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    if (head == nullptr) {
      return false;
    }

    ListNode *reverseHead = reverseList(head); //生成一个新的翻转链表但是不破坏原链表

    while (head != nullptr) {
      if (reverseHead->val != head->val) {
        return false;
      }
      head = head->next;
      reverseHead = reverseHead->next;
    }
    return true;
  }

 private:
  ListNode *reverseList(ListNode *p_node) {
    ListNode *cur = p_node;
    ListNode *newHead = nullptr;
    while (cur != nullptr) {
      ListNode *next = cur->next;
      auto *temp = new ListNode(0);
      temp->val = cur->val;
      temp->next = newHead;
      newHead = temp;
      cur = next;
    }
    return newHead;
  }
};