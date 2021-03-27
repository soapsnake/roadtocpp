//
// Created by soapsnake@gmail.com on 3/26/21.
//
#include <stack>
#include "vector"
#include "iostream"

class Solution {
 public:
  std::vector<int> nextGreatElement(std::vector<int> &prices) {
    std::vector<int> res(prices.size(), 0);
    std::stack<int> stack;
    for (int kI = prices.size() - 1; kI >= 0; --kI) {
      while(!stack.empty() && prices[kI] >= stack.top()) {
        stack.pop();
      }
      res[kI] = stack.empty() ? -1 : stack.top();
      stack.push(prices[kI]);
    }
    return res;
  }
};

int main() {
  std::cout << "hello" << std::endl;

  Solution solution;
  std::vector<int> nums = {2,3,6,5,6,7};
  std::vector<int> res = solution.nextGreatElement(nums);

  for (int re : res) {
    std::cout << re << std::endl;
  }
}