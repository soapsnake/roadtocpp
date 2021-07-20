//
// Created by soapsnake@gmail.com on 4/21/21.
//

#ifndef ROADTOCPP_HEARDERS_NODE_H_
#define ROADTOCPP_HEARDERS_NODE_H_

#endif //ROADTOCPP_HEARDERS_NODE_H_
#include <vector>

class Node {
 public:
  int val;
  std::vector<Node*> children;

  Node() {}

  Node(int _val) {
      val = _val;
  }

  Node(int _val, std::vector<Node*> _children) {
      val = _val;
      children = _children;
  }
};