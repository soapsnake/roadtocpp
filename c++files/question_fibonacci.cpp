//
// Created by soapsnake@gmail.com on 4/16/21.
//

class Solution {
 public:
  int fib(int n) {
      int first = 0;
      int second = 1;
      if (n == 1) {
          return 0;
      }

      while (n-- > 1) {
          int third = first + second;
          first = second;
          second = third;
      }
      return second;
  }
};