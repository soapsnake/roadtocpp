//
// Created by soapsnake@gmail.com on 24/9/20.
//
#include "string"

using namespace std;

class Solution {
 public:
  char findTheDifference(string s, string t) {
      char res = 0;
      for (char s : s) {
          res ^= s;
      }
      for (char t : t) {
          res ^= t;
      }
      return res;
  }
};