//
// Created by soapsnake@gmail.com on 2019-06-10.
//

#ifndef ROADTOCPP_QUESTION229_H
#define ROADTOCPP_QUESTION229_H


#include "vector"
using namespace std;

class question229 {

public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        if (nums.empty()) {
            return res;
        }
        int len = nums.size();
        int candi1 = nums[0], candi2 = nums[0], count1 = 0, count2 = 0;

        for (int i = 0; i < len; ++i) {
            if (nums[i] == candi1) {
                count1++;
            }
            else if (nums[i] == candi2) {
                count2++;
            }
            else if (count1 == 0) {
                candi1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0) {
                candi2 = nums[i];
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;

        for (int i = 0; i < len; ++i) {
            if (nums[i] == candi1) {
                count1++;
            } else if (nums[i] == candi2) {
                count2++;
            }
        }
        if (count1 > len / 3) {
            res.push_back(candi1);
        }
        if (count2 > len / 3) {
            res.push_back(candi2);
        }
        return res;
    }
};


#endif //ROADTOCPP_QUESTION229_H
