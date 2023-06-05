class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        # 算法主要确保 dp[0] = 0
        dp = [amount+1 for i in range(amount+1)]
        dp[0] = 0
        # print(dp)
        # dp = [amount] * amount
        for i in range(1, amount+1):
            for coin in coins:
                if i-coin < 0:  continue
                dp[i] = min(dp[i-coin]+1, dp[i])
        # print(dp)
        return dp[amount] if dp[amount] != amount+1 else -1
if __name__ == "__main__":
    coins = [2]
    num = Solution()
    print(num.coinChange(coins, 11))
