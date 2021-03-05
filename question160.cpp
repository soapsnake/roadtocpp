//
// Created by soapsnake@gmail.com on 3/5/21.
//

#include "ListNode.h"
#include "iostream"

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    std::cout << "can heree!!!!" << std::endl;

    if(headA == nullptr || headB == nullptr) {
      return nullptr;
    }

    ListNode *A = headA;
    ListNode *B = headB;

    while (A != B) {
      A = A == nullptr ? headB : A->next;
      B = B == nullptr ? headA : B->next;
    }
    return A;
  }
};

int main() {
  std::cout << "heeloc" << std::endl;

  auto *solution = new Solution();  //new 创建对象时,对象要声明成指针
  ListNode *a = nullptr;
  ListNode *b = nullptr;
  solution->getIntersectionNode(a, b);
  delete solution;
}