//
// Created by soapsnake@gmail.com on 3/10/21.
//

#include "hearders/TreeNode.h"

class Solution {
 public:
  void dfs(TreeNode *root, int v, int d, int curDepth) {
      if (root == nullptr) {
          return;
      }
      if (curDepth < d - 1) {
          dfs(root->left, v, d, curDepth + 1);
          dfs(root->right, v, d, curDepth + 1);
      } else {
          TreeNode *tmp_left = root->left;
          TreeNode *tmp_right = root->right;

          root->left = new TreeNode(v);
          root->left->left = tmp_left;

          root->right = new TreeNode(v);
          root->right->right = tmp_right;
      }
  }

  TreeNode *addOneRow(TreeNode *root, int v, int d) {
      if (root == nullptr) {
          return root;
      }
      if (d == 1) {
          auto *newRoot = new TreeNode(v);
          newRoot->left = root;
          return newRoot;
      }
      dfs(root, v, d, 1);
      return root;
  }
};