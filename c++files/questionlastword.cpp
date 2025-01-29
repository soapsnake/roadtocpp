//
// Created by soapsnake@gmail.com on 2020/9/15.
//

#include "vector"
#include "string"

using namespace std;

//leetcode58
class Solution {
 public:
  int lengthOfLastWord(string s) {
      int len = 0, tail = s.length() - 1;
      //tail指针指向最后一个不为空字符的字符
      while (tail >= 0 && s[tail] == ' ') {
          tail--;
      }
      //tail继续往左走,直到遇到空字符,意味着一个单词读完了
      while (tail >= 0 && s[tail] != ' ') {
          len++;
          tail--;
      }
      return len;
  }
};