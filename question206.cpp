//
// Created by soapsnake@gmail.com on 2019-05-28.
//

#include <vector>      //别忘了这个,不然编译不通过,不能使用[]取数组元素
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0, j = 0, total = 0, len = INT_MAX;  //c++中的int最大值,c++中不推荐使用min为变量名称,因为是内置函数名称
        while (j < nums.size()) {
            total += nums[j++];
            while (total >= s) {
                len = min(len, j - i);   //内置函数min,类似java中的Math.min()
                total -= nums[i++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};

int main() {

}
