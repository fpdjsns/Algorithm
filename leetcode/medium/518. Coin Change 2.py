# problem : https://leetcode.com/problems/coin-change-2/
# time complexity : O(NM)
# algorithm : DP
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        if amount == 0 and len(coins) == 0:
            return 1
        dp = [[0] * (amount + 1)] * (len(coins) + 1)

        for coinInd in range(len(coins)):
            coin = coins[coinInd]
            prev = dp[coinInd]
            now = dp[coinInd + 1]
            now[0] = 1
            for ind in range(coin, amount + 1):
                now[ind] = now[ind-coin] + prev[ind]

        return dp[len(coins)][amount]
