//
// Created by soapsnake@gmail.com on 2019-06-12.
//

#ifndef ROADTOCPP_QUESTION236_H
#define ROADTOCPP_QUESTION236_H


#include "hearders/TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q || !root)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (!left)
            return right;
        if (!right)
            return left;
        else
            return root;
    }
};
#endif //ROADTOCPP_QUESTION236_H
