//
// Created by soapsnake@gmail.com on 3/9/21.
//
#include <iostream>
#include "vector"

using namespace std;
class Solution {
public:
    //leetcode 565
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<bool> visited(n, false);
        for (int x : nums) {
            int cnt = 0;
            while (!visited[x]) {
                cnt += 1;
                visited[x] = true;
                x = nums[x];
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {5,4,0,3,1,6,2};
    cout << solution.arrayNesting(nums) << endl;


}
