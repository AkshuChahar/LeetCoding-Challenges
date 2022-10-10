class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        n = len(palindrome)
        # Edge case: Check if the length of string is 1.
        if n == 1:
            return ""
        # Iterate over the string and change the first non-'a' character to 'a'.
        for i in range(n//2):
            if palindrome[i] != 'a':
                return palindrome[:i] + 'a' + palindrome[i + 1:]
        return palindrome[:-1] + 'b'