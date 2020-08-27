#include <iostream>
#include "map"
#include "vector"

using namespace std;   //名称空间编译指令,这个是函数级别的,也可以声明在👆,那么就是全局级别的


class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>> & intervals) {
        map<int, int> hash;
        vector<int> res;
        int n = intervals.size();
        for (int i = 0; i < n; ++i)
            hash[intervals[i].start] = i;
        for (auto in : intervals) {
            auto itr = hash.lower_bound(in.end);
            if (itr == hash.end()) res.push_back(-1);
            else res.push_back(itr->second);
        }
        return res;
    }
};

int main() {
    Solution so;
    cout << so.findRightInterval(NULL) << endl;
    return 0;
}