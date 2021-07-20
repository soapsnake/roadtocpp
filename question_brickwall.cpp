//
// Created by soapsnake@gmail.com on 4/23/21.
//
#include <vector>
#include <unordered_map>
using namespace std;

//leetcode wall bricks
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

};