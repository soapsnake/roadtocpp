//
// Created by 刘盾 on 2019-07-04.
//
#include <iostream>
#include "string"

using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        for (int i = 1; i <= num.size() / 2; i++) {
            for (int j = 1; j <= (num.size() - i) / 2; j++) {
                if (check(num.substr(0, i), num.substr(i, j), num.substr(i + j))) return true;
            }
        }
        return false;
    }

    string add(string n, string m) {
        string res;
        int i = n.size() - 1, j = m.size() - 1, carry = 0;
        while (i >= 0 || j >= 0) {
            int sum = carry + (i >= 0 ? (n[i--] - '0') : 0) + (j >= 0 ? (m[j--] - '0') : 0);
            res.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        if (carry) res.push_back(carry + '0');
        cout << "before = " << res << endl;
        reverse(res.begin(), res.end());
        return res;
    }

    bool check(string num1, string num2, string num) {
        if ((num1.size() > 1 && num1[0] == '0') ||
            (num2.size() > 1 && num2[0] == '0'))
            return false;
        string sum = add(num1, num2);
        if (num == sum)
            return true;
        if (num.size() <= sum.size() || sum.compare(num.substr(0, sum.size())) != 0)
            return false;
        else return check(num2, sum, num.substr(sum.size()));
    }
};

int main() {


    string num = "112358";
    Solution solution;
    cout << "res = " << boolalpha << solution.isAdditiveNumber(num) << endl;

    cout << "add(123, 456) = " << solution.add("123", "456") << endl;

    cout << "stoi = " << stoi("0") << endl;


}

