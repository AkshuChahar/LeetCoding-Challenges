class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        # Edge case: Check if the number of days is greater than the number of jobs.
        if n < d:
            return -1
        @cache
        # Function for 'Memoization'.
        def memo(curr, days):
            # Check if we have any day left to accomodate the remaining jobs.
            if not days:
                if curr < 0:
                    return 0
                return math.inf
            # Check if we have any jobs left to fill the day.
            elif curr < 0:
                if not days:
                    return 0
                return math.inf
            # Check if the reamining jobs are less than number of days left.
            elif curr + 1 < days:
                return math.inf
            else:
                # Get the maximum job difficulty.
                max_job = -math.inf
                ans = math.inf
                for i in range(curr, -1, -1):
                    max_job = max(max_job, jobDifficulty[i])
                    ans = min(ans, max_job + memo(i - 1, days - 1))
                return ans
        return memo(n - 1, d)