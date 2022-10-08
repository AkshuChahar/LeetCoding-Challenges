class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        ans, diff = 0, float(inf)
        # Sort the list.
        nums.sort()
        # Traverse the list.
        for i in range(len(nums) - 2):
            # Initialise 2 pointers for calculating the closest sum using the current threee numbers.
            j, k = i + 1, len(nums) - 1
            while j < k:
                curr_sum = nums[i] + nums[j] + nums[k]
                # Update 'ans'.
                if abs(curr_sum - target) < diff:
                    ans = curr_sum
                    diff = abs(curr_sum - target)
                # Update the pointers.
                if curr_sum < target:
                    j += 1
                elif curr_sum > target:
                    k -= 1
                else:
                    return ans
        return ans