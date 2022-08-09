class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        MOD, n = 10 ** 9 + 7, len(arr)
        # Sort the array.
        arr.sort()
        # Initialise a 'dp' array.
        dp = [1] * n
        # Build a dictionary to get the index of a number quickly.
        index = {x : i for i, x in enumerate(arr)}
        # Traverse the array.
        for i, x in enumerate(arr):
            for j in range(i):
                # Check if the given number can be a divisor of 'arr[i]'.
                if x % arr[j] == 0:
                    k = x / arr[j]
                    # Get the index of the 'k'.
                    if k in index:
                        dp[i] += dp[j] * dp[index[k]]
                        dp[i] %= MOD
        return sum(dp) % MOD