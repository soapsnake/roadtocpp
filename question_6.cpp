//
// Created by soapsnake@gmail.com on 3/29/21.
//

#include "vector"
#include "string"

class solution {

 public:
  std::string convert(std::string s, int numRows) {

    std::vector<std::string> res(numRows,"");
    int i = 0;
    int len = s.length();
    while (i < len) {
      for (int kI = 0; kI < numRows && kI < len; ++kI) {
        res[kI].push_back(s[i++]);
      }
      for (int kI = numRows - 2; kI >= 1 && i < len; --kI) {
        res[kI].push_back(s[i++]);
      }
    }
    std::string zig;
    for (const auto & re : res) {
      zig += re;
    }
    return zig;
  }

};