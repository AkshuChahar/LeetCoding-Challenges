class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        # Initialise a list of dictionaries to store the possible combinations.
        dp = [defaultdict(int) for _ in nums]
        # Traverse the list.
        for i in range(1, n):
            for j in range(i):
                # Calculate the difference and update the 'dp'.
                diff = nums[j] - nums[i]
                dp[i][diff] += dp[j][diff] + 1
                ans += dp[j][diff]
        return ans