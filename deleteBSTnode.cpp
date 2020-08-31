//
// Created by soapsnake@gmail.com on 2020/8/31.
//


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include "hearders/TreeNode.h"
#include "iostream"
using namespace std;

//leetcode450
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        //二叉平衡树节点删除
        if (!root) return nullptr;  //如果节点为空,那么返回空
        if (root->val == key) {   //结构体使用->来访问成员变量,如果是class,就和java一样了
            //如果节点就是要删除的节点
            if (!root->right) {
                //如果节点没有右子节点
                TreeNode* left = root->left;
                //那么直接返回其左孩子节点并且删掉该节点即可
                delete root;
                return left;
            } else {
                //如果有右孩子节点
                TreeNode* right = root->right;
                while (right->left)
                    //遍历到达左叶子几点
                    right = right->left;
                swap(root->val, right->val);
            }
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};


int main() {
    cout << "hello world! 11111111" << endl;
}
