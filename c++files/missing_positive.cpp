//
// Created by soapsnake@gmail.com on 30/9/20.
//
#include "vector"

using namespace std;

class Solution {
 public:
  int firstMissingPositive(vector<int> &nums) {
      int n = nums.size();
      for (int i = 0; i < n; ++i)
          while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
              swap(nums[i], nums[nums[i] - 1]);
      for (int i = 0; i < n; ++i)
          if (nums[i] != i + 1)
              return i + 1;
      return n + 1;
  }
};
