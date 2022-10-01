class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        # Edge case: Leading Zeros.
        if s[0] == '0':
            return 0
        # Edge case: If the length of string is 1.
        if n == 1:
            return 1
        # Initialise a dp list to store the number of possible ways to decode untill the previous position.
        dp = [0] * n
        dp[0] = 1
        dp[1] = 1 if (s[0] < '2' or (s[1] <= '6' and s[0] <= '2')) else 0
        # Traverse the string.
        for i in range(1, n):
            # Check for all possible combinations.
            if (i > 1 and (s[i-1] == '1' or (s[i-1] == '2' and s[i] <= '6'))):
                dp[i] += dp[i - 2]
            if (s[i] != '0'):
                dp[i] += dp[i - 1]
        return dp[n - 1]