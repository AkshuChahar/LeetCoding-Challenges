class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        # Initialise a dictionary to store the visited elements.
        d = {}
        # Traverse the list.
        for i, num in enumerate(nums):
            # Check if the two elements are equal and the distance between them is <= 'k'.
            if num in d and i - d[num] <= k:
                return True
            d[num] = i
        return False