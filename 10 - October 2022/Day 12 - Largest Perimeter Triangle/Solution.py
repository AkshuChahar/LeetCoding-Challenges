class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        n = len(nums)
        # Sort the lengths.
        nums.sort()
        # Check if the triangle is possible to be formed.
        for i in range(n - 1, 1, -1):
            if nums[i] < nums[i - 1] + nums[i - 2]:
                return nums[i] + nums[i - 1] + nums[i - 2]
        return 0