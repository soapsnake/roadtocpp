//
// Created by soapsnake@gmail.com on 4/22/21.
//
#include <vector>
#include <iostream>

//leetcode 三角形矩阵从上到下最小路径和
using namespace std;
class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
      if (triangle.empty()) {
          return 0;
      }
      //思路,自底向上dp
      for (auto i = triangle.size() - 2; i >= 0; --i) {
          for (auto j = 0; j < triangle[i].size(); ++j) {
              triangle[i][j] = triangle[i][j] + min(triangle[i + 1][j], triangle[i + 1][j + 1]);
          }
      }
      return triangle[0][0];
  }
};