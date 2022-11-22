from math import isqrt
class Solution:
    def numSquares(self, n: int) -> int:
        # Check if the number itself is a perfect square.
        if isqrt(n) ** 2 == n:
            return 1
        # Check if 2 perfect squares can sum to given number.
        for i in range(1, isqrt(n) + 1):
            j = n - i ** 2
            if j == isqrt(j) ** 2:
                return 2
        # Check if 3 perfect squares can sum to given number.
        while n % 4 == 0: 
            n /= 4
        if n % 8 != 7:
            return 3
        return 4