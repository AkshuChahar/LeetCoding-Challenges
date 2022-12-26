class Solution:
    def canJump(self, nums: List[int]) -> bool:
        last, n = 0, len(nums)
        # Traverse the list.
        for i in range(n):
            # Check if the current step can be reached.
            if (last < i):
                break
            # Update 'last'.
            last = max(last, nums[i]+i)
        return last >= n - 1