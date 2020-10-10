//
// Created by soapsnake@gmail.com on 8/10/20.
//
#include <iostream>
#include "vector"

using namespace std;

class solution {
public:
    //迭代版本二分查找
    int biner_search_iterator(vector<int> &nums, int target) {
        if (nums.size() == 0) {
            return 0;
        }
        int left = 0, right = nums.size() - 1;
        while (right >= left) {
            int mid = left + (right - left) / 2;
            cout << "mid = " << mid << endl;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }

};

int main() {
    solution so;
    vector<int> nums = {5};
    int tar = 5;
    cout << so.biner_search_iterator(nums, tar) << endl;
}

