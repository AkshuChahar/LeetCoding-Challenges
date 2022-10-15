class Solution:
    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        @cache
        # Function for Memoization.
        def dp(i, prev, prev_cnt, k):
            # Check if K is less than 0.
            if k < 0: 
                return inf
            # Check if 'i' is equal to length of string.
            if i == len(s): 
                return 0
            # Check if we should keep the current character or delete it.
            delete = dp(i + 1, prev, prev_cnt, k - 1)
            if s[i] == prev:
                keep = dp(i + 1, prev, prev_cnt + 1, k)
                if prev_cnt in [1, 9, 99]:
                    keep += 1
            else:
                keep = dp(i + 1, s[i], 1, k) + 1
            return min(delete, keep)
        return dp(0, "", 0, k)