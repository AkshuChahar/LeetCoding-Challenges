class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        # Get the 'desired' and 'actual' sum.
        desired = (len(nums) * (len(nums) + 1)) // 2
        actual = sum(nums)
        # Get the sum of unique elements.
        s = sum(set(nums))
        return [actual - s, desired - s]