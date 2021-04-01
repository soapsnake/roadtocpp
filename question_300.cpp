//
// Created by soapsnake@gmail.com on 3/31/21.
//
#include "vector"
using namespace std;

class solution {
 public:
  int maxLen(vector<int> &nums) {

    if (nums.size() <= 1) {
      return nums.size();
    }

    vector<int> dp(nums.size(), 0);
    int maxLen = 1;
    dp[0] = 1;
    for (int kI = 0; kI < nums.size(); ++kI) {
      int maxVal = 0;
      for (int kJ = 0; kJ < kI; ++kJ) {
        if (nums[kJ] < nums[kI]) {
          maxVal = max(dp[kI], dp[kJ]);
        }
        dp[kI] = maxVal + 1;
      }
      maxLen = max(dp[kI], maxLen);
    }
    return maxLen;
  }
};