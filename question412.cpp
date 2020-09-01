#include "vector"
#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for(int i = 1;i <= n; i++) {
            res[i - 1] = to_string(i);
        }
        for(int i = 2;i < n; i += 3) {
            res[i] = "Fizz";
        }
        for(int i = 4;i < n; i += 5) {
            res[i] = "Buzz";
        }
        for(int i = 14;i < n; i += 15) {
            res[i] = "FizzBuzz";
        }
        return res;
    }
};

int main() {
    Solution so;
    vector<string> im = so.fizzBuzz(15);
    for (size_t i = 0; i < im.size() ; i++){
      cout << "res = " <<  im[i] << endl;
    }
    return 0;
}