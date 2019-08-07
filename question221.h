//
// Created by soapsnake@gmail.com on 2019-06-06.
//

#ifndef ROADTOCPP_QUESTION221_H
#define ROADTOCPP_QUESTION221_H

#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), sz = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));   //声明一个长度为n, 宽度为m的二维数组
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!i || !j || matrix[i][j] == '0') {  //没有这个判断会报错,好像是数组越界异常了,c++这么弱的
                    dp[i][j] = matrix[i][j] - '0';
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
                sz = max(dp[i][j], sz);
            }
        }
        return sz * sz;
    }
};

#endif //ROADTOCPP_QUESTION221_H
