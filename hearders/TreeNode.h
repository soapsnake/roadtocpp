//
// Created by soapsnake@gmail.com on 2019-06-10.
//


#include <cstdio>

#ifndef ROADTOCPP_TREENODE_H
#define ROADTOCPP_TREENODE_H

#endif //ROADTOCPP_TREENODE_H

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
  TreeNode() : val(0), left(nullptr), right(nullptr) {};
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};

};