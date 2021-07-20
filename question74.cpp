//
// Created by soapsnake@gmail.com on 2019-06-25.
//
#include <iostream>
#include "vector"

using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
      if (matrix.empty()) {
          return false;
      }
      int rowMax = matrix.size();
      int colMax = matrix[0].size();

      int row = 0;
      int col = colMax - 1;
      while (row < rowMax && col > 0) {
          if (matrix[row][col] == target) {
              return true;
          } else if (matrix[row][col] > target) {
              col--;
          } else {
              row++;
          }
      }
      return false;
  }
};

int main() {
    cout << "hello world this is question74" << endl;
    Solution solution;
    vector<vector<int>> res;
    cout << solution.searchMatrix(res, 3) << endl;
}
