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
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};