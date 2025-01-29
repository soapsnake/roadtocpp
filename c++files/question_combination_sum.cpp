//
// Created by soapsnake@gmail.com on 4/20/21.
//

#include <vector>
#include <iostream>

class Solution {
 public:
  int sumOf(std::vector<int> &vector) {
      int total = 0;
      for (int kI = 0; kI < vector.size(); ++kI) {
          total += vector[kI];
      }
      return total;
  }

  void helper(std::vector<int> &nums, int target, std::vector<int> &temp, int start) {
      if (sumOf(temp) == target) {
          res++;
          return;
      }
      if (sumOf(temp) > target) {
          return;
      }
      for (int kI = start; kI < nums.size(); ++kI) {
          temp.push_back(nums[kI]);
          helper(nums, target, temp, start);
          temp.pop_back();
      }
  }

  int res = 0;
  int combinationSum4(std::vector<int> &nums, int target) {
      if (nums.size() == 0) {
          return 0;
      }
      std::vector<int> temp;
      helper(nums, target, temp, 0);
      return res;
  }

  int combinationSum5(std::vector<int> &nums, int target) {
      //自底向上dp
      std::vector<unsigned int> dp(target + 1, 0);
      dp[0] = 1;
      for (int i = 0; i < dp.size(); ++i) {
          for (int j = 0; j < nums.size(); ++j) {
              if (i - nums[j] >= 0) {
                  dp[i] = dp[i] + dp[i - nums[j]];
              }
          }
      }
      return dp[target];
  }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 2, 3};
    int target = 4;
    std::cout << solution.combinationSum4(nums, target);
}