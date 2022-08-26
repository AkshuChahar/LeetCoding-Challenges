class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        # Get the frequency of each digit in the given number.
        freq = Counter(str(n))
        # Compare with all powers of 2.
        for i in range(30):
            # Check if the given number has same frequency of digits as any power of 2.
            if freq == Counter(str(1 << i)):
                return True
        return False