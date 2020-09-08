//
// Created by soapsnake@gmail.com on 8/9/20.
//
#include "hearders/TreeNode.h"

using namespace std;

class Solution {
public:
    int sumRootToLeaf(TreeNode *root) {
       return helper(root, 0);
    }

    int helper(TreeNode *root, int val) {
        if (!root) return 0;
        val = (val * 2 + root->val);
        return root->left == root->right ? val : helper(root->left, val) + helper(root->right, val);
    }
};

