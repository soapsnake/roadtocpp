//
// Created by soapsnake@gmail.com on 13/9/20.
//
#include "vector"
using namespace std;

//leeccode57
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int index = 0;

        //左半部分
        //这个while的作用是把intervals中左半部分未和newInterval重叠的部分直接放进res,这一部分不需要进行任何操作
        while (index < intervals.size() && intervals[index][1] < newInterval[0]) {
            res.push_back(intervals[index++]);
        }

        //中间部分,注意了到这里时index值已经很大了
        //重新确定遮盖部分的最大长度,判定的方法很简单,直接看左边界最小能到多少,右侧看最大能到多少,不用再担心是否有不重叠(为啥?)
        while (index < intervals.size() && intervals[index][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[index][0]);
            newInterval[1] = max(newInterval[1], intervals[index][1]);
            index++;
        }
        //newInterval的值已经被重写
        res.push_back(newInterval);

        //右半部分
        //这个while的作用同第一个while,不赘述
        while (index < intervals.size()) {
            res.push_back(intervals[index++]);
        }
        return res;
    }
};


