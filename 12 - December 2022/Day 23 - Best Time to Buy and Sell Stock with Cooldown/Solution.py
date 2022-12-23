class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        # Edge case: Check if there is only 1 day available.
        if (n == 1):
            return 0
        # Initialise lists to keep track of buying and selling prices.
        buy, sell = [0] * n, [0] * n
        buy[0] = -prices[0]
        buy[1] = max(-prices[0], -prices[1])
        sell[1] = max(0, buy[0] + prices[1])
        # Traverse the list.
        for i in range(2, n):
            buy[i] = max(buy[i - 1], sell[i - 2] - prices[i])
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i])
        return sell[n-1]