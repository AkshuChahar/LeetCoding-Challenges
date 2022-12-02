class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        # Count the frequency and number of unique characters.
        return Counter(Counter(word1).values()) == Counter(Counter(word2).values()) and set(word1) == set(word2)