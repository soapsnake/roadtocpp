//
// Created by soapsnake@gmail.com on 3/19/21.
//
#include "vector"

using namespace std;

//leetcode376, 线性dp
class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    vector<int> upArr(nums.size() ,0);  //到索引i处已上升数组结束的最大子串长度
    vector<int> downArr(nums.size(), 0);  //到索引i处已下降数组结束的最大子串长度
    upArr[0] = 1, downArr[0] = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        //上升时,更新上升数组的最新值
        upArr[i] = downArr[i - 1] + 1;
        downArr[i] = downArr[i - 1];
      } else if (nums[i] < nums[i - 1]) {
        //下降时,更新下降数组的最新值
        downArr[i] = upArr[i - 1] + 1;
        upArr[i] = upArr[i - 1];
      } else {
        //不升不降的情况
        upArr[i] = upArr[i - 1];
        downArr[i] = downArr[i - 1];
      }
    }
    return max(upArr[nums.size() - 1], downArr[nums.size() - 1]);
  }
};