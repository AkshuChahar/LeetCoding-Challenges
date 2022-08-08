class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # Initialise an array with the first element as 'nums[0]'.
        arr = [nums.pop(0)]
        # Traverse through the array.
        for num in nums:
            # If the current element is greater than the last element of 'arr', append it to 'arr'.
            if (num > arr[-1]):
                arr.append(num)
            # Replace an element such that 'arr' remains increasing.
            else:
                arr[bisect_left(arr, num)] = num
        return len(arr)