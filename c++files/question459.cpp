//
// Created by soapsnake@gmail.com on 3/9/20.
//

#include "string"
#include "vector"

using namespace std;

//leetcode459
class Solution {
 public:
  bool repeatedSubstringPattern(string s) {
      int i = 1, j = 0, n = s.size();
      vector<int> dp(n + 1, 0);
      while (i < n) {
          if (s[i] == s[j]) dp[++i] = ++j;
          else if (j == 0) i++;
          else j = dp[j];
      }
      return dp[n] && dp[n] % (n - dp[n]) == 0;
  }
};


