class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        ans = 0
        # Join the second list to get a string.
        str2 = "".join([chr(num) for num in nums2])
        str1 = ""
        # Traverse the first list.
        for num in nums1:
            # Append to the 'str1'.
            str1 += chr(num)
            # Check if the current string is present in 'str2'.
            if str1 in str2:
                ans = max(ans, len(str1))
            # Check by slicing the string.
            else:
                str1 = str1[1:]
        return ans