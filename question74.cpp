//
// Created by 刘盾 on 2019-06-25.
//
#include "vector"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
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
