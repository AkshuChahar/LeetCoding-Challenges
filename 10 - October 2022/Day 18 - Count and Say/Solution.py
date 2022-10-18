class Solution:
    def countAndSay(self, n: int) -> str:
        # Edge case: Check if 'n' is equal to 1.
        if n == 1:
            return '1'
        ans = ""
        # Perform a Recursion.
        result = self.countAndSay(n - 1)
        result += '#'
        count = 1
        # Traverse 'result'.
        for i in range(len(result) - 1):
            # Get the count of same digits and update 'ans'.
            if result[i] == result[i + 1]:
                count += 1
            else:
                ans += str(count) + result[i]
                count = 1
        return ans