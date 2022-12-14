class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        # Edge case: Check if there is only 1 house.
        if (n == 1):
            return nums[0]
        # Initialise a 'dp' list.
        dp = [0]
        dp.append(nums[0])
        # Traverse the list.
        for i in range(2, n + 1):
            dp.append(max(dp[i - 1], nums[i - 1] + dp[i - 2]))
        return dp[n]