//
// Created by soapsnake@gmail.com on 7/10/20.
//
#include "vector"

using namespace std;

/**
 * 股票买卖问题所有变型
 */
class Solution {
 public:
  //限定一笔:任意一天买入,任意一天卖出(但是必须先买入再卖出),问:给定价格的数组的最大收益是多少?
  int maxProfit(vector<int> &prices) {
      if (prices.size() == 0) {
          return 0;
      }
      int sofarMin = prices[0];
      int maxProfit = 0;
      for (int i = 1; i < prices.size(); ++i) {
          if (prices[i] > sofarMin) {
              maxProfit = max(maxProfit, prices[i] - sofarMin);
          } else {
              sofarMin = prices[i];
          }
      }
      return maxProfit;
  }

  //不限定买入/卖出次数,也不带冷却时间(可以当天卖出当天买入): 问:最大收益
  int maxProfit2(vector<int> &prices) {
      //如果允许当天买入,当天卖出,那么解法就是这个:思路就是每天都买入,每天都卖出,然后取其中有收益的那些(买-卖>0)的全部加起来
      int ret = 0;
      for (auto i = 1; i < prices.size(); ++i)
          ret += max(prices[i] - prices[i - 1], 0);
      return ret;
  }

  //不限定买入/卖出次数,带冷却时间(不允许当天卖出当天买入): 问:最大收益
  int maxProfit3(vector<int> &prices) {

  }

  //难度加强版,你最多可以买入和卖出2比,但是下一次买入前必须先卖出
  //这个解法属实看的老子头皮发麻
  int maxProfit4(vector<int> &prices) {
      int buyOne = INT_MAX;
      int profitOne = 0;  //第一笔交易的最大收益

      int buyTwo = INT_MAX;
      int profitTwo = 0;  //第二笔交易的最大收益,题目求得就是这个
      for (int i = 0; i < prices.size(); ++i) {
          buyOne = min(buyOne, prices[i]);
          profitOne = max(prices[i] - buyOne, profitOne);

          buyTwo = min(buyTwo, prices[i] - profitOne);
          profitTwo = max(prices[i] - buyTwo, profitTwo);
      }
      return profitTwo;
  }

  //最大允许k笔交易,这个就太难了
  int maxProfit5(int k, vector<int> &prices) {

  }

};
