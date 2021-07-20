//
// Created by soapsnake@gmail.com on 2019-05-17.
//
#include <iostream>
#include <unordered_map>
#include "vector"

using namespace std;   //名称空间编译指令,这个是函数级别的,也可以声明在👆,那么就是全局级别的

class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
      cout << "findRepeatedDnaSequences" << s << endl;  //<<符号实际上是运算符的重载,它也有按位操作的意思,这里则是把字符串赋给输出流
      unordered_map<size_t, int> MP;
      hash<string> hash_fn;   //这个的含义不是定义一个变量,而是引入了std:hash函数
      vector<string> ret;

      for (int i = 0; i < int(s.size()) - 9; ++i)
          if (MP[hash_fn(s.substr(i, 10))]++ == 1)   //关键是搞明白这个是什么意思
              ret.push_back(s.substr(i, 10));

      return ret;
  }
};

int main() {
    cout << "come up and c++ me some time";   //<<符号实际上是运算符的重载,它也有按位操作的意思,这里则是把字符串赋给输出流
    cout << endl;   //cout需要用endl来结束啊哥们

    Solution s;
    vector<string> vector = s.findRepeatedDnaSequences("123");
    for (int i = 0; i < vector.size(); ++i) {
        cout << vector[i] << "\n";
    }
    cout << "ready to finish" << endl;   //<<符号实际上是运算符的重载,它也有按位操作的意思,这里则是把字符串赋给输出流
    return 0;
}