#include "string"
#include <iostream>

using namespace std;

//leetcode470
class Solution {
public:
    int rand10() { 
      int rand40 = 40;
        while (rand40 >= 40) {
            rand40 = (rand7() - 1) * 7 + rand7() - 1;
        }
        return rand40 % 10 + 1;
    }
};

int main() {
    Solution so;
    cout << so.rand10() << endl;
    return 0;
}

