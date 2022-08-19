class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        # Initialise 2 dictionaries to keep the number of elements used for subsequence and number of subsequences that end with an element.
        count = Counter(nums)
        sub = defaultdict(int)
        # Traverse through the array.
        for num in nums:
            # Check if all the occurances of the current element are used.
            if not count[num]:
                continue
            # Check if there is a subsequence ending with 'num - 1'.
            if sub[num - 1]:
                # Update the subsequence ending element.
                sub[num - 1] -= 1
                sub[num] += 1
            else:
                # Check if we have next 2 consecutive elements available.
                if not count[num + 1] or not count[num + 2]:
                    return False
                # Create a new subsequence ending with 'num + 2'.
                count[num + 1] -= 1
                count[num + 2] -= 1
                sub[num + 2] += 1
            count[num] -= 1
        return True