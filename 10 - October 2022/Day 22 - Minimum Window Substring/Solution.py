class Solution:
    def minWindow(self, s: str, t: str) -> str:
        # Store the frequencies of each character in 't'.
        d_t = Counter(t)
        req = len(d_t)
        # Filter the string 's' to get only the required characters.
        new_s = [(i, c) for i,c in enumerate(s) if c in d_t]
        # Initialise variables for 'Sliding Window'.
        left, right, res = 0, 0, 0
        window = {}
        ans = (float('inf'), None, None)
        # Traverse the string.
        while right < len(new_s):
            ch = new_s[right][1]
            # Update the character count.
            window[ch] = window.get(ch, 0) + 1
            # Check if we have desired number of 'ch' characters.
            if window[ch] == d_t[ch]:
                res += 1            
            # Check if the current sliding window has all the characters.
            while left <= right and res == req:
                ele = new_s[left][1]
                # Update 'ans'.
                end = new_s[right][0]
                start = new_s[left][0]
                if end - start + 1 < ans[0]:
                    ans = (end - start + 1, start, end)
                # Try decreasing sliding window size.
                window[ele] -= 1
                if window[ele] < d_t[ele]:
                    res -= 1
                left += 1
            right += 1
        return "" if ans[0] == float(inf) else s[ans[1] : ans[2] + 1]