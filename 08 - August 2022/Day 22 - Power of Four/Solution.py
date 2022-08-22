class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        # Check if the log of the given number is an integer.
        return n > 0 and log(n, 4).is_integer()