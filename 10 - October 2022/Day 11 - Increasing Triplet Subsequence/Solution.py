class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        n, i = len(nums), 0
        # Edge case: Check if the length of the list is less than 3.
        if n < 3:
            return False
        # Initialise variables to keep track of lowest and highest values.
        low = high = float(inf)
        # Traverse the list.
        while i < n:
            # Check if current element is greater than 'high'.
            if nums[i] > high:
                return True
            # Update 'low' and 'high'.
            elif nums[i] < low:
                low = nums[i]
            elif nums[i] > low and nums[i] < high:
                high = nums[i]
            i += 1
        return False