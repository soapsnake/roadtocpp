//
// Created by soapsnake@gmail.com on 2020/9/1.
//
#include "string"
#include "vector"
#include "iostream"

using namespace std;

//leetcode949
class Solution {
public:
    string largestTimeFromDigits(vector<int> &A) {
        sort(begin(A), end(A), greater<int>());
        do {
            if ((A[0] < 2 || (A[0] == 2 && A[1] < 4)) && A[2] < 6)
                return to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
        } while (prev_permutation(begin(A), end(A)));
        return "";
    }
};

int main() {
    Solution so;
    vector<int> a = {1, 2, 3, 4};
    cout << so.largestTimeFromDigits(a) << endl;
}