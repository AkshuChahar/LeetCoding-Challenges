class Solution:
    def climbStairs(self, n: int) -> int:
        # Edge case: Check if the number is less than 1.
        if n < 1:
            return 1
        # Initialise the 'dp' list.
        dp = [1] * 2
        # Iterate for all stairs.
        for i in range(2, n+1):
            dp[1], dp[0] = dp[1] + dp[0], dp[1]
        return dp[1]