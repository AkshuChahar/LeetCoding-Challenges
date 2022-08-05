class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        # Initialise a 'dp' dictionary to keep track of various combination sums possible.
        dp = {}
        dp[0] = [1]
        # Funtion to recursively search if the 'target - sum' combination exists.
        def helper(target):
            # Check if the current combination sum already exists in the dictionary.
            if target in dp:
                return dp[target]
            summ = 0
            # Traverse the array and check for each combination.
            for num in nums:
                if target > num:
                    summ += helper(target - num)
                elif target == num:
                    summ += 1
            # Update the dictionary.
            dp[target] = summ
            return summ
        return helper(target)