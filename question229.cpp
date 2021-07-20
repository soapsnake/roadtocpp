//
// Created by soapsnake@gmail.com on 2019-06-10.
//

#include <iostream>
#include "question229.h"

int main() {

    question229 question229;
    vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 2};

    vector<int> res;
    res = question229.majorityElement(nums);

    cout << "size is = " << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
}
