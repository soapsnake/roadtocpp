#include "vector"
#include "map"

using namespace std;

class Solution {
 public:
  vector<int> majorityElement(vector<int> &nums) {
      //找出来数组中出现n/3次的数字
      //思路1:遍历数组,保存每个数字的出现次数,倒序出现次数,大于等于n/3的数字即为所求
      vector<int> res;
      if (nums.size() == 0) {
          return res;
      }

      int len = nums.size();
      int candi1 = nums[0];
      int candi2 = nums[0];
      int count1 = 0;
      int count2 = 0;
      for (auto i = 0; i < len; i++) {
          if (candi1 == nums[i]) {
              ++count1;
          } else if (candi2 == nums[i]) {
              ++count2;
          } else if (count1 == 0) {
              candi1 == nums[i];
              count1 = 1;
          } else if (count2 == 0) {
              candi2 == nums[i];
              count2 = 1;
          } else {
              --count1;
              --count2;
          }
      }

      count1 = 0;
      count2 = 0;
      for (auto i = 0; i < len; i++) {
          if (nums[i] == candi1) {
              count1++;
          } else if (nums[i] == candi2) {
              count2++;
          }
      }
      o

      if (count1 > len / 3) {
          res.push_back(candi1);
      }
      if (count2 > len / 3) {
          res.push_back(candi2);
      }
      return res;
  }
};