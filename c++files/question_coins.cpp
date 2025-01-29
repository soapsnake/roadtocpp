//
// Created by soapsnake@gmail.com on 27/3/21.
//

#include "vector"

class solutions {

 public:
  int minCoinsAmount(std::vector<int> &coins, int total) {
      std::vector<int> dp((total + 1), total);

      dp[0] = 0;
      for (int i = 0; i < dp.size(); ++i) {
          for (int coinAmount: coins) {
              if (dp[i] - coinAmount < 0) {
                  continue;
              }
              dp[i] = std::min(dp[i], 1 + dp[i - coinAmount]);
          }
      }
      return dp[total] == total ? -1 : dp[total];
  }
};