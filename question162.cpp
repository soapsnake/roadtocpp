//
// Created by 刘盾 on 2019-05-19.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        //我们需要保证的循环不变性是 nums[left - 1] < nums[left] && nums[right] > nums[right + 1];
        //如果满足这个条件,那么left就是我们要找的元素
        int left = 0;
        int size = nums.size();
        int right = size - 1;
        while (right > left) {
            int mid = left + (right - left) /2;
            if (nums[mid] < nums[mid + 1])
                left = mid + 1;
            else
                right = mid;    //mid > = mid + 1
        }
        return left;
    }
};

int main() {
    Solution solution;
    vector<int> vector1;
    cout << "here is the res = " << solution.findPeakElement(vector1) << endl;
}

