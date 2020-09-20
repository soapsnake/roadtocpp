//
// Created by soapsnake@gmail.com on 2020/9/17.
//
#include "string"
#include "vector"
using namespace std;

//leetcode1041
class Solution {
public:
    /**
     * 在一个指令序列之后。
        如果机器人能够回到原点，则明显是一个圆圈。
        如果指令结束时，机器人并不面朝北,那么它将在另外一个或三个序列中恢复到初始状态。
     */
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, i = 0;
        vector<vector<int>> d = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
        for (char & ins : instructions)
            if (ins == 'R')
                i = (i + 1) % 4;
            else if (ins == 'L')
                i = (i + 3) % 4;
            else
                x += d[i][0],y += d[i][1];
        return x == 0 && y == 0 || i > 0;
    }
};
