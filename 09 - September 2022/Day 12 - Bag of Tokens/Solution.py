class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        ans, res, n = 0, 0, len(tokens)
        # Sort the 'tokens'.
        tokens.sort()
        # Initialise two pointers for traversal.
        left, right = 0, n - 1
        # Traverse the array.
        while (left <= right) and (power >= tokens[left] or res):
            # Check if we can play the token 'face-up'.
            while (left <= right) and (power >= tokens[left]):
                power -= tokens[left]
                left += 1
                res += 1
            # Update 'ans'.
            ans = max(ans, res)
            # Check if we can play the token 'face-down'.
            if (left <= right) and res:
                power += tokens[right]
                right -= 1
                res -= 1
        return ans