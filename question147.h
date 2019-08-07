//
// Created by soapsnake@gmail.com on 2019-06-12.
//

#ifndef ROADTOCPP_QUESTION147_H
#define ROADTOCPP_QUESTION147_H

#include "ListNode.h"

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head)
            return head;
        ListNode* helper = new ListNode(0);
        ListNode* cur = head;
        ListNode* pre = helper;
        ListNode* next = nullptr;
        while (cur) {
            next = cur->next;   //保存next的值
            while (pre->next && pre->next->val < cur->val) {
                pre = pre->next;
            }
            cur->next = pre->next;
            pre->next = cur;   //防止链表断裂;
            pre = helper;
            cur = next;
        }
        return helper->next;
    }
};

#endif //ROADTOCPP_QUESTION147_H
