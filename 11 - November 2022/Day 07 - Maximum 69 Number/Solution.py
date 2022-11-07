class Solution:
    def maximum69Number (self, num: int) -> int:
        # Convert the number to a string and change the first '6' to '9'.
        s = str(num)
        return int(s.replace('6', '9', 1))