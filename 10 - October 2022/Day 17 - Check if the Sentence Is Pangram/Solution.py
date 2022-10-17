class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        # Add all the letters to a 'set' and check if the length of set is '26'.
        s = set(sentence)
        return len(s) == 26