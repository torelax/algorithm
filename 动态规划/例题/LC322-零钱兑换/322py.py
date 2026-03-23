class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        mem = dict()
        def dp(n):
            if n in mem: return mem[n]
            if n == 0: return 0
            if n < 0 : return -1
            res = float('INF')
            for coin in coins:
                ses = dp(n-coin)
                if ses == -1: continue
                res = min(res, ses+1)
            mem[n] = res if res != float('INF') else -1
            return mem[n]
        return dp(amount)
if __name__ == "__main__":
    coins = [1, 2, 5]
    num = Solution()
    print(num.coinChange(coins, 11))
