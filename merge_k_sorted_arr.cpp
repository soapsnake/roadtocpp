//
// Created by soapsnake@gmail.com on 2020/10/10.
//
#include <iostream>
#include "vector"

using namespace std;

class solution {
 public:
  vector<int> merge_two_arr(vector<int> &l, vector<int> &r) {
      int total = l.size() + r.size();
      vector<int> res(total, 0);  //没有这个初始化填充0下边进行res[resPointer]时会报错
      int leftPointer = 0;
      int rightPointer = 0;
      int resPointer = 0;
      for (; resPointer < total; ++resPointer) {
          if (leftPointer >= l.size()) {
              res[resPointer] = r[rightPointer++];
          } else if (rightPointer >= r.size()) {
              res[resPointer] = l[leftPointer++];
          } else {
              if (l[leftPointer] >= r[rightPointer]) {
                  res[resPointer] = r[rightPointer++];
              } else {
                  res[resPointer] = l[leftPointer++];
              }
          }
      }
      return res;
  }

  vector<int> helper(vector<vector<int>> &nums, int left, int right) {
      if (left == right) {
          return nums[left];
      }
      if (left == right - 1) {
          return merge_two_arr(nums[left], nums[right]);
      }
      int mid = left + (right - left) / 2;
      vector<int> leftArr = helper(nums, left, mid);
      vector<int> rightArr = helper(nums, mid + 1, right);
      return merge_two_arr(leftArr, rightArr);
  }

//nums都是有序的数组,要求把他们合并成一个有序的数组
  vector<int> merge_sorted_arr(vector<vector<int>> &nums) {
      if (nums.size() == 0) return nums[0];
      int len = nums.size();
      return helper(nums, 0, len - 1);
  }
};

int main() {
    solution so;
    vector<vector<int>> arr = {{2, 5, 8}, {1, 3, 4}, {100, 102}};
    vector<int> res = so.merge_sorted_arr(arr);
    for (int re : res) {
        cout << re << ' ';
    }
}
