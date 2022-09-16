class Solution:
    def maximumScore(self, nums: List[int], multipliers: List[int]) -> int:
        m, n = len(multipliers), len(nums)
        # Initialise the 'dp' array.
        dp = [0] * (m + 1)
        for i in range(m - 1, -1, -1):
            # Copy the present 'dp' array to serve as the next row.
            row = dp.copy()
            # Iterate to fill the current row.
            for j in range(i, -1, -1):
                dp[j] = max(multipliers[i] * nums[j] + row[j + 1], multipliers[i] * nums[n - 1 - i + j] + row[j])
        return dp[0]