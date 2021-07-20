#include <iostream>
#include "map"
#include "vector"

using namespace std;   //名称空间编译指令,这个是函数级别的,也可以声明在👆,那么就是全局级别的

//leetcode436
class Solution {
 public:
  vector<int> findRightInterval(vector<vector<int>> &intervals) {
      vector<int> ans(intervals.size());
      map<int, int> m;
      for (int i = 0; i < intervals.size(); i++)
          m[intervals[i][0]] = i;
      for (int i = 0; i < intervals.size(); i++)
          ans[i] = m.lower_bound(intervals[i][1]) != end(m) ? m.lower_bound(intervals[i][1])->second : -1;
      return ans;
  }
};