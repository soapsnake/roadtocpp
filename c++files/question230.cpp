//
// Created by soapsnake@gmail.com on 2019-06-10.
//

#include "hearders/TreeNode.h"
#include "stack"

using namespace std;

class Solution {
 public:
  int kthSmallest(TreeNode *root, int k) {
      stack<TreeNode *> stack;  //指针泛型
      TreeNode *p = root;
      while (p || !stack.empty()) {
          while (p) {
              stack.push(p);
              p = p->left;
          }
          p = stack.top();
          if (--k == 0)
              return p->val;
          stack.pop();
          p = p->right;
      }
      return 0;  //必须要有返回值
  }
};

int main() {

}