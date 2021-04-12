//
// Created by soapsnake@gmail.com on 10/10/20.
//

#include <MacTypes.h>
#include "ListNode.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        ListNode *firstp = head;
        ListNode *secondp = head;
        bool isCycle = false;

        while (firstp != nullptr && secondp != nullptr) {
            firstp = firstp->next;
            if (secondp->next == nullptr) return nullptr;
            secondp = secondp->next->next;

            //快慢指针相遇表明出现了环路
            if (firstp == secondp) {
                isCycle = true;
                break;
            }
        }

        if (!isCycle) return nullptr;
        firstp = head;
        while (firstp != secondp) {
            firstp = firstp->next;
            secondp = secondp->next;
        }

        return firstp;
    }
};