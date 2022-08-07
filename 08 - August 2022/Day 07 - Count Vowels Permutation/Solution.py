class Solution:
    def countVowelPermutation(self, n: int) -> int:
        # Initialise the count of vowels to 1.
        a, e, i, o, u = 1, 1, 1, 1, 1
        # Iterate from 2 to 'n'.
        for _ in range(2, n + 1):
            # Add the counts.
            a, e, i, o, u = e + i + u, a + i, e + o, i, i + o
        return (a + e+ i + o + u) % 1000000007