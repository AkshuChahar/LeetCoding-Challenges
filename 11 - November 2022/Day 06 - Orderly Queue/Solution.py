class Solution:
    def orderlyQueue(self, s: str, k: int) -> str:
        # Check whether 'k' is 1.
        if k == 1:
            # Check for each possible combination of string.
            return min(s[i:] + s[:i] for i in range(len(s)))
        else:
            return "".join(sorted(s))