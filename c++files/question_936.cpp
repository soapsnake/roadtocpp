//
// Created by soapsnake@gmail.com on 4/1/21.
//


#include "vector"
#include "string"
#include "iostream"

using namespace std;

//leetcode936
class solution {
 private:
  bool canReplace(string &target, string &stamp, int start) {
      for (int kI = 0; kI < stamp.size(); ++kI) {
          if (target[kI + start] != '*' && target[kI + start] != stamp[kI]) {
              return false;
          }
      }
      return true;
  }

 private:
  int doReplace(string &target, int start, int size, int stars) {  //发现传参带不带&结果差别很大,不知道为什么
      for (int kI = 0; kI < size; ++kI) {
          if (target[kI + start] != '*') {
              target[kI + start] = '*';
              stars++;
          }
      }
      return stars;
  }

 public:
  vector<int> movesToStamp(string stamp, string target) {
      vector<int> res;
      vector<bool> visited(target.size(), false);
      int stars = 0;
      while (stars < target.size()) {
          bool doneReplace = false;
          for (int kI = 0; kI <= target.size() - stamp.size(); ++kI) {
              if (!visited[kI] && canReplace(target, stamp, kI)) {
                  stars = doReplace(target, kI, stamp.size(), stars);
                  doneReplace = true;
                  visited[kI] = true;
                  res.push_back(kI);
                  if (stars == target.size()) {
                      break;
                  }
              }
          }
          if (!doneReplace) {
              return vector<int>{};
          }
      }

      reverse(res.begin(), res.end());
      return res;
  }
};

int main() {
    cout << "this is question_936" << endl;

}