//
// Created by soapsnake@gmail.com on 15/9/20.
//
#include "vector"

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size(), pre = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;  //cur取得是两者的最大值
        }
        return cur;
    }
};