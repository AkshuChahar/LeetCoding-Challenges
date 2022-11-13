class Solution:
    def reverseWords(self, s: str) -> str:
        # Split the sentence and reverse the sequence.
        return " ".join(s.split()[::-1])