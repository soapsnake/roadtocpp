//
// Created by soapsnake@gmail.com on 11/4/21.
//

#include "question_longest_path.h"
#include "vector"

using namespace std;

//leetcode329
class Solution {
public:
    vector<vector<int>> dirs = {{0,  1},
                                {1,  0},
                                {0,  -1},
                                {-1, 0}};

    int dfs(vector<vector<int>> &matrix, int i, int j, int m, int n, std::vector<std::vector<int>> &cache) {
        if (cache[i][j] != 0) {
            return cache[i][j];
        }
        int max = 1;
        for (std::vector<int> dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (x <0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j]) {
                continue;
            }
            int len = 1 + dfs(matrix, x, y, m, n, cache);
            max = std::max(max, len);
        }
        cache[i][j] = max;  //这个解法最精髓的就是这个cache,即可用来防止走重复路,也可用来暂存上一步结果
        return max;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> cache(m, vector<int>(n, 0));
        int max = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int len = dfs(matrix, i, j, m, n, cache);
                max = std::max(max, len);
            }
        }
        return max;
    }
};

int main() {
}