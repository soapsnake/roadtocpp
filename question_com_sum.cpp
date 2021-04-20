//
// Created by soapsnake@gmail.com on 2/10/20.
//
#include "vector"

//leetcode39
class Solution {
 public:
  std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target) {
      std::sort(candidates.begin(), candidates.end());
      std::vector<std::vector<int>> res;
      std::vector<int> combination;
      combinationSum(candidates, target, res, combination, 0);
      return res;
  }

 private:
  void combinationSum(std::vector<int> &candis, int sum, std::vector<std::vector<int>> &res,
                      std::vector<int> &temp, int start) {
      if (sum == 0) {
          res.push_back(temp);
          return;
      }
      for (int i = start; i < candis.size() && sum >= candis[i]; ++i) {
          temp.push_back(candis[i]);
          combinationSum(candis, sum - candis[i], res, temp, i);
          temp.pop_back();  //弹出最后一个元素 = list.remove(list.size() - 1)(Java)
      }
  }

};