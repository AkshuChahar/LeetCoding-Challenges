class Solution:
    def firstUniqChar(self, s: str) -> int:
        # Initialise a dictionary and store the frequency of each character.
        d = collections.Counter(s)
        # Traverse the string and return the first character index with frequency 1.
        for index, ch in enumerate(s):
            if d[ch] == 1:
                return index
        return -1