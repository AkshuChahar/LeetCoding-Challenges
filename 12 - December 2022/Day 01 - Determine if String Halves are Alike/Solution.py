class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        sum_a = sum_b = 0
        # Initialise a set of vowels.
        vowels = set('aeiouAEIOU')
        # Traverse the word.
        for i in range(len(s)//2):
            # Check for first half.
            if s[i] in vowels:
                sum_a += 1
            # Check for second half.
            if s[len(s)//2 + i] in vowels:
                sum_b += 1
        return sum_a == sum_b