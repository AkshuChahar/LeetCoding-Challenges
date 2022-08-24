class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        # Check if the 'log(n)/log(3)' is an integer.
        return n > 0 and (log10(n) / log10(3)) % 1 == 0