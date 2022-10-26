class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        s = 0
        # Initialise a dictionary to keep track of the remainders.
        d = {0: 0}
        # Traverse the array while updating the sum.
        for i in range(len(nums)):
            s += nums[i]
            # Check if the remainder of current sum has occured.
            if s % k not in d:
                d[s % k] = i + 1
            # Check if the size of subarray is greater than 2.
            elif d[s % k] < i:
                return True
        return False