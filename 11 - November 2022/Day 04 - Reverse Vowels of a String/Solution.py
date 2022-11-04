class Solution:
    def reverseVowels(self, st: str) -> str:
        s = [c for c in st]
        n = len(s)
        # Initialise two pointers.
        left, right = 0, n - 1
        # Traverse the string.
        while left < right:
            # Move to the next vowels.
            while left <= right and s[left] not in "aeiouAEIOU":
                left += 1
            while right >= left and s[right] not in "aeiouAEIOU":
                right -= 1
            # Swap the vowels.
            if left < right:
                temp = s[left]
                s[left] = s[right]
                s[right] = temp
            left += 1
            right -= 1
        return "".join(s)