//
// Created by soapsnake@gmail.com on 4/30/21.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {

      vector<int> res(2, -1);
      if (nums.size() == 0) {
          return res;
      }
      int midIndex= binerSearch(nums, target);
      if (midIndex == -1) {
          return res;
      }

      int left = midIndex;
      int right = midIndex;
      res[0] = midIndex;
      res[1] = midIndex;

      while (left-- > 0) {
          if (nums[left] == target) {
              res[0] = left;
          }
      }
      while (right++ < nums.size() - 1) {
          if (nums[right] == target) {
              res[1] = right;
          }
      }
      return res;
  }

  int binerSearch(vector<int> &vec, int target) {
      int left = 0;
      int right = vec.size() - 1;
      while (right >= left) {
          int mid = left + (right - left) / 2;
          if (vec[mid] == target) {
              return mid;
          } else if (vec[mid] > target) {
              right = mid - 1;
          } else {
              left = mid + 1;
          }
      }
      return -1;
  }
};

int main() {
    Solution solution;
    vector<int > nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> res = solution.searchRange(nums, target);
    for (int i = 0; i < res.size(); ++i) {
        std::cout << res[i] << endl;
    }
}