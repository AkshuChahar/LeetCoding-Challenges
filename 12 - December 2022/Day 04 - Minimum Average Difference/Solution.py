class Solution:
    def minimumAverageDifference(self, nums: List[int]) -> int:
        n, ans, diff, pref_sum = len(nums), -1, math.inf, 0
        # Calculate total sum of list.
        total = sum(nums)
        # Traverse the list.
        for ind in range(n):
            pref_sum += nums[ind]
            # Calculate average of left and right part of list.
            left = pref_sum
            left //= (ind + 1)
            right = total - pref_sum
            # Check if 'right' part have 0 elements.
            if ind != n - 1:
                right //= (n - ind - 1)
            curr_diff = abs(left - right)
            # Update 'diff' and 'ans'.
            if curr_diff < diff:
                diff = curr_diff
                ans = ind                
        return ans