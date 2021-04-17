//
// Created by soapsnake@gmail.com on 17/4/21.
//
#include <iostream>
#include "string"
#include "stack"

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stack;
        for (char c : s) {
            if (stack.empty() || stack.top().first != c) {
                stack.push(pair<char, int>(c, 1));
            } else {
                pair<char, int> p = stack.top();
                if (p.second != k - 1) {
                    p.second++;
                } else {
                    stack.pop();
                }
            }
        }
        string res = "";
        while (!stack.empty()) {
            while (stack.top().second-- > 0) {
                res.push_back(stack.top().first);
            }
            stack.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution solution;
    string s = "deeedbbcccbdaa";
    int k = 3;
    cout << solution.removeDuplicates(s, k);
}

