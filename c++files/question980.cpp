//
// Created by soapsnake@gmail.com on 20/9/20.
//
#include "vector"

using namespace std;

/**
 * 1 represents the starting square.  There is exactly one starting square.
    2 represents the ending square.  There is exactly one ending square.
    0 represents empty squares we can walk over.
    -1 represents obstacles that we cannot walk over.
 */
// leetcode980
class Solution {
 public:
  int dfs(vector<vector<int>> &vector, int i, int j, int cur, int total) {
      if (i >= vector.size() || i < 0 || j >= vector[0].size() || j < 0 || vector[i][j] == -1) {
          return 0;
      }
      if (vector[i][j] == 2) {
          //the problem says our path should go through every empty cell.
          // In other words, a valid path should have exactly [total] steps.
          // So, we check whether [cur] == [total] when we reached the end to see if we need to count the path.
          return cur == total ? 1 : 0;
      }
      //markij as obstacle can prevent infinite cycle
      vector[i][j] = -1;
      int paths = dfs(vector, i + 1, j, cur + 1, total)
          + dfs(vector, i - 1, j, cur + 1, total)
          + dfs(vector, i, j + 1, cur + 1, total)
          + dfs(vector, i, j - 1, cur + 1, total);
      vector[i][j] = 0;
      return paths;
  }

  int uniquePathsIII(vector<vector<int>> &grid) {
      auto i_start = 0, j_start = 0, total_step = 0;
      for (int i = 0; i < grid.size(); ++i) {
          for (int j = 0; j < grid[0].size(); ++j) {
              if (grid[i][j] == 1) {
                  i_start = i;
                  j_start = j;
              }
              if (grid[i][j] != -1) {
                  total_step++;
              }
          }
      }
      return dfs(grid, i_start, j_start, 1, total_step);
  }
};