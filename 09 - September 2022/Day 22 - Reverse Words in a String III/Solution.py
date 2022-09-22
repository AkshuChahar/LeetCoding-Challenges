class Solution:
    def reverseWords(self, s: str) -> str:
        # Split the string around whitespaces.
        l = s.split(" ")
        # Reverse and join the strings.
        return " ".join([s[::-1] for s in l])