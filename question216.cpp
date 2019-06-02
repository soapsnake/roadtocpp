//
// Created by 刘盾 on 2019-06-02.
//

#include <iostream>
#include "vector"

using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> res;
        vector<int> tmp;
        backtrace(res, tmp, nums, k, 0, n);
        return res;
    }

    void backtrace(vector<vector<int>> & res, vector<int> tmp, vector<int> nums, int k, int start, int n) {
        if (tmp.size() == k && n == 0) {
            res.push_back(tmp);
            return;
        }
        for (int i = start; i < nums.size() ; ++i) {
            tmp.push_back(nums[i]);
            backtrace(res, tmp, nums, k, i + 1, n - nums[i]);
            tmp.pop_back();
        }
    }
};


int main() {
        Solution solution;
        int k = 3;
        int n = 9;
}

