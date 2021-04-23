//
// Created by soapsnake@gmail.com on 4/23/21.
//
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
 public:
  int leastBricks(vector<vector<int>>& wall) {
        int count = 0;
        unordered_map<int, int> map;

        for (vector<int> &row : wall) {
            int rowTotalLength = 0;
            //最下面一行不计算
                for (int i = 0; i < row.size() - 1; ++i) {
                    rowTotalLength += row[i];
                    ++map[rowTotalLength];
                    count = max(count, map[rowTotalLength]);
                }
        }
      return wall.size() - count;
  }

  int leastBricks2(vector<vector<int>> &wall) {
      unordered_map<int, int> map;
      int count = 0, m = wall.size();
      for (int i = 0; i < wall.size(); i++) {
          for (int j = 0, sum = 0; j < wall[i].size() - 1; j++) {
              count = max(count, ++map[sum += wall[i][j]]);
          }
      }
      return m - count;
  }
};