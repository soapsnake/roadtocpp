//
// Created by soapsnake@gmail.com on 27/9/20.
//
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;

class Solution {
 public:
  vector<double>
  calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
      unordered_map<string, Node *> map;
      vector<double> res;
      for (int i = 0; i < equations.size(); i++) {
          string s1 = equations[i][0], s2 = equations[i][1];

          //map.count(s1) 返回map中key等于s1的元素数量(只有0和1两个值吧)
          if (map.count(s1) == 0 && map.count(s2) == 0) {
              //如果map中不包含s1和s2的情况
              map[s1] = new Node();
              map[s2] = new Node();
              map[s1]->value = values[i];  //Node1.value
              map[s2]->value = 1;
              map[s1]->parent = map[s2];    //node1.parent = node2
          } else if (map.count(s1) == 0) {
              //不存在s1但是存在s2的情况
              map[s1] = new Node();
              map[s1]->value = map[s2]->value * values[i];
              map[s1]->parent = map[s2];
          } else if (map.count(s2) == 0) {
              //存在s1但是不存在s2的情况
              map[s2] = new Node();
              map[s2]->value = map[s1]->value / values[i];
              map[s2]->parent = map[s1];
          } else {
              //s1和s2均存在
              unionNodes(map[s1], map[s2], values[i], map);
          }
      }

      for (auto query : queries) {
          if (map.count(query[0]) == 0 || map.count(query[1]) == 0 ||
              findParent(map[query[0]]) != findParent(map[query[1]]))
              res.push_back(-1);
          else
              res.push_back(map[query[0]]->value / map[query[1]]->value);
      }
      return res;
  }

//cpp版本的union find算法
 private:
  struct Node {
    Node *parent;
    double value = 0.0;

    Node() { parent = this; }
  };

  void unionNodes(Node *node1, Node *node2, double num, unordered_map<string, Node *> &map) {
      Node *parent1 = findParent(node1), *parent2 = findParent(node2);
      double ratio = node2->value * num / node1->value;
      for (auto it = map.begin(); it != map.end(); it++)
          if (findParent(it->second) == parent1)
              it->second->value *= ratio;
      parent1->parent = parent2;
  }

  Node *findParent(Node *node) {
      if (node->parent == node)
          return node;
      node->parent = findParent(node->parent);
      return node->parent;
  }
};