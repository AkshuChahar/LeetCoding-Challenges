class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        # Initialise an array to keep track of numbers with the given digits difference at current level.
        arr = [num for num in range(1, 10)]
        # Loop for all the levels.
        for level in range(n - 1):
            # Initialise a temporary array to store the next level.
            temp = []
            # Check for each number in the current array if they can have a new digit added.
            for num in arr:
                end = num % 10
                # Store the possible digits for the new number.
                new = set([end - k, end + k])
                # Check if the new digits are valid.
                for n in new:
                    if 0 <= n < 10:
                        new_num = num * 10 + n
                        temp.append(new_num)
            arr = temp
        return arr