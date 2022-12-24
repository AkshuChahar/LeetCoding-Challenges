class Solution:
    def numTilings(self, n: int) -> int:
        # Initialise the 'dp' list.
        dp = [1, 2, 5] + [0] * n
        # Traverse for all blocks.
        for i in range(3, n):
            # Update 'dp'.
            dp[i] = (dp[i - 1] * 2 + dp[i - 3]) % 1000000007
        return dp[n - 1]