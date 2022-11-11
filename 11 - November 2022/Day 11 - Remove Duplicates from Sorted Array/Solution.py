class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n, ind = len(nums), 1
        # Traverse the list.
        for i in range(1, n):
            # Find the unique element.
            if nums[i - 1] != nums[i]:      
                nums[ind] = nums[i] 
                # Update 'ind'.
                ind += 1       
        return ind