class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        n = len(prices)
        # Initialise arrays to store the minimum prices and maximum profits.
        buy, profit = [float(inf)] * (k + 1), [0] * (k + 1)
        # Traverse the array.
        for price in prices:
            # Update the arrays.
            for i in range(1, k + 1):
                buy[i] = min(buy[i], price - profit[i - 1])
                profit[i] = max(profit[i], price - buy[i])
        return profit[k]