class Solution:
    def romanToInt(self, s: str) -> int:
        n, ans, i = len(s), 0, 0
        # Initialise a dictionary with all the symbols and their values.
        dict = {'I' : 1, 'V' : 5, 'X' : 10, 'L' : 50, 'C' : 100, 'D' : 500, 'M' : 1000}
        # Traverse the string.
        while i < n:
            # Check if the current roman symbol is smaller than the next one.
            if i < n - 1 and dict[s[i]] < dict[s[i + 1]]:
                ans += dict[s[i + 1]] - dict[s[i]]
                i += 2;
            else:
                ans += dict[s[i]]
                i += 1
        return ans