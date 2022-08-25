class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        # Initialise two dictionaries and store the frequencies of each character in the string.
        rn, mz = Counter(ransomNote), Counter(magazine)
        # Traverse the dictionary 'rn'.
        for ch in rn:
            # Check if we have the required number of characters in 'magazine'.
            if rn[ch] > mz[ch]:
                return False
        return True