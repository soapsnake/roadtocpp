//
// Created by soapsnake@gmail.com on 2/24/21.
//
#include "iostream"
#include "vector"

using namespace std;

//leetcode240
class solution {
 public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int row = 0;
    int col = matrix[0].size() - 1;
    while (row < matrix.size() && col >= 0) {
      if (matrix[row][col] == target) {
        return true;
      } else if (matrix[row][col] > target) {
        --col;
      } else {
        ++row;
      }
    }
    return false;
  }
};

int main() {
  cout << "hello" << endl;
}