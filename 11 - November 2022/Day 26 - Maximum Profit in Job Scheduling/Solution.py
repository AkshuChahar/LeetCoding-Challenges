class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        # Initialise a list of tuples to get all the jobs sorted according to the start time.
        jobs, n = sorted(zip(startTime, endTime, profit)), len(startTime)
        # Initialise a dp list.
        dp = [0] * (n + 1)
        # Traverse the list.
        for i in reversed(range(n)):
            # Perform a 'Binary Search'.
            ind = bisect_left(jobs, jobs[i][1], key = lambda j: j[0])
            dp[i] = max(jobs[i][2] + dp[ind], dp[i+1])
        return dp[0]