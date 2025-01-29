//
// Created by soapsnake@gmail.com on 4/12/21.
//
#include "hearders/TreeNode.h"
#include "vector"
#include "queue"
using namespace std;

//leetcode 二叉树最深叶节点的和
class Solution {
 public:
  int deepestLeavesSum(TreeNode *root) {
      if (root == nullptr) {
          return 0;
      }
      vector<vector<TreeNode *>> vec;
      queue<TreeNode *> queue;
      queue.push(root);
      while (!queue.empty()) {
          vector<TreeNode *> rows;
          while (!queue.empty()) {
              TreeNode *cur = queue.front();
              if (cur != nullptr) {
                  rows.push_back(cur);
              }
              queue.pop();
          }
          vec.push_back(rows);  //一行入队

          for (TreeNode *node : rows) {
              if (node->left != nullptr) {
                  queue.push(node->left);
              }
              if (node->right != nullptr) {
                  queue.push(node->right);
              }
          }
      }
      vector<TreeNode *> last = vec[vec.size() - 1];
      int res = 0;
      for (TreeNode *node: last) {
          res += node->val;
      }
      return res;
  }
};