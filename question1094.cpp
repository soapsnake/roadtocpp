//
// Created by soapsnake@gmail.com on 22/9/20.
//
#include "vector"

using namespace std;

//leetcode1094
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int stops[1001] = {};
        for (auto t : trips) {
            //累计所有上车点上车的总人数
            stops[t[1]] += t[0];

            //累计所有下车点下车的总人数(很可能为负值)
            stops[t[2]] -= t[0];
        }
        for (auto i = 0; capacity >= 0 && i < 1001; ++i) {
            //用汽车总容积减去每个站点上车和下车的总人数,如果上车点,会减去一个正数,如果下车点,会减去一个负数
            capacity -= stops[i];
        }
        //最后看下容积是否还未正
        return capacity >= 0;
    }
};