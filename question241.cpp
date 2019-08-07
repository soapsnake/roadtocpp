//
// Created by soapsnake@gmail.com on 2019-06-16.
//

#include <string>
#include "question241.h"
#include "vector"
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        if (input.empty())
            return res;
        int len = input.length();
        for (int i = 0; i < len; ++i) {
            char temp = input[i];
            vector<int> left;
            vector<int> right;
            if (temp == '+' || temp == '-' || temp == '*') {
                int tempInt = 0;
                left = diffWaysToCompute(input.substr(0, i));
                right = diffWaysToCompute(input.substr(i+1));
                for (int j : left) {
                    for(int k : right) {
                        if (temp == '+')
                            res.push_back(j + k);
                        else if (temp == '-')
                            res.push_back(j - k);
                        else
                            res.push_back(j * k);
                    }
                }
            }
        }
        if (res.size() == 0) {
            res.push_back(stoi(input));
        }
        return res;
    }
};
