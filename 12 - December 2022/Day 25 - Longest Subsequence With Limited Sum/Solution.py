class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        ans, n = [], len(nums)
        # Calculate the prefix sum list of the sorted 'nums'.
        nums.sort()
        for i in range(1, n):
            nums[i] += nums[i - 1]
        # Traverse the list.
        for query in queries:
            # Find the insertion index of the prefix sum list.
            ind = bisect.bisect_right(nums, query)
            ans.append(ind)
        return ans