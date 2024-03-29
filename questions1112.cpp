#include <vector>
#include "iostream"
using namespace std;

//leetcode969
class Solution {
 public:
  vector<int> pancakeSort(vector<int> &A) {
      int size = A.size();
      int maxindex = -1, maxnum = INT_MIN;
      vector<int> res;

      while (size > 2) {
          maxindex = -1, maxnum = INT_MIN;
          for (int i = 0; i < size; i++) {
              if (A[i] > maxnum) {
                  maxnum = A[i];
                  maxindex = i;
              }
          }

          res.push_back(maxindex + 1);
          res.push_back(size);
          reverse(A.begin(), A.begin() + maxindex + 1);
          reverse(A.begin(), A.begin() + size);
          size--;
      }
      if (size == 2 && A[0] > A[1]) res.push_back(2);
      return res;
  }
};

int main() {
    cout << "helloworld" << endl;

    return 0;
}