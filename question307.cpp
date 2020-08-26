//
// Created by soapsnake@gmail.com on 2019-07-04.
//
#include <iostream>
#include <unordered_set>
#include "string"
#include "queue"

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> travel(begin(days), end(days));
        int dp[366] = {};
        for (int i = 1; i < 366; ++i) {
            if (travel.find(i) == travel.end()) dp[i] = dp[i - 1];
            else dp[i] = min({ dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]});
        }
        return dp[365];
    }
};

int main() {
    string num = "112358";
    Solution solution;
//    cout << "res = " << boolalpha << solution.mincostTickets(num) << endl;
//    cout << "add(123, 456) = " << solution.mincostTickets("123", "456") << endl;
    cout << "stoi = " << stoi("0") << endl;
}

