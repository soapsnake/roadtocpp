//
// Created by soapsnake@gmail.com on 4/21/21.
//
#include <vector>
#include <stack>
#include "hearders/Node.h"

//N叉树先根遍历,递归 vs 迭代, 迭代要快很多
class Solution {
 public:
  //递归版本
  std::vector<int> preorder(Node* root) {
      if (root == nullptr) {
          return res;
      }
      res.push_back(root->val);
      for (Node *p : root->children) {
          preorder(p);
      }
      return res;
  }
  std::vector<int> res;

  //迭代版本
  std::vector<int> preorder2(Node* root) {
      std::vector<int> res1;
      if (root == nullptr) {
          return res1;
      }
      std::stack<Node*> stack;
      stack.push(root);
      while (!stack.empty()) {
          Node* cur = stack.top();
          stack.pop();
          res1.push_back(cur->val);
          //唯一要注意的是这里要倒着push,这样最左边的子节点会最先被弹出
          for (int i = cur->children.size() - 1; i >= 0; --i) {
              if (cur->children[i] != nullptr) {
                  stack.push(cur->children[i]);
              }
          }
      }
      return res1;

  }
};