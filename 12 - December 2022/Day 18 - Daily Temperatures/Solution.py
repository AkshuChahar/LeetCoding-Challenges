class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        ans = [0] * n
        # Initialise a stack.
        s = []
        # Traverse the list.
        for i, temp in enumerate(temperatures):
            # Check for warmer temperatures.
            while s and temperatures[s[-1]] < temp:
                curr = s.pop()
                ans[curr] = i - curr
            s.append(i)
        return ans