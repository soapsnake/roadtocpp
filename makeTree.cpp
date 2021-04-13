//
// Created by soapsnake@gmail.com on 2019-10-29.
//

#include <iostream>
#include <utility>
#include "vector"

/**
 * 必须完成的题目:
 * 创建一棵树,树的层数随机,树的子节点数目随机,随机函数rand()已经提供
 * 要求:1. rand()要定边界
 *     2. 不允许使用std模板函数
 */
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
      val = _val;
      children = std::move(_children);
    }
};

class Solution {
public:
     Node makeTree() {
        int layer = rand();
        Node root;
        root.val = rand();
        root.children =  makeChildrens2(1, layer);
        return root;
    }

     vector<Node*> makeChildrens2(int cur, int layer) {
       vector<Node *> res;
         return res;
     }

     vector<Node*> makeChildrens(int cur, int layer) {
        vector<Node*> vector;
        if (cur >= layer) {
            return vector;
        }

        int num = rand();
        for (int i = 0; i < num; ++i) {
            Node *node = new Node;
            node->val = rand();
            node->children = makeChildrens(cur + 1, layer);
            vector.push_back(node);
        }
        return vector;
    }
};


int main() {
    Solution solution;
    solution.makeTree();
}