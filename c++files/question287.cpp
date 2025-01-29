//
// Created by soapsnake@gmail.com on 2019-06-25.
//


#include "vector"
using namespace std;

class Solution {
 public:
  int findDuplicate(vector<int> &nums) {
      if (nums.empty()) {
          return -1;
      }

      int fast = nums[0];
      int slow = nums[0];
      do {
          fast = nums[nums[fast]];
          slow = nums[slow];
      } while (fast != slow);

      int ptr1 = fast;
      int ptr2 = nums[0];
      while (ptr1 != ptr2) {
          ptr1 = nums[ptr1];
          ptr2 = nums[ptr2];
      }
      return ptr1;
  }
};