class Solution:
    def mirrorReflection(self, p: int, q: int) -> int:
        # Divide by 2 while both 'p' and 'q' are even.
        while (p % 2 == 0 and q % 2 == 0):
            p /= 2
            q /= 2
        # Check if 'p' is even.
        if p % 2 == 0:
            return 2
        # Check if 'q' is even.
        elif q % 2 == 0:
            return 0
        else:
            return 1