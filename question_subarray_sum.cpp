//
// Created by soapsnake@gmail.com on 4/18/21.
//
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int subarraySum(vector<int> &nums, int k) {
      if (nums.size() == 0) {
          return 0;
      }

      int sumsI = 0, sumsJ = 0, res = 0;
      for (int i = 0; i < nums.size(); ++i) {
          sumsI += nums[i];
          sumsJ = 0;
          for (int j = 0; j <= i; ++j) {
              if (sumsI - sumsJ == k) {
                  res++;
              }
              sumsJ += nums[j];
          }
      }
      return res;
  }

  int subarraySum2(vector<int> &nums, int k) {
      if (nums.size() == 0) {
          return 0;
      }
      int sums = 0, res = 0;
      unordered_map<int, int> map;  //sumsJ -> count
      map[0] = 1;
      for (int i = 0; i < nums.size(); ++i) {
          sums += nums[i];
          if (map.count(sums - k) == 1) {
              res += map[sums - k];
          }
          map[sums]++;
      }
      return res;
  }

  int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
      int count = 0;
      int line = matrix.size();
      int column = matrix[0].size() + 1;
      vector<vector<int>> sum(line, vector<int>(column, 0));

      for (int kI = 0; kI < sum.size(); ++kI) {
          for (int kJ = 0; kJ < sum[0].size(); ++kJ) {
              sum[kI][kJ] = sum[kI][kJ - 1] + matrix[kI][kJ - 1];
          }
      }

      for (int start = 0; start < column; ++start) {
          for (int end = start + 1; end < column; ++end) {
              int sumOfSubMatrix = 0;
              unordered_map<int, int> map;
              map[0] = 1;
              for (int l = 0; l < line; ++l) {
                  sumOfSubMatrix += sum[l][end] - sum[l][start];
                  if (map.count(sumOfSubMatrix - target) == 1) {
                      count += map[sumOfSubMatrix - target];
                  }
                  map[sumOfSubMatrix]++;
              }
          }
      }
      return count;
  }

};