//
// Created by soapsnake@gmail.com on 2019-10-29.
//
#include "vector"
using namespace std;

class Node {
 public:
  int val;
  vector<Node> children;

  Node() {}

  Node(int _val, vector<Node> _children) {
      val = _val;
      children = _children;
  }
};

