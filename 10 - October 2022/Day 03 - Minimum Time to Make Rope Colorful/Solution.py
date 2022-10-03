class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        n, ans = len(colors), 0
        # Initialise variable to store the maximum time in a group.
        time = neededTime[0]
        # Traverse the 'colors'.
        for i in range(1, n):
            # Check if the color of the current balloon is different from the previous one.
            if colors[i] != colors[i - 1]:
                time = 0
            # Update 'ans' and 'time'.
            ans += min(time, neededTime[i])
            time = max(time, neededTime[i])
        return ans