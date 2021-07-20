//
// Created by soapsnake@gmail.com on 27/3/21.
//
#include "vector"
#include "string"

using namespace std;

class Solution {
 public:
  vector<string> wordSubsets(vector<string> &A, vector<string> &B) {
      vector<int> count(26), tmp(26);
      for (string word : B) {
          tmp = counter(word);
          for (int i = 0; i < 26; ++i) {
              count[i] = max(count[i], tmp[i]);
          }
      }
      int i;
      vector<string> res;
      for (string word : A) {
          tmp = counter(word);
          for (i = 0; i < 26; ++i) {
              if (tmp[i] < count[i]) {
                  break;
              }
          }
          if (i == 26) {
              res.push_back(word);
          }
      }
      return res;
  }

  vector<int> counter(string &word) {
      vector<int> res(26);
      for (char c : word) {
          res[c - 'a']++;
      }

      if (true) {

      }
      return res;
  }

};